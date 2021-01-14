#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;
ifstream fin("dishes.in");
ofstream fout("dishes.out");

int n;
int a[100100];
vector< deque<int> > stacks;

bool comp (const deque<int>& q1, const deque<int>& q2) {
	return q1.front()<q2.front();
}

int main () {
	int n;
	fin >> n;
	int a[n];
	for (int i=0; i<n; i++) {
		fin >> a[i];
	}
	stacks.push_back(deque<int>(1));
	int rem = 0;
	int pos;
	int out = n;
	for (int i=0; i<n; i++) {
		if (a[i] < rem) {
			out = i;
			break;
		}
		deque<int> q;
		q.push_front(a[i]);
		pos = lower_bound(stacks.begin(), stacks.end(), q, comp) - stacks.begin();
		if (pos == stacks.size()) {
			stacks.push_back(deque<int>());
		}
		if (a[i] < stacks[pos-1].back()) {
			while (stacks[pos-1].front() < a[i]) {
				rem = stacks[pos-1].front();
				stacks[pos-1].pop_front();
			}
			stacks[pos-1].push_front(a[i]);
		} else {
			stacks[pos].push_front(a[i]);
		}
	}
	fout << out << endl;
}