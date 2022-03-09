#include <iostream>
#include <set>
#include <string>
using namespace std;

int main(){
	set<string> s;

	long long k;
	long long r;
	cin >> k; //CHECK ORDER
	cin >> r;

	float max_profit = 0;

	int totals[k];
	int recipes[r][k];

	for(int i = 0; i < r+1; i++){
		if (i == 0){
			for (int j = 0; j < k; j++){
				cin >> totals[j];
			}
		}
		else {
			int min_ingredient = -1;
			for (int j = 0; j < k; j++){
				cin >> recipes[i-1][j];
				if (recipes[i-1][j] != 0 && (min_ingredient == -1 || (int)(totals[j]/recipes[i-1][j]) < min_ingredient)){
					min_ingredient = (int)(totals[j]/recipes[i-1][j]);
				}

			}
			int amount;
			cin >> amount;
			if (min_ingredient*amount > max_profit){
				max_profit = min_ingredient*amount;
			}
		}
	}

	cout << (int) max_profit << endl;
}