#include <iostream>
using namespace std;

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	for(int i = 0; i < t; i++){
		bool dec = false;
		bool used = false;
		char prev = '0';
		string num;
		cin >> num;

		for(char c : num){
			if(!dec){
				cout << c;
				if(c < prev){
					dec = true;
				}
				prev = c;
			}else{
				if (used) {
					cout << prev;
				} else if (c > prev) {
					cout << prev;
					used = true;
				} else {
					cout << c;
					prev = c;
				}
			}
		}
		cout << '\n';
	}
}