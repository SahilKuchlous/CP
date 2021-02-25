#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
#define MAXN 500005
int n;
int a[MAXN];
void solve1 () {
	int psum[n+1][3];
	psum[0][0] = psum[0][1] = psum[0][2] = 0;
	for (int i=1; i<=n; i++) {
		psum[i][0] = psum[i-1][0];
		psum[i][1] = psum[i-1][1];
		psum[i][2] = psum[i-1][2];
		psum[i][a[i-1]]++;
	}
	for (int i=0; i<n; i++) {
		if ((psum[i][(a[i]+1)%3] == 0 || psum[i][(a[i]+2)%3] > 0) && (psum[n][(a[i]+1)%3]-psum[i+1][(a[i]+1)%3] == 0 || psum[n][(a[i]+2)%3]-psum[i+1][(a[i]+2)%3] > 0)) {
			cout << 1;
		} else {
			cout << 0;
		}
	}
	cout << '\n';
}
void solve2 () {
	bool o1[n];
	for (int i=0; i<n; i++) {
		o1[i] = false;
	}
	for (int i=0; i<3; i++) {
		bool done[3];
		for (int i=0; i<3; i++) done[i] = false;
		bool no0 = true;
		bool nosuf = false;
		for (int j=0; j<n; j++) {
			if (a[j] == 0) no0 = false;
			if (a[j] == 1) done[0] = true;
			if ((done[0] || no0) && a[j] == 2) done[1] = true;
			if ((done[0] || no0) && a[j] == 2) nosuf = true;
			if (done[1] && a[j] == 1) done[2] = true;
			if (done[2] && a[j] == 0) o1[j] = true;
			if (j == 0 && a[j] == 0) o1[j] = true;
			if (nosuf && a[j] == 0) o1[j] = true;
			if (nosuf && (a[j] == 0 || a[j] == 1)) nosuf = false;
		}
		for (int j=0; j<n; j++) {
			a[j] = (a[j]+1)%3;
		}
	}
	for (int i=0; i<n/2; i++) {
		swap(a[i], a[n-i-1]);
	}
	bool o2[n];
	for (int i=0; i<n; i++) {
		o2[i] = false;
	}
	for (int i=0; i<3; i++) {
		bool done[3];
		for (int i=0; i<3; i++) done[i] = false;
		bool no0 = true;
		bool nosuf = false;
		for (int j=0; j<n; j++) {
			if (a[j] == 0) no0 = false;
			if (a[j] == 1) done[0] = true;
			if ((done[0] || no0) && a[j] == 2) done[1] = true;
			if ((done[0] || no0) && a[j] == 2) nosuf = true;
			if (done[1] && a[j] == 1) done[2] = true;
			if (done[2] && a[j] == 0) o2[j] = true;
			if (j == 0 && a[j] == 0) o2[j] = true;
			if (nosuf && a[j] == 0) o2[j] = true;
			if (nosuf && (a[j] == 0 || a[j] == 1)) nosuf = false;
		}
		for (int j=0; j<n; j++) {
			a[j] = (a[j]+1)%3;
		}
	}
	for (int i=0; i<n/2; i++) {
		swap(o2[i], o2[n-i-1]);
	}
	for (int i=0; i<n; i++) {
		if (o1[i] && o2[i]) {
			cout << 1;
		} else {
			cout << 0;
		}
	}
	cout << '\n';
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int type;
		cin >> type;
		string s;
		cin >> s;
		n = s.length();
		for (int i=0; i<n; i++) {
			if (s[i] == 'r') a[i] = 0;
			if (s[i] == 'p') a[i] = 1;
			if (s[i] == 's') a[i] = 2;
		}
		if (type == 1) {
			solve1();
		} else {
			solve2();
		}
	}
}