#include <iostream>
#include <set>
using namespace std;
int main () {
	int t;
	cin >> t;
	for (int z=0; z<t; z++) {
		int n;
		cin >> n;
		int grid[n][n];
		int trace = 0;
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				cin >> grid[i][j];
				if (i == j) trace += grid[i][j];
			}
		}
		int rep_rows = 0;
		set<int> found;
		for (int i=0; i<n; i++) {
			found.clear();
			for (int j=0; j<n; j++) {
				if (found.find(grid[i][j]) != found.end()) {
					rep_rows++;
					break;
				}
				found.insert(grid[i][j]);
			}
		}
		int rep_cols = 0;
		for (int j=0; j<n; j++) {
			found.clear();
			for (int i=0; i<n; i++) {
				if (found.find(grid[i][j]) != found.end()) {
					rep_cols++;
					break;
				}
				found.insert(grid[i][j]);
			}
		}
		cout << "Case #" << z+1 << ": " << trace << " " << rep_rows << " " << rep_cols << endl;
	}
}