#include <iostream>
#include <vector>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;
		int ai, bi;
		vector<int> adj[n+1];
		for (int i=0; i<n-1; i++) {
			cin >> ai >> bi;
			adj[ai].push_back(bi);
			adj[bi].push_back(ai);
		}
		if (adj[x].size() <= 1) {
			cout << "Ayush" << endl;
		} else {
			cout << (n%2==0 ? "Ayush":"Ashish") << endl;
		}
	}
}