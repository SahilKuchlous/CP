#include <iostream>
#include <map>
#include <vector>
using namespace std;
int seq[100001];
vector<int> dp_prev(256, -1);
vector<int> dp_next(256, -1);
int main () {
	int n;
	cin >> n;
	char inp;
	for (int i=1; i<=n; i++) {
		cin >> inp;
		if (inp == 'M') seq[i] = 1;
		if (inp == 'B') seq[i] = 2;
		if (inp == 'F') seq[i] = 3;
	}
	dp_prev[0] = 0;
	bool eq1, eq2, eq3;
	int cur[4];
	int val;
	for (int i=1; i<=n; i++) {
		for (int j=0; j<256; j++) {
			if (dp_prev[j] == -1) continue;
			cur[0] = j%4, cur[1] = (j/4)%4, cur[2] = (j/(4*4))%4, cur[3] = (j/(4*4*4))%4;
			eq1 = false, eq2 = false, eq3 = false;
			if (cur[0] == 0) eq1 = true, eq3 = true;
			if (cur[1] == 0) eq2 = true, eq3 = true;
			if (cur[0] == seq[i]) eq1 = true;
			if (cur[1] == seq[i]) eq2 = true;
			if (cur[0] == cur[1]) eq3 = true;
			int s1 = 2;
			if (eq1 && eq2 && eq3) s1 = 1;
			if (!eq1 && !eq2 && !eq3) s1 = 3;
			val = cur[1]+seq[i]*4+cur[2]*4*4+cur[3]*4*4*4;
			dp_next[val] = max(dp_next[val], dp_prev[j]+s1);
			eq1 = false, eq2 = false, eq3 = false;
			if (cur[2] == 0) eq1 = true, eq3 = true;
			if (cur[3] == 0) eq2 = true, eq3 = true;
			if (cur[2] == seq[i]) eq1 = true;
			if (cur[3] == seq[i]) eq2 = true;
			if (cur[2] == cur[3]) eq3 = true;
			int s2 = 2;
			if (eq1 && eq2 && eq3) s2 = 1;
			if (!eq1 && !eq2 && !eq3) s2 = 3;
			val = cur[0]+cur[1]*4+cur[3]*4*4+seq[i]*4*4*4;
			dp_next[val] = max(dp_next[val], dp_prev[j]+s2);
		}
		dp_prev = dp_next;
		for (int j=0; j<256; j++) dp_next[j] = -1;
	}
	int o = 0;
	for (int i=0; i<256; i++) {
		o = max(o, dp_prev[i]);
	}
	cout << o << endl;
}