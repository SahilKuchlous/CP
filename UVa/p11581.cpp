#include <iostream>
#include <cmath>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int g[3][3];
		int inp;
		for (int i=0; i<3; i++) {
			cin >> inp;
			for (int j=0; j<3; j++) {
				g[i][j] = inp%10;
				inp /= 10;
			}
		}
		int m[514];
		for (int i=0; i<514; i++) {
			m[i] = -1;
		}
		int ng[3][3];
		int c = 0;
		int s;
		int o;
		while (true) {
			s = 0;
			for (int i=0; i<3; i++) {
				for (int j=0; j<3; j++) {
					s += pow(2, i*3+j)*g[i][j];
				}
			}
			if (m[s] == -1) {
				m[s] = c;
			} else {
				o = m[s]-1;
				break;
			}
			c++;
			ng[0][0] = (g[0][1]+g[1][0])%2;
			ng[0][1] = (g[0][0]+g[0][2]+g[1][1])%2;
			ng[0][2] = (g[0][1]+g[1][2])%2;
			ng[1][0] = (g[0][0]+g[1][1]+g[2][0])%2;
			ng[1][1] = (g[0][1]+g[1][2]+g[2][1]+g[1][0])%2;
			ng[1][2] = (g[0][2]+g[2][2]+g[1][1])%2;
			ng[2][0] = (g[1][0]+g[2][1])%2;
			ng[2][1] = (g[1][1]+g[2][0]+g[2][2])%2;
			ng[2][2] = (g[1][2]+g[2][1])%2;
			for (int i=0; i<3; i++) {
				for (int j=0; j<3; j++) {
					g[i][j] = ng[i][j];
				}
			}
		}
		cout << o << endl;
	}
}