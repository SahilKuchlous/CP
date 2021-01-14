#include <iostream>
using namespace std;
struct country {
	int id;
	int x, y, s;
};
double dist (country &c1, country &c2) {
	return (double) (c1.x-c2.x)*(c1.x-c2.x) + (c1.y-c2.y)*(c1.y-c2.y);
}
int n;
country a[1010];
int par[1010];
bool king[1010];
int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		a[i].id = i;
		cin >> a[i].x >> a[i].y >> a[i].s;
	}
	for (int i=0; i<n; i++) {
		double max_inf = 0;
		int max_i;
		int cnt = 0;
		for (int j=0; j<n; j++) {
			if (i == j) continue;
			double inf = a[j].s/dist(a[i], a[j]);
			if (inf > max_inf) {
				max_inf = inf;
				max_i = j;
				cnt = 1;
			} else if (inf == max_inf) {
				cnt++;
			}
		}
		if (max_inf <= a[i].s) {
			par[i] = i;
			king[i] = true;
		} else if (cnt == 1) {
			par[i] = max_i;
		} else {
			par[i] = i;
			king[i] = false;
		}
	}
	for (int i=0; i<n; i++) {
		if (par[i] == i) {
			cout << (king[i] ? 'K':'D') << endl;
		} else {
			int o = par[i];
			while (par[o] != o) {
				o = par[o];
			}
			cout << o+1 << endl;
		}
	}
}