#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("optmilk.in");
ofstream fout("optmilk.out");
int n, d;
int a[40100];
struct Node {
	long long best;
	long long exc_l;
	long long exc_r;
	long long exc_ends;
};
struct Node segtree[200100];
void merge (int x) {
	segtree[x].best = max(segtree[2*x+1].exc_r+segtree[2*x+2].best, segtree[2*x+1].best+segtree[2*x+2].exc_l);
	segtree[x].exc_l = max(segtree[2*x+1].exc_l+segtree[2*x+2].exc_l, segtree[2*x+1].exc_ends+segtree[2*x+2].best);
	segtree[x].exc_r = max(segtree[2*x+1].exc_r+segtree[2*x+2].exc_r, segtree[2*x+1].best+segtree[2*x+2].exc_ends);
	segtree[x].exc_ends = max(segtree[2*x+1].exc_ends+segtree[2*x+2].exc_r, segtree[2*x+1].exc_l+segtree[2*x+2].exc_ends);
}
void create (int x, int l, int r) {
	if (l == r) {
		segtree[x].best = a[l];
		segtree[x].exc_l = segtree[x].exc_r = segtree[x].exc_ends = 0;
		return;
	}
	int m = (l+r)/2;
	create(2*x+1, l, m);
	create(2*x+2, m+1, r);
	merge(x);
}
void update (int x, int l, int r, int a, int v) {
	if (a < l || a > r) {
		return;
	}
	if (l == r) {
		segtree[x].best = v;
		return;
	}
	int m = (l+r)/2;
	update(2*x+1, l, m, a, v);
	update(2*x+2, m+1, r, a, v);
	merge(x);
}
int main () {
	fin >> n >> d;
	for (int i=0; i<n; i++) {
		fin >> a[i];
	}
	create(0, 0, n-1);
	long long o = 0;
	int ai, bi;
	for (int i=0; i<d; i++) {
		fin >> ai >> bi;
		ai--;
		update(0, 0, n-1, ai, bi);
		o += segtree[0].best;
	}
	fout << o << endl;
}