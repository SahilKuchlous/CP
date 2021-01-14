#include <iostream>
#include <cmath>
using namespace std;
int main () {
  int t;
  cin >> t;
  while (t--) {
    long long n, m, c, p;
    cin >> n >> m >> c >> p;
    long long n_extra = c-abs(c-n%(2*c));
    long long m_extra = c-abs(c-m%(2*c));
    long long count = (n*m-n_extra*m_extra)/2;
    if (count >= p) {
      cout << "YAY" << endl;
    } else {
      cout << "NAY" << endl;
    }
  }
}