#include <iostream>
using namespace std;
int main () {
	while (true) {
		float t, p, a, v;
		int r;
		cin >> t >> p >> a >> r;
		if (t < 0) {
			break;
		}
		pair<float, float> d[r];
		for (int i=0; i<r; i++) {
			cin >> d[i].first >> d[i].second;
		}
		v = a+p;
		int c = 1;
		int di = 0;
		v *= 1-d[di].second;
		while (a >= v) {
			cout << a << " " << v << endl;
			if (d[di+1].first == c) {
				di++;
			}
			a -= p;
			v *= 1-d[di].second;
			c++;
		}
		cout << a << " " << v << endl;
		cout << c << endl;
	}
}