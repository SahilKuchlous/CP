#include <iostream>
#include <iomanip>
#include <cmath>
#define PI 3.14159265358979323846264338327950L
using namespace std;
int main () {
	long double a, b, h, m;
	cout << fixed;
	cout << setprecision(15);
	cin >> a >> b >> h >> m;
	long double rad = 2 * PI * (h/12.0 + (m/60.0)/12.0 - m/60.0);
	long double dist = (a*a + b*b) - (2*a*b) * cos(rad);
	cout << sqrt(dist) << endl;
}