#include <iostream>
using namespace std;
int n;
pair<int, int> plates[201];
int memo[601][601];
void rec (int w, int h) {
	if (memo[w][h] > -1) return;
	memo[w][h] = w*h;
	for (int i=0; i<n; i++) {
		if (plates[i].first > w || plates[i].second > h) continue;
		rec(w-plates[i].first, h);
		rec(plates[i].first, h);
		memo[w][h] = min(memo[w][h], memo[w-plates[i].first][h]+memo[plates[i].first][h]);
		rec(w, h-plates[i].second);
		rec(w, plates[i].second);
		memo[w][h] = min(memo[w][h], memo[w][h-plates[i].second]+memo[w][plates[i].second]);
	}
}
int main () {
	int w, h;
	cin >> w >> h;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> plates[i].first >> plates[i].second;
	}
	for (int i=0; i<=w; i++) {
		for (int j=0; j<=h; j++) {
			memo[i][j] = -1;
		}
	}
	memo[0][0] = 0;
	for (int i=0; i<n; i++) {
		memo[plates[i].first][plates[i].second] = 0;
	}
	rec(w, h);
	cout << memo[w][h] << endl;
}