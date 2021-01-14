#include <fstream>
#include <iostream>
#include <map>
using namespace std;
ifstream fin("moobuzz.in");
ofstream fout("moobuzz.out");
int main () {
	int n;
	fin >> n;
	long long o = (n/8)*15;
	int x = n%8;
	map<int, int> m = {{0, -1}, {1, 1}, {2, 2}, {3, 4}, {4, 7}, {5, 8}, {6, 11}, {7, 13}};
	o += m[x];
	fout << o << endl;
}