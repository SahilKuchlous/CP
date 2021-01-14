#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("mincross.in");
ofstream fout("mincross.out");
int n;
int bit[100100];
int seq_l[100100], pos_l[100100];
int seq_r[100100], pos_r[100100];
void update (int x) {
	x++;
	while (x <= n) {
		bit[x]++;
		x += x & -x;
	}
}
int query (int x) {
	x++;
	int o = 0;
	while (x > 0) {
		o += bit[x];
		x -= x & -x;
	}
	return o;
}
int main () {
	fin >> n;
	for (int i=0; i<n; i++) {
		fin >> seq_l[i];
		seq_l[i]--;
		pos_l[seq_l[i]] = i;
	}
	for (int i=0; i<n; i++) {
		fin >> seq_r[i];
		seq_r[i]--;
		pos_r[seq_r[i]] = i;
	}
	long long total = 0;
	for (int i=n-1; i>=0; i--) {
		total += query(pos_r[seq_l[i]]);
		update(pos_r[seq_l[i]]);
	}
	long long o = total;
	for (int i=n-1; i>=0; i--) {
		total -= n-pos_l[seq_r[i]]-1;
		total += pos_l[seq_r[i]];
		o = min(o, total);
	}
	fout << o << endl;
}