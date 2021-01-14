#include <iostream>
#include <fstream>
#include <map>
using namespace std;
ifstream fin("reststops.in");
ofstream fout("reststops.out");
int main () {
    int l, n, rf, rb;
    fin >> l >> n >> rf >> rb;
    map<int, int> stops;
    int a, b;
    for (int i=0; i<n; i++) {
        fin >> a >> b;
        stops[a] = b;
    }
    pair<long long, long long> best[l+1];
    best[l] = make_pair(-1, -1);
    for (int i=l-1; i>=0; i--) {
        best[i] = best[i+1];
        if (stops.find(i) != stops.end() && stops[i] > best[i].first) {
            best[i] = make_pair(stops[i], i);
        }
    }
    int x = 0;
    long long o = 0;
    while (best[x].first > -1) {
        if (o == 0) {
            o += (best[x].second-x)*(rf-rb)*best[x].first;
        } else {
            o += (best[x].second-x+1)*(rf-rb)*best[x].first;
        }
        x = best[x].second+1;
    }
    fout << o << endl;
}