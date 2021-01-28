#include <iostream>
#define MOD 1000000007
using namespace std;
int main () {
	string n;
	cin >> n;
	long long p10[n.length()+1];
	p10[0] = 1;
	for (int i=1; i<=n.length(); i++) {
		p10[i] = (p10[i-1]*10)%MOD;
	}
	long long o = 0;
	long long a = 0;
	for (int i=0; i<n.length(); i++) {
		long long dig = n[n.length()-i-1]-'0';
		o = (o+dig*a%MOD)%MOD;
		a = (a+(i+1)*p10[i]%MOD)%MOD;
		long long r = n.length()-i-1;
		o = (o + (r*(r+1)/2)%MOD*dig%MOD*p10[i]%MOD) % MOD;
	}
	cout << o << endl;
}