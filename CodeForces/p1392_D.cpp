#include <iostream>
using namespace std;
#define MAXN 200005
int n;
char a[MAXN];
int o;
int main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		bool p1 = false, p2 = false;
		for (int i=0; i<n; i++) {
			cin >> a[i];
			if (a[i] == 'L') p1 = true;
			if (a[i] == 'R') p2 = true;
		}
		if (!p1 || !p2) {
			cout << (n+2)/3 << endl;
			continue;
		}
		o = 0;
		int st = 0;
		for (int i=0; i<n; i++) {
			if (a[i] != a[(n+i-1)%n]) st = i;
		}
		int cnt = 1;
		for (int i=st+1; i<n+st; i++) {
			if (a[i%n] == a[(n+i-1)%n]) {
				cnt++;
			} else {
				o += cnt/3;
				cnt = 1;
			}
		}
		o += cnt/3;
		cout << o << endl;
	}
}