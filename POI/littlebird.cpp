#include <iostream>
#include <deque>
using namespace std;
int n;
int ht[1000000];
int q;
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> ht[i];
	}
	cin >> q;
	while (q--) {
		int st;
		cin >> st;
		deque<int> up, down;
		int pos = 0;
		for (int i=1; i<st; i++) {
			while (up.size() > 0 && ht[up.back()] <= ht[i]) up.pop_back();
			up.push_back(i);
			if (ht[i] < ht[0]) {
				while (down.size() > 0 && ht[down.back()] <= ht[i]) down.pop_back();
				down.push_back(i);
			}
		}
		int nxt = st, o = 0;
		while (pos < n-1) {
			nxt = max(nxt, pos+1);
			while (nxt < min(n, pos+st+1)) {
				while (up.size() > 0 && ht[up.back()] <= ht[nxt]) up.pop_back();
				up.push_back(nxt);
				if (ht[nxt] < ht[pos]) {
					while (down.size() > 0 && ht[down.back()]<= ht[nxt]) down.pop_back();
					down.push_back(nxt);
				}
				nxt++;
			}
			if (down.size() > 0) {
				pos = down.front();
				down.pop_front();
			} else {
				pos = up.front();
				up.pop_front();
				down = up;
				while (up.size() > 0) up.pop_back();
				o++;
			}
		}
		cout << o << endl;
	}
}