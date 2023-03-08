#include <iostream>
#include <vector>
#include <cstdlib> 
#include <ctime> 
using namespace std;
int main () {
	srand((unsigned)time(0)); 
	int n = 10;
	vector< pair<int, int> > edges;
	for (int i=0; i<n; i++) {
		for (int j=i+1; j<n; j++) {
			if (rand()%4 == 1) {
				edges.push_back(make_pair(i+1, j+1));
			}
		}
	}
	cout << n << " " << edges.size() << endl;
	for (auto i: edges) {
		cout << i.first << " " << i.second << endl;
	}
}