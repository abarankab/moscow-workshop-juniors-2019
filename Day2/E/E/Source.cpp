#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

#define all(c) c.begin(), c.end()

typedef long double ld;

const ld EPS = 1e-9, INF = 1e18;
const int MAXN = 1e5 + 5;

struct point {
	ld x, y;

	point() {}

	point(ld _x, ld _y) { x = _x, y = _y; }
};

ld babs(ld a) {
	if (a < 0) return -a;
	return a;
}

struct event {
	int id, type;
	ld x;

	event() {}

	event(ld _x, int _id, int _type) {
		x = _x;
		id = _id;
		type = _type;
	}
};

bool operator<(event a, event b) {
	if (babs(a.x - b.x) < EPS) return a.type < b.type;
	return a.x < b.x;
}

bool operator!=(point a, point b) {
	return babs(a.x - b.x) > EPS || babs(a.y - b.y) > EPS;
}

bool operator==(point a, point b) {
	return babs(a.x - b.x) < EPS && babs(a.y - b.y) < EPS;
}

int n, res;
vector<event> e;
set<int> open;
bool need[MAXN], done[MAXN];
ld h;
vector<point> al, ar, a;

ld dp(point a, point b, point c) {
	if (a == c) return 0;
	point w = point(b.x - a.x, b.y - a.y);
	point r = point(c.x - a.x, c.y - a.y);
	return w.x * r.y - w.y * r.x;
}

ld intersect(point a, point b) {
	return a.x + (b.x - a.x) / (b.y - a.y) * (h - a.y);
}

signed main() {
	cin >> n >> h;
	for (int i = 0; i < n; ++i) {
		ld x, y;
		cin >> x >> y >> need[i];
		al.push_back(point(x, y));
		ar.push_back(point(x, y));
		a.push_back(point(x, y));
	}
	reverse(al.begin(), al.end());
	point now = al.back();
	al.pop_back();
	for (int i = 0; i < n; ++i) {
		while (al.size() && dp(a[i], al.back(), now) <= EPS) {
			now = al.back(), al.pop_back();
		}

		if (need[i]) {
			if (now != a[i] && intersect(a[i], now) > a[i].x) e.push_back(event(intersect(a[i], now), i, 1));
			else e.push_back(event(INF, i, 1));
		}
	}
	now = ar.back();
	ar.pop_back();
	for (int i = n - 1; i >= 0; --i) {
		while (ar.size() && dp(a[i], ar.back(), now) >= -EPS) {
			now = ar.back(), ar.pop_back();
		}

		if (need[i]) {
			if (now != a[i] && intersect(a[i], now) < a[i].x) e.push_back(event(intersect(a[i], now), i, -1));
			else e.push_back(event(-INF, i, -1));
		}
	}

	sort(all(e));
	for (int i = 0; i < e.size(); ++i) {
		if (e[i].type == -1) {
			open.insert(e[i].id);
		}
		else if (!done[e[i].id]) {
			++res;
			while (!open.empty()) {
				done[*open.begin()] = 1;
				open.erase(open.begin());
			}
		}
	}

	cout << res << endl;

	return 0;
}