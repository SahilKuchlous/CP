#include <iostream>
#include <algorithm>
using namespace std;
int main () {
	// a+d or b+c+d
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	int o = 0;
	if (e > f) {
		o += e*min(a, d);
		d -= min(a, d);
		o += f*min(b, min(c, d));
	} else {
		o += f*min(b, min(c, d));
		d -= min(b, min(c, d));
		o += e*min(a, d);
	}
	cout << o << endl;
}