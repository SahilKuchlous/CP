#include <iostream>
#include <set>
#include <string>
using namespace std;

int main(){
	set<string> s;

	long long n;
	long long p;
	cin >> p;
	cin >> n;

	for(int i = 0; i < n; i++){
		string st;
		cin >> st;
		s.insert(st);

		if(s.size() == p){
			cout << i + 1 << endl;
			return 0;
		}
	}

	cout << "paradox avoided" << endl;
}