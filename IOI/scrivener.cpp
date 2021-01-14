#include "grader.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
char val[1000100];
int par[1000100];
int depth[1000100];
int bin[1000100][30];
int cnt = 0;
vector<int> hist;
void Init () {
	val[0] = '-';
	par[0] = 0;
	depth[0] = 0;
	for (int i=0; i<30; i++) {
		bin[0][i] = 0;
	}
	hist.push_back(0);
	cnt = 1;
}
void TypeLetter (char L) {
	val[cnt] = L;
	par[cnt] = hist.back();
	depth[cnt] = depth[par[cnt]]+1;
	bin[cnt][0] = par[cnt];
	for (int i=1; i<30; i++) {
		bin[cnt][i] = bin[bin[cnt][i-1]][i-1];
	}
	hist.push_back(cnt);
	cnt++;
}
void UndoCommands (int U) {
	hist.push_back(hist[hist.size()-U-1]);
}
char GetLetter (int P) {
	int dist = depth[hist.back()]-P-1;
	int pos = hist.back();
	while (dist > 0) {
		for (int i=0; i<30; i++) {
			if (dist-(1<<i) < 0) {
				dist -= (1<<(i-1));
				pos = bin[pos][i-1];
				break;
			}
		}
	}
	return val[pos];
}