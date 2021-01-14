/*
Condition for framed interval - 
	First element must be minimum
	Last element must be maximum
	Last element - First element = Size of range
Empodia can't intersect - Intersection of framed intervals is also framed interval.
Why condition on no neighbours have difference of 1?
	Prevents empodia of size 2 and 3.
*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int seq[n];
	for (int i=0; i<n; i++) {
		cin >> seq[i];
	}
	set<int> cur;
	vector< pair<int, int> > o;
	int left = 0;
	for (int i=1; i<n; i++) {
		cur = {seq[i]};
		for (int j=i-1; j>=left; j--) {
			cur.insert(seq[j]);
			if (*prev(cur.end()) != seq[i]) break;
			if (*cur.begin() == seq[j] && seq[i]-seq[j] == i-j) {
				o.push_back(make_pair(j, i));
				left = i;
				break;
			}
		}
	}
	cout << o.size() << endl;
	for (auto i: o) {
		cout << i.first+1 << " " << i.second+1 << endl;
	}
}