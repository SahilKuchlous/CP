#include <iostream>
#include <queue>
using namespace std;
int main () {
	int n, m;
	cin >> n >> m;
	int rate[n];
	for (int i=0; i<n; i++) {
		cin >> rate[i];
	}
	int wts[m];
	for (int i=0; i<m; i++) {
		cin >> wts[i];
	}
	bool free[n];
	for (int i=0; i<n; i++) {
		free[i] = true;
	}
	int pos[m];
	queue<int> cur;
	int ci;
	long long o = 0;
	for (int i=0; i<2*m; i++) {
		cin >> ci;
		if (ci < 0) {
			ci = -ci-1;
			if (cur.size() > 0) {
				pos[cur.front()] = pos[ci];
				o += rate[pos[cur.front()]]*wts[cur.front()];
				cur.pop();
			} else {
				free[pos[ci]] = true;
			}
		} else {
			ci--;
			pos[ci] = -1;
			for (int j=0; j<n; j++) {
				if (free[j]) {
					pos[ci] = j;
					free[j] = false;
					o += rate[j]*wts[ci];
					break;
				}
			}
			if (pos[ci] == -1) {
				cur.push(ci);
			}
		}
	}
	cout << o << endl;
}