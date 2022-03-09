#include <iostream>
using namespace std;

#define M 1000000007
typedef long long ll;

ll euclid(ll a, ll b, ll &x, ll &y) { 
	if (!b) return x = 1, y = 0, a;
	ll d = euclid(b, a % b, y, x); 
	return y-=a/b*x,d;
}

int main () {
	ll a, b;
	cin >> a >> b;

	ll n;
	cin >> n;
	n++;
	bool even = n%2 == 0;

	ll x = ((b*b)%M - (a*a)%M + M)%M;
	ll y = (2*(a*b%M))%M;
	ll d = ((a*a)%M + (b*b)%M)%M;

	ll ansD = 1;
	ll ansX = 1;
	ll ansY = 0;

	while(n > 0){
		if(n & 0x1){
			ansD = (ansD * d) % M;
			ll nextX = ((ansX * x) % M - (ansY * y) % M + M) % M;
			ll nextY = (ansX * y) % M + (ansY * x) % M;
			ansX = nextX % M;
			ansY = nextY % M;
		}

		ll nextX = ((x*x) % M - (y*y) % M + M) % M;
		ll nextY = (x*y) % M;
		x = nextX % M;
		y = (2*nextY) % M;
		d = (d*d) % M;
		n = n >> 1;
	}
	if(even) ansX = (-ansX+M)%M;

	ll k1;
	ll k2;
	euclid(ansD, M, k1, k2);
	ll ans = (k1 * ansX) % M;
	cout << (ans + M) % M << "\n";
}
