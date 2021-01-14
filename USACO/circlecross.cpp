#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <set>
using namespace std;
ifstream fin("circlecross.in");
ofstream fout("circlecross.out");
int n, inp;
int segtree[400000];
vector< pair<int, int> > start;
map<int, int> endp;
set<int> occ;
void update (int x, int l, int r, int v) {
  if (l == r && v == l) {
    segtree[x]++;
    return;
  }
  if (l > v || r < v) {
    return;
  }
  segtree[x]++;
  int m = (l+r)/2;
  update(2*x+1, l, m, v);
  update(2*x+2, m+1, r, v);
}
int query (int x, int l, int r, int a, int b) {
  if (a <= l && r <= b) {
    return segtree[x];
  }
  if (r < a || l > b) {
    return 0;
  }
  int m = (l+r)/2;
  int o = query(2*x+1, l, m, a, b);
  o += query(2*x+2, m+1, r, a, b);
  return o;
}
int main() {
  fin >> n;
  for (int i=0; i<2*n; i++) {
    fin >> inp;
    if (occ.find(inp) == occ.end()) {
      start.push_back(make_pair(inp, i));
      occ.insert(inp);
    } else {
      endp[inp] = i;
    }
  }
  long long o = 0;
  for (auto i: start) {
    // cout << i.second << " " << endp[i.first] << endl;
    o += query(0, 0, 2*n-1, i.second, endp[i.first]);
    update(0, 0, 2*n-1, endp[i.first]);
  }
  fout << o << endl;
}