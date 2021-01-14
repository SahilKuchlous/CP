#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;
ifstream fin("square.in");
ofstream fout("square.out");
int main () {
	int x1, y1, x2, y2, x3, y3, x4, y4;
	fin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
	int xu = min(x1, x3);
	int yu = min(y1, y3);
	int xl = max(x2, x4);
	int yl = max(y2, y4);
	if (xl-xu > yl-yu) {
		fout << (xl-xu)*(xl-xu) << endl;
	} else {
		fout << (yl-yu)*(yl-yu) << endl;
	}
}