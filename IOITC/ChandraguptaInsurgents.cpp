#include <iostream>
using namespace std;
int n, m, q;
int cnt[100100];
int main () {
	cin >> n >> m >> q;
	int ai, bi;
	for (int i=0; i<m; i++) {
		cin >> ai >> bi;
		ai--; bi--;
		for (int j=ai; j<bi; j++) {
			cnt[j]++;
		}
	}
	int ti;
	for (int i=0; i<q; i++) {
		cin >> ti >> ai >> bi;
		ai--; bi--;
		if (ai > bi) swap(ai, bi);
		if (ti == 0) {
			for (int j=ai; j<bi; j++) {
				cnt[j]++;
			}
		} else if (ti == 1) {
			for (int j=ai; j<bi; j++) {
				cnt[j]--;
			}
		} else if (ti == 2) {
			int o = 0;
			for (int j=ai; j<bi; j++) {
				if (cnt[j] == 0) o++;
			}
			cout << o << endl;
		}
	}
}