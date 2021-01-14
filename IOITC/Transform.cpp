#include <iostream>
#include <set>
#include <vector>
#include <cmath>
using namespace std;
struct ans {
	int x;
	int y;
	int k;
};
int main () {
	int n;
	cin >> n;
	int a[n];
	set< pair<int, int>, greater< pair<int, int> > > pos, neg;
	int cnt = 0;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		if (a[i] > 0) pos.insert(make_pair(a[i], i));
		if (a[i] < 0) neg.insert(make_pair(-a[i], i));
	}
	if ((pos.size() > 1 && neg.size() == 0) || (neg.size() > 1 && pos.size() == 0) || (neg.size() == 0 && pos.size() == 0)) {
		cout << 0 << endl;
		return 0;
	}
	vector<ans> o;
	while (pos.size() > 0 && neg.size() > 0) {
		ans cur;
		pair<int, int> p_num = *pos.begin();
		pair<int, int> n_num = *neg.begin();
		if (p_num.first > n_num.first) {
			cur.x = p_num.second;
			cur.y = n_num.second;
			cur.k = (int)log2(1.0*p_num.first/n_num.first);
			pos.erase(pos.begin());
			if (p_num.first-n_num.first*pow(2, cur.k) > 0) {
				pos.insert(make_pair(p_num.first-n_num.first*pow(2, cur.k), p_num.second));
			} else if (pos.size() == 0) {
				cur.k--;
				pos.insert(make_pair(p_num.first-n_num.first*pow(2, cur.k), p_num.second));
			}
		} else if (n_num.first > p_num.first) {
			cur.x = n_num.second;
			cur.y = p_num.second;
			cur.k = (int)log2(1.0*n_num.first/p_num.first);
			neg.erase(neg.begin());
			if (n_num.first-p_num.first*pow(2, cur.k) > 0) {
				neg.insert(make_pair(n_num.first-p_num.first*pow(2, cur.k), n_num.second));
			} else if (neg.size() == 0) {
				cur.k--;
				neg.insert(make_pair(n_num.first-p_num.first*pow(2, cur.k), n_num.second));
			}
		} else {
			if (pos.size() > 1) {
				cur.x = p_num.second;
				cur.y = n_num.second;
				cur.k = 0;
				pos.erase(pos.begin());
			} else {
				cur.x = n_num.second;
				cur.y = p_num.second;
				cur.k = 0;
				neg.erase(neg.begin());
			}
		}
		o.push_back(cur);
	}
	cout << 1 << endl;
	cout << o.size() << endl;
	for (auto i: o) {
		cout << i.x+1 << " " << i.y+1 << " " << i.k << endl;
	}
}