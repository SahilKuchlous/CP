#include "grader.h"
#include "cluedo.h"
#include <vector>
using namespace std;
void Solve () {
	vector<int> cur = {0, 1, 1, 1};
	while (true) {
		cur[Theory(cur[1], cur[2], cur[3])]++;
		if (cur[0] > 0) return;
	}
}