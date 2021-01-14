#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int n, a, b;
int hp[200100], dmg[200100];
long long ttl = 0;
vector< pair<int, int> > ord;
bool inc[200100];
int main () {
	cin >> n >> a >> b;
	for (int i=0; i<n; i++) {
		cin >> hp[i] >> dmg[i];
		ttl += dmg[i];
	}
	if (b == 0) {
		cout << ttl << endl;
		return 0;
	}
	for (int i=0; i<n; i++) {
		ord.push_back(make_pair(dmg[i]-hp[i], i));
	}
	sort(ord.begin(), ord.end());
	int last = -1;
	for (int i=0; i<ord.size(); i++) {
		if (ord[i].first >= 0) break;
		if (b == 0) break;
		ttl -= ord[i].first;
		last = ord[i].first;
		inc[ord[i].second] = true;
		b--;
	}
	long long mv = -1e9;
	for (int i=0; i<n; i++) {
		long long score = 1ll*hp[i]*pow(2, a)-dmg[i];
		if (inc[i]) score -= hp[i]-dmg[i];
		if (!inc[i] && b == 0) score += last;
		if (score > mv) mv = score;
	}
	if (mv > 0) ttl += mv;
	cout << ttl << endl;
}