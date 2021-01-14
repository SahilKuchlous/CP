#include "combo.h"
#include <vector>
using namespace std;
string guess_sequence (int n) {
	string ans = "";
	vector<string> opts;
	if (press("AB")) {
		if (press("A")) {
			ans = "A";
			opts = {"B", "X", "Y"};
		} else{
			ans = "B";
			opts = {"A", "X", "Y"};
		}
	} else {
		if (press("X")) {
			ans = "X";
			opts = {"A", "B", "Y"};
		} else {
			ans = "Y";
			opts = {"A", "B", "X"};
		}
	}
	string q;
	for (int i=1; i<n-1; i++) {
		q = ans+opts[0];
		for (int j=0; j<3; j++) {
			q += ans+opts[1]+opts[j];
		}
		int l = press(q);
		if (l == i) {
			ans += opts[2];
		} else if (l == i+1) {
			ans += opts[0];
		} else {
			ans += opts[1];
		}
	}
	if (n > 1) {
		if (press(ans+opts[0]) == n) {
			ans += opts[0];
		} else if (press(ans+opts[1]) == n) {
			ans += opts[1];
		} else {
			ans += opts[2];
		}
	}
	return ans;
}