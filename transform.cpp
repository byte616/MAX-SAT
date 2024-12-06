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

vector<int> vc[100005];

void open_file(ifstream &finput,ofstream &foutput,int t_case){
	string dir_path1 = "./data/";
	string dir_path2 = "./SOTA/";

	string input_file_name = to_string(t_case)+".in";
	string output_file_name = to_string(t_case)+".in";

	string input_path = dir_path1 + input_file_name;
	string output_path = dir_path2 + output_file_name;

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

void solve(ifstream &finput,ofstream &foutput, int t_case){

	// serial random MAX-SAT
	finput >> n >> m;

	for(int i = 0; i < m; i++){
		finput >> k;
		vc[i].resize(k);
		for(int j = 0; j < k; j++) {
			finput >> vc[i][j];
		}
	}

	foutput << n << " " << m << endl;

	for(int i = 0; i < m; i++) {
		for(auto j : vc[i]) {
			foutput << j << " ";
		}
		foutput << endl;
	}

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
