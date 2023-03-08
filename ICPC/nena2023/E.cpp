// Chipotgang 618311

#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;

int main(){
	double pi = atan(1) * 4;
	double eps = 1e-10;
	int r, s, h;
	cin >> r >> s >> h;
	double tropical_length = 2 * pi * r / (s*h);

	double x = abs(tropical_length - round(tropical_length));

	int a_bound = 1.0 / x;
	long long ans_1, ans_2, ans_3;
	double min_error = 1<<30;

	for(int a=2; a<=1000; a++){
		for(int b=2*a; b<=1000; b+=a){
			for(int c=2*b; c<=1000; c+=b){
				double error = abs(x - 1.0/a + 1.0/b - 1.0/c);
				if(error < min_error - eps){
					min_error = error;
					ans_1 = a;
					ans_2 = b;
					ans_3 = c;
				}
			}
		}
	}
	cout << ans_1 << ' ' << ans_2 << ' ' << ans_3 <<'\n';
}