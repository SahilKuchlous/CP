
#include <iostream>
using namespace std;

int main(){
	int n; cin>>n;
	int A[n+1][2];
	for(int i=0; i<=n; i++){
		cin>>A[i][0]>>A[i][1];
	}
	int c, sx, sy, r, dx, dy, v;
	cin >> c >> sx >> sy >> r >> dx >> dy >> v;
	// compute camera y
	double cy;
	for(int i=0; i<n; i++){
		if(A[i][0] <= c && c <= A[i+1][0]){
			cy = A[i][1] + ((double) A[i+1][1] - A[i][1]) / (A[i+1][0] - A[i][0]) * (c - A[i][0]);
		}
	}
	for(int i=0; i<n; i++){
		
	}
}