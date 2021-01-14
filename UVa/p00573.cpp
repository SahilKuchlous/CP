#include <iostream>
using namespace std;
int main () {
	while (true) {
		float h, u, d, f;
		cin >> h >> u >> d >> f;
		if (h == 0) {
			break;
		}
		float r = u*f/100.0;
		int day = 0;
		float height = 0;
		bool suc;
		while (true) {
			day += 1;
			height += u;
			if (height > h) {
				suc = true;
				break;
			}
			height -= d;
			if (height < 0) {
				suc = false;
				break;
			}
			u -= r;
			if (u < 0) {
				u = 0;
			}
		}
		if (suc) {
			cout << "success on day " << day << endl;
		} else {
			cout << "failure on day " << day << endl;
		}
	}
}