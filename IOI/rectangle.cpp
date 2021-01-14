using namespace std;
int main () {
	while (true) {
		int x = dimension_x();
		int y = dimension_y();
		if (x > y) {
			int l = 0, r = 32, m;
			int ans = 0;
			while (l <= r) {
				m = (l+r)/2;
				if ((1<<m)*(y+1)-1 < x) {
					ans = m;
					l = m+1;
				} else {
					r = m-1;
				}
			}
			cut(vertical, (1<<ans)*(y+1)-1);
		} else {
			int l = 0, r = 32, m;
			int ans = 0;
			while (l <= r) {
				m = (l+r)/2;
				if ((1<<m)*(x+1)-1 < y) {
					ans = m;
					l = m+1;
				} else {
					r = m-1;
				}
			}
			cut(horizontal, (1<<ans)*(x+1)-1);
		}
	}
}