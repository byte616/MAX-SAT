#include<fstream>
#include<iostream>
#include <vector>
#include<algorithm>
#include <pthread.h>
using namespace std;

const int N = 10;
const int R = 1000;
const int numthread = 6;

int n, m, k;

struct Threaddata {
	vector<vector<int>> *vc; // pointer for save space
	int start, end;
	int LB;
	vector<int> LBX;
};


void open_file(ifstream &finput,ofstream &foutput,int t_case){
	string dir_path = "./data/";

	string input_file_name = to_string(t_case)+".in";
	string output_file_name = "pthread"+to_string(t_case)+".ans";

	string input_path = dir_path + input_file_name;
	string output_path = dir_path + output_file_name;

	finput.open(input_path , ios::in);
	foutput.open(output_path , ios::out | ios::trunc);

	if(!finput){
		cerr << "cannot open input file " << input_path << endl;
		exit(1);
	}
	if(!foutput){
		cerr << "cannot open output file " << output_path << endl;
		exit(1);
	}
}

int evaluate(vector<vector<int>> &vc, vector<int> vx) {
	int satisfy = 0;

	for(auto clause : vc) {
		bool flag = 0;
		for(int j = 0; j < clause.size(); j++) {
			if(clause[j] > 0 && vx[clause[j]] == 1) {
				flag = 1;
				break;
			}
			if(clause[j] < 0 && vx[-clause[j]] == 0) {
				flag = 1;
				break;
			}
		}
		satisfy += flag;
	}

	return satisfy;
}

void *random_max_sat_thread(void *arg) {
	Threaddata *data = (Threaddata*) arg;
	// LBX, LB maintain local best solution
	vector<int> LBX;
	int LB = 0;

	// thread work
	for(int i = data->start; i < data->end; i++) {
		vector<int> vx(n + 1);
		for(int j = 1; j <= n; j++) {
			vx[j] = rand() % 2;
		}
		int score = evaluate(*(data->vc), vx);
		if(score > LB) {
			LB = score;
			LBX = vx;
		}
	}

	// save answer
	data->LB = LB;
	data->LBX = LBX;
	pthread_exit(NULL);
}

void random_max_sat(vector<vector<int>> &vc, ofstream &foutput, int t_case) {

	// initialize each testcase
	pthread_t threads[numthread];
	Threaddata thread_data[numthread];
	int work_size = R / numthread;

	// pthread create
	for(int i = 0; i < numthread; i++) {
		thread_data[i].vc = &vc;
		thread_data[i].start = i * work_size;
		thread_data[i].end = (i + 1) * work_size;
		if(i == numthread - 1) {
			thread_data[i].end = R;
		}
		pthread_create(&threads[i], NULL, random_max_sat_thread, (void*) &thread_data[i]);
	}
	
	// pthread join
	vector<int> BX;
	int B = 0;
	for(int i = 0; i < numthread; i++) {
		pthread_join(threads[i], NULL);
		if(thread_data[i].LB > B) {
			B = thread_data[i].LB;
			BX = thread_data[i].LBX;
		}
	}

	// ouput best answer
	foutput << "best clauses: " << B << endl;
	foutput << "best combination" << endl;
	for(auto x : BX) {
		foutput << x << " ";
	}

	cout << "testcase " << t_case << " success" << '\n';
	cout << "best clauses " << B << '\n';
}
void solve(ifstream &finput,ofstream &foutput, int t_case){

	// serial random MAX-SAT
	srand(time(0));
	finput >> n >> m;
	vector<vector<int>> vc(m);

	for(int i = 0; i < m; i++){
		finput >> k;
		vc[i].resize(k);
		for(int j = 0; j < k; j++) {
			finput >> vc[i][j];
		}
	}

	// run algorithm
	random_max_sat(vc, foutput, t_case);
}
void close_file(ifstream &finput,ofstream &foutput,int t_case){
	finput.close();
	foutput.close();
}
int main(){
	for(int i = 1;i <= N; i++){
		ifstream finput;
		ofstream foutput;
		open_file(finput,foutput,i);
		solve(finput,foutput,i);
		close_file(finput,foutput,i);
	}
}
