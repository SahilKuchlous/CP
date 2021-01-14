#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
int main () {
	ofstream outfile;
	outfile.open("inp.txt");
	outfile << "1000\n";
	for (int i=0; i<1000; i++) {
		outfile << rand()%100000+1 << '\n';
	}
	outfile << "100\n";
	int x, y;
	for (int i=0; i<100; i++) {
		x = rand()%1000;
		y = x+(rand()%(1000-x));
		outfile << x << " " << y << '\n';	
	}
	outfile.close();
}