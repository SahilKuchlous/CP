#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
ifstream fin("cowdate.in");
ofstream fout("cowdate.out");
int main () {
	int n;
	fin >> n;
	double prob[n];
	for (int i=0; i<n; i++) {
		fin >> prob[i];
		prob[i] /= 1000000;
	}
	double best = 0;
	int cur_i = 0;
	double cur_sum = 0;
	double cur_prod = 1;
	for (int i=0; i<n; i++) {
		while (cur_i < n && cur_sum < 1) {
			cur_prod *= 1-prob[cur_i];
			cur_sum += prob[cur_i]/(1-prob[cur_i]);
			cur_i++;
		}
		best = max(best, cur_prod*cur_sum);
		cur_prod /= 1-prob[i];
		cur_sum -= prob[i]/(1-prob[i]);
	}
	fout << (int)floor(best*1000000) << endl;
}