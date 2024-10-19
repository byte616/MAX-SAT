#include<fstream>
#include<iostream>
#include <algorithm>
#include<random>
#include <vector>
#include<ctime>
using namespace std;

const int N = 10; 
int n, m, k;

void open_input(ofstream &fout,int t_case){
    string dir_path = "./data/";  
    string file_name = to_string(t_case)+".in"; 
    string real_path = dir_path + file_name; 
    fout.open(real_path , ios::out | ios::trunc); 
    if(!fout){
        cerr << "cannot open file " << real_path << endl;
        exit(1);
    }
}
void make_input(ofstream &fout, int t_case){
    random_device rd;
    uniform_int_distribution<int> unif(0,2147483647);
    mt19937 gen(rd()); 

    // vx --> shuffle x1 ~ xn
    vector<int> vx, vk;
    vector<int> C[m];
    // generate k1 ~ km
    int sum = 0;
    for(int i = 0; i < m; i++) {
        vk.push_back(unif(gen) % k + 1);
        sum += vk[i];
    }
    // generate the order of X_i
    for(int i = 1; i <= n; i++) {
        vx.push_back(i);
    }
    shuffle(vx.begin(), vx.end(), gen);

    // fill C1 ~ Cm
    int idx = 0;
    for(int i = 0; i < m; i++) {
        int cnt = vk[i];
        while(cnt--) {
            if(idx == vx.size()) {
                idx = 0;
                shuffle(vx.begin(), vx.end(), gen);
            }
            int sign = unif(gen) % 2;
            if(sign){
                C[i].push_back(-vx[idx]);
                idx += 1;
            }
            else {
                C[i].push_back(vx[idx]);
                idx += 1;
            }
        }
    }

    // output
    // test case
    // n, m
    // k1 C1
    // ...
    // km Cm
    fout << n << " " << m << endl;
    for(int i = 0; i < m; i++) {
        fout << vk[i] << " ";
        for(int j = 0; j < vk[i]; j++) {
            fout << C[i][j] << " ";
        }
        fout << endl;
    }
    cout << "use X: " <<sum << '\n';
    cout << "test_case " << t_case << " success" << '\n';
}
void close_input(ofstream &fout,int t_case){
    fout.close();
}
int main(){
    cout << "Input n, m, k:";
        cin >> n >> m >> k;
    for(int i = 1;i <= N; i++){
        ofstream fout;
        open_input(fout,i); 
        make_input(fout,i); 
        close_input(fout,i); 
    }
}

