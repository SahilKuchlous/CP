#include <iostream>
#include <iomanip>
using namespace std;

#define MAXN 200000
typedef long long ll;

int points[MAXN][2];
ll areas[MAXN];

int main () {
	int n;
	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> points[i][0];
		cin >> points[i][1];
	}

	ll tot = 0;
	for(int i = 0; i < n-2; i++){
		ll x1 = points[1+i][0] - points[0][0];
		ll y1 = points[1+i][1] - points[0][1];
		ll x2 = points[1+i][0] - points[2+i][0];
		ll y2 = points[1+i][1] - points[2+i][1];
		areas[i] = abs((x1*y2 - x2*y1));
		tot += areas[i];
	}

	ll cum = 0;
	for(int i = 0; i < n-2; i++){
		if(2*(cum + areas[i]) == tot){
			cout << points[2+i][0] << " " << points[2+i][1] << "\n";
			return 0;
		}

		if(2*cum < tot && 2*(cum + areas[i]) > tot){
			double diff = tot/2.0 - cum;
			double x = points[1+i][0] + diff * (points[2+i][0] - points[1+i][0]) / (double) areas[i];
			double y = points[1+i][1] + diff * (points[2+i][1] - points[1+i][1]) / (double) areas[i];
			cout << fixed << setprecision(12);
			cout << x << " " << y << "\n";
			return 0;
		}
		cum += areas[i];
	}
}