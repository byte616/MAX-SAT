#include<fstream>
#include<iostream>
#include <vector>
#include<algorithm>
#include <omp.h>
#include <immintrin.h>
using namespace std;

const int N = 10;
const int R = 1000;
const int numthread = 6;

int n, m, k;

void open_file(ifstream &finput,ofstream &foutput,int t_case){
	string dir_path = "./data/";

	string input_file_name = to_string(t_case)+".in";
	string output_file_name = "serial"+to_string(t_case)+".ans";

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
	int satisfy = 0, idx = 0;
	vector<int> vs(vc.size());
	
	for(int i = 0; i < vc.size(); i++) {
		for(int j = 0; j < vc[i].size(); j++) {
			if(vc[i][j] > 0 && vx[vc[i][j]] == 1) {
				vs[i] = 1;
				break;
			}
			if(vc[i][j] < 0 && vx[-vc[i][j]] == 0) {
				vs[i] = 1;
				break;
			}
		}
	}

	// SIMD ADD
	__m256i vec_sum = _mm256_setzero_si256();
	for (int i = 0; i < vs.size(); i += 8) {
        __m256i vec = _mm256_loadu_si256((__m256i*)&vs[i]);
        vec_sum = _mm256_add_epi32(vec_sum, vec);
    }
	int result[8];
	_mm256_storeu_si256((__m256i*)result, vec_sum);
	for(int i = 0; i < 8; i++) {
		satisfy += result[i];
	}

	// remaining work
	for(int i = (vs.size() / 8) * 8; i < vs.size(); i++) {
		satisfy += vs[i];
	}

	return satisfy;
}

void random_max_sat(vector<vector<int>> &vc, ofstream &foutput, int t_case) {

	vector<int> BX;
	int B = 0;

	#pragma omp parallel num_threads(numthread)
	{
		// set local variable
		int LB = 0;
		vector<int> LBX;
		unsigned seed = time(0);

		// parallelize
		#pragma omp for schedule(static)
		for(int i = 0; i < R; i++) {
			// random set x_j - 0 or 1
			vector<int> vx(n + 1);
			for(int j = 1; j <= n; j++){
				vx[j] = rand_r(&seed) % 2;
			}
			// update best answer
			int score = evaluate(vc, vx);
			if(score > B) {
				LB = score;
				LBX = vx;
			}

		}

		// merge answer --> synchronization
		#pragma omp critical
		{
			if(LB > B) {
				B = LB;
				BX = LBX;
			}
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
