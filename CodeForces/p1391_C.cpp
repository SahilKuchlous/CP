#include <iostream>
using namespace std;
#define MOD 1000000007
long long bin[1000100];
long long fact[1000100];
int main () {
	int n;
	cin >> n;
	bin[0] = 1;
	fact[0] = 1;
	for (int i=1; i<=n; i++) {
		bin[i] = bin[i-1]*2 % MOD;
		fact[i] = fact[i-1]*i % MOD;
	}
	cout << (MOD+fact[n]-bin[n-1])%MOD << endl;
}