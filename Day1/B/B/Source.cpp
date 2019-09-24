#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <algorithm>

#define all(x) x.begin(), x.end()

using namespace std;

const int MAXN = 1e3 + 5;

struct circle {
	int x, y, r, w;

	circle() {}

	circle(int _x, int _y, int _r, int _w) { x = _x, y = _y, r = _r, w = _w; }
};

struct point {
	int x, type, w;

	point() {}

	point(int _x, int _type, int _w) {
		x = _x;
		type = _type;
		w = _w;
	}
};

bool operator<(point a, point b) {
	if (a.x == b.x) return a.type < b.type;
	return a.x < b.x;
}

int n, m, k, maxr, cnt;
circle cr[MAXN];
vector<point> mod[MAXN];

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> m >> n >> k;
	for (int i = 0; i < k; ++i) {
		int x, y, r, w;
		cin >> x >> y >> r >> w;
		cr[i] = circle(x, y, r, w);
	}
	for (int row = 1; row <= n; ++row) {
		for (int i = 0; i < k; ++i) {
			circle c = cr[i];
			int dx = abs(row - c.x);
			if (dx <= c.r) {
				int l = 0, r = c.y;
				while (r - l > 1) {
					int mid = (l + r) / 2;
					if (dx * dx + (c.y - mid) * (c.y - mid) <= c.r * c.r) {
						r = mid;
					}
					else l = mid;
				}
				mod[row].push_back(point(r, -1, c.w));

				l = c.y, r = m + 1;
				while (r - l > 1) {
					int mid = (l + r) / 2;
					if (dx * dx + (c.y - mid) * (c.y - mid) <= c.r * c.r) {
						l = mid;
					}
					else r = mid;
				}
				mod[row].push_back(point(l, 1, c.w));
			}
		}
		sort(all(mod[row]));
		int now = 0;
		for (point p : mod[row]) {
			now -= p.w * p.type;
			if (now > maxr) maxr = now;
		}
	}

	for (int row = 1; row <= n; ++row) {
		int now = 0, pr = -1;
		for (point p : mod[row]) {
			if (now == maxr && p.type == 1) {
				cnt += p.x - pr + 1;
			}
			now -= p.w * p.type;
			pr = p.x;
		}
	}
	cout << maxr << endl << cnt;
	return 0;
}