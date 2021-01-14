#include "grader.h"
#include "memory.h"
#include <vector>
using namespace std;
vector<int> pos[25];
void play () {
	for (int i=1; i<=50; i++) {
		int val = faceup(i)-'A';
		pos[val].push_back(i);
	}
	for (int i=0; i<25; i++) {
		faceup(pos[i][0]);
		faceup(pos[i][1]);
	}
}