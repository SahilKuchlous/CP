#include <iostream>
using namespace std;
int main () {
	int n, t, p;
	cin >> n >> t >> p;
	p--;
	bool solved[n][t];
	int val[t];
	for (int i=0; i<t; i++) {
		val[i] = 0;
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<t; j++) {
			cin >> solved[i][j];
			if (!solved[i][j]) val[j]++;
		}
	}
	int score[n], cnt[n];
	for (int i=0; i<n; i++) {
		score[i] = cnt[i] = 0;
		for (int j=0; j<t; j++) {
			if (solved[i][j]) {
				score[i] += val[j];
				cnt[i]++;
			}
		}
	}
	int rank = 1;
	for (int i=0; i<n; i++) {
		if (i == p) continue;
		if (score[i] > score[p]) rank++;
		if (score[i] == score[p] && cnt[i] > cnt[p]) rank++;
		if (score[i] == score[p] && cnt[i] == cnt[p] && i<p) rank++;
	}
	cout << score[p] << " " << rank << endl;
}