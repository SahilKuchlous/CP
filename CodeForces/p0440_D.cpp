#include <iostream>
#include <vector>
using namespace std;
int n, k;
vector<int> adj[410];
int main () {
	cin >> n >> k;
	int ai, bi;
	for (int i=0; i<n-1; i++) {
		cin >> ai >> bi;
		ai--; bi--;
		adj[ai].push_back(bi);
		adj[bi].push_back(ai);
	}
	
}