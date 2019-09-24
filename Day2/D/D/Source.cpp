#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long double ld;

const int MAXN = 1e5 + 5;
const ld INF = 1e30, EPS = 1e-8;

struct ln {
	ld a, b;
	ld x;

	ln() {}

	ln(ld _a, ld _b, ld _x) {
		a = _a, b = _b, x = _x;
	}

	ln(ld _a, ld _b) {
		a = _a, b = _b, x = -INF;
	}
};

ld inter(ld a, ld b, ld c, ld d) {
	return (d - b) / (a - c);
}

int n;
ld minr = 1e18, ans;
ln all[MAXN];
vector<ln> u, un, d, dn;

bool cmp1(ln a, ln b) {
	if (a.a == b.a) return a.b < b.b;
	return a.a < b.a;
}

bool cmp2(ln a, ln b) {
	if (a.a == b.a) return a.b > b.b;
	return a.a > b.a;
}

signed main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		ld a, b;
		cin >> b >> a;
		all[i] = ln(a, b);
	}
	sort(all, all + n, cmp1);
	for (int i = 0; i < n; ++i) {
		while (u.size()) {
			if (all[i].a == u.back().a && all[i].b >= u.back().b) {
				u.pop_back();
			}
			else if (inter(all[i].a, all[i].b, u.back().a, u.back().b) <= u.back().x) {
				u.pop_back();
			}
			else {
				break;
			}
		}
		if (!u.size()) u.push_back(all[i]);
		else u.push_back(ln(all[i].a, all[i].b, inter(all[i].a, all[i].b, u.back().a, u.back().b)));
	}
	for (int i = 0; i < u.size(); ++i) {
		if ((i == u.size() - 1) || (u[i + 1].x >= 0)) {
			un.push_back(u[i]);
		}
	}
	swap(un, u);
	if (u[0].x < 0) u[0].x = 0;
	un.clear();

	sort(all, all + n, cmp2);
	for (int i = 0; i < n; ++i) {
		while (d.size()) {
			if (all[i].a == d.back().a && all[i].b <= d.back().b) {
				d.pop_back();
			}
			else if (inter(all[i].a, all[i].b, d.back().a, d.back().b) <= d.back().x) {
				d.pop_back();
			}
			else {
				break;
			}
		}
		if (!d.size()) d.push_back(all[i]);
		else d.push_back(ln(all[i].a, all[i].b, inter(all[i].a, all[i].b, d.back().a, d.back().b)));
	}
	for (int i = 0; i < d.size(); ++i) {
		if ((i == d.size() - 1) || (d[i + 1].x >= 0)) {
			dn.push_back(d[i]);
		}
	}
	swap(dn, d);
	if (d[0].x < 0) d[0].x = 0;
	dn.clear();

	int i1 = 0, i2 = 0;
	ld nowx = 0;

	if ((u[i1].a - d[i2].a) * nowx + u[i1].b - d[i2].b < minr) {
		minr = (u[i1].a - d[i2].a) * nowx + u[i1].b - d[i2].b;
		ans = nowx;
	}

	while (!(u.size() - 1 == i1 && d.size() - 1 == i2)) {
		if ((u[i1].a - d[i2].a) * nowx + u[i1].b - d[i2].b < minr) {
			minr = (u[i1].a - d[i2].a) * nowx + u[i1].b - d[i2].b;
			ans = nowx;
		}

		if (i1 != u.size() - 1 && i2 != d.size() - 1) {
			if (u[i1 + 1].x < d[i2 + 1].x) ++i1, nowx = u[i1].x;
			else ++i2, nowx = d[i2].x;
		}
		else if (i1 == u.size() - 1) {
			++i2, nowx = d[i2].x;
		}
		else {
			++i1, nowx = u[i1].x;
		}

		if ((u[i1].a - d[i2].a) * nowx + u[i1].b - d[i2].b < minr) {
			minr = (u[i1].a - d[i2].a) * nowx + u[i1].b - d[i2].b;
			ans = nowx;
		}
	}

	cout.precision(20);
	cout << ans << endl << minr << endl;
	return 0;
}