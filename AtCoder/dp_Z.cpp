#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
long long c;
long long ht[200100];
long long dp[200100];
vector<int> cur;
int main () {
	cin >> n >> c;
	for (int i=0; i<n; i++) {
		cin >> ht[i];
	}
	dp[0] = 0;
	cur.push_back(0);
	for (int i=1; i<n; i++) {
		while (cur.size() > 1) {
			int p1 = cur[cur.size()-1], p2 = cur[cur.size()-2];
			if (dp[p1]+(ht[i]-ht[p1])*(ht[i]-ht[p1]) > dp[p2]+(ht[i]-ht[p2])*(ht[i]-ht[p2])) {
				cur.pop_back();
			} else {
				break;
			}
		}
		dp[i] = dp[cur.back()]+(ht[i]-ht[cur.back()])*(ht[i]-ht[cur.back()])+c;
	}
	cout << dp[n-1] << endl;
}