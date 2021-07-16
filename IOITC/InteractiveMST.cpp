#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> query(vector<int> W);

vector<int> findHiddenPermutation (int m) {
	vector<int> pos;
	vector< set<int> > msts(m);
	for (int i=0; i<m; i++) {
		vector<int> q;
		for (int j=0; j<m; j++) {
			q.push_back((j+i)%m+1);
		}
		vector<int> mst = query(q);
		/*
		for (auto i: q) {
			cout << i << " ";
		}
		cout << endl;
		for (auto i: mst) {
			cout << i << " ";
		}
		cout << endl;
		*/
		for (auto j: mst) {
			msts[i].insert(j);
		}
	}
	for (int i=0; i<m; i++) {
		pos.push_back(-1);
		int max_pos = m-i-1;
		int min_pos = (max_pos+1)%m;
		for (int j=0; j<m; j++) {
			if (msts[min_pos].find(j) != msts[min_pos].end() && msts[max_pos].find(j) == msts[max_pos].end()) {
				pos[i] = j;
				break;
			}
		}
	}
	int cnt = 0;
	int last = -1;
	bool done[m];
	for (int i=0; i<m; i++) {
		done[i] = false;
	}
	for (int i=0; i<m; i++) {
		if (pos[i] == -1) {
			cnt++;
			last = i;
		} else {
			done[pos[i]] = true;
		}
	}
	if (cnt > 1) {
		return {};
	}
	if (cnt == 1) {
		for (int i=0; i<m; i++) {
			if (!done[i]) {
				pos[last] = i;
				break;
			}
		}
	}
	/*
	for (auto i: pos) {
		cout << i << " ";
	}
	cout << endl;
	*/
	return pos;
}

/*
vector<int> findHiddenPermutation (int m) {
	if (m == 1) return {0};
    return {};
}
*/