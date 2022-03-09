#include <iostream>
#include <string>
#include <map>
using namespace std;

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	int outer_results[t];
	
	for (int i =0; i < t; i++){
		outer_results[i] = 0;
		string s;
		cin >> s;
		for (int k = 0; k <= 6; k++){
			int r = 1;
			int counter = 0;
			int bound = 2;
			map<char, int> tracker;
			tracker['J'] = 0;
			tracker['L'] = 0;
			tracker['S'] = 0;
			tracker['Z'] = 0;
			tracker['I'] = 0;
			tracker['O'] = 0;
			tracker['T'] = 0;
			for (int j = k; j < s.length(); j++){
				tracker[s[j]] += 1;
				counter += 1;
				if (!(tracker['J'] < bound && tracker['L'] < bound && tracker['S'] < bound && tracker['Z'] < bound &&  tracker['I'] < bound && tracker['O'] < bound && tracker['T'] < bound)){
					r=0;
					break;
				}
				if (counter % 7 == 0){
					bound+=1;
				}
			}
			if (r == 1){
				tracker['J'] = 0;
				tracker['L'] = 0;
				tracker['S'] = 0;
				tracker['Z'] = 0;
				tracker['I'] = 0;
				tracker['O'] = 0;
				tracker['T'] = 0;
				for (int j = 0; j < k; j++){
					tracker[s[j]] += 1;
				}
				if (!(tracker['J'] < 2 && tracker['L'] < 2 && tracker['S'] < 2 && tracker['Z'] < 2 &&  tracker['I'] < 2 && tracker['O'] < 2 && tracker['T'] < 2)){
					r=0;
					continue;
				}
				outer_results[i] = 1;
				break;
			}
		}
	}

	for (int i = 0; i < t; i++){
		cout << outer_results[i] << '\n';
	}
}