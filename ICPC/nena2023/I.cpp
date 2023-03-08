#include <iostream>
using namespace std;
int main () {
	int n;
	cin >> n;
	pair<int, int> trees[n];
	for (int i=0; i<n; i++) {
		cin >> trees[i].first >> trees[i].second;
	}
	int dp[n];
	dp[0] = 1;
	for (int i=1; i<n; i++) {
		dp[i] = dp[i-1];
		for (int j=i; j>=0; j--) {
			if (trees[j].first < trees[i].first-trees[i].second && trees[i].first > trees[j].first+trees[j].second) {
				dp[i] = max(dp[i], dp[j]+1);
			}
		}
	}
	cout << n-dp[n-1] << endl;
}