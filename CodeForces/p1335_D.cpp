#include <iostream>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int grid[9][9];
		char inp;
		for (int i=0; i<9; i++) {
			for (int j=0; j<9; j++) {
				cin >> inp;
				grid[i][j] = inp-'0';
			}
		}
		grid[0][0] = (grid[0][0] == 1 ? 2 : 1);
		grid[3][1] = (grid[3][1] == 1 ? 2 : 1);
		grid[6][2] = (grid[6][2] == 1 ? 2 : 1);
		grid[1][3] = (grid[1][3] == 1 ? 2 : 1);
		grid[4][4] = (grid[4][4] == 1 ? 2 : 1);
		grid[7][5] = (grid[7][5] == 1 ? 2 : 1);
		grid[2][6] = (grid[2][6] == 1 ? 2 : 1);
		grid[5][7] = (grid[5][7] == 1 ? 2 : 1);
		grid[8][8] = (grid[8][8] == 1 ? 2 : 1);
		for (int i=0; i<9; i++) {
			for (int j=0; j<9; j++) {
				cout << grid[i][j];
			}
			cout << endl;
		}
	}
}