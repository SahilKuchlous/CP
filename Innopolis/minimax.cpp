#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std;
double dist (double x1, double y1, double a, double b, double c) {
	return fabs((a * x1 + b * y1 + c))/(sqrt(a * a + b * b));
}
int main () {
	int n;
	cin >> n;
	pair<double, double> pts[n];
	for (int i=0; i<n; i++) {
		cin >> pts[i].first >> pts[i].second;
	}
	double o = 0;
	for (int i=0; i<n; i++) {
		for (int j=i+1; j<n; j++) {
			double a, b;
			double m = -(pts[i].first-pts[j].first)/(pts[i].second-pts[j].second);
			double c = (pts[i].second+pts[j].second)/2 - m*(pts[i].first+pts[j].first)/2;
			a = -m; b = 1; c = -c;
			if (pts[i].second == pts[j].second) {
				a = 1; b = 0; c = -(pts[i].first+pts[j].first)/2;
			}
			double min_d = 1e16;
			for (int k=0; k<n; k++) {
				double d = dist(pts[k].first, pts[k].second, a, b, c);
				min_d = min(min_d, d);
			}
			o = max(o, min_d);
		}
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			for (int k=j+1; k<n; k++) {
				if (i == j || i == k) continue;
				pair<double, double> m1 = make_pair((pts[i].first+pts[j].first)/2, (pts[i].second+pts[j].second)/2);
				pair<double, double> m2 = make_pair((pts[i].first+pts[k].first)/2, (pts[i].second+pts[k].second)/2);
				if (m1.first == m2.first && m1.second == m2.second) continue;
				double a, b, c, m;
				if (m1.first-m2.first == 0) {
					a = 1; b = 0; c = -m1.first;
				} else {
					m = (m1.second-m2.second)/(m1.first-m2.first);
					c = m1.second - m*m1.first;
					a = -m, b = 1, c = -c;
				}
				double min_d = 1e16;
				for (int k=0; k<n; k++) {
					double d = dist(pts[k].first, pts[k].second, a, b, c);
					min_d = min(min_d, d);
				}
				o = max(o, min_d);
			}
		}
	}
	cout << fixed << setprecision(11);
	cout << o << endl;
}