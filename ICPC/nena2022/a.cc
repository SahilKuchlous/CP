#include <iostream>
#include <string>
using namespace std;

int main () {
	string s1;
	string s2;
	cin >> s1;
	cin >> s2;
	int n = 1;
	for (int i = 0; i < 4; i++){
		if (s1[i]!=s2[i]){
			n *= 2;
		}
	}
	cout << n << endl;
}