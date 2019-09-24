#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

typedef long double ld;

const ld EPS = 1e-9;

ld h, w;
pair<ld, ld> a, b, m;

ld dp(pair<ld, ld> a, pair<ld, ld> b, pair<ld, ld> c) {
	pair<ld, ld> n = { a.first - b.first, a.second - b.second };
	pair<ld, ld> m = { c.first - b.first, c.second - b.second };
	return n.first * m.second - n.second * m.first;
}

ld cp(pair<ld, ld> a, pair<ld, ld> b, pair<ld, ld> c) {
	pair<ld, ld> n = { a.first - b.first, a.second - b.second };
	pair<ld, ld> m = { c.first - b.first, c.second - b.second };
	return (n.first * m.first + n.second * m.second) / sqrt(n.first * n.first + n.second * n.second) / sqrt(m.first * m.first + m.second * m.second);
}

signed main() {
	cin >> w >> h >> a.first >> a.second >> b.first >> b.second;
	m = { w / 2, h / 2 };
	if (dp(a, m, b) < EPS && abs(cp(a, m, b) + 1) > EPS) {
		cout << "NO" << endl;
	}
	else {
		pair<ld, ld> res = { ceil((a.first + b.first - 2 * m.first) * 10000), ceil((a.second + b.second - 2 * m.second) * 10000) };
		if (res.first < EPS && res.second < EPS) {
			res = { ceil((a.second - m.second) * 10000), ceil((m.first - a.first) * 10000) };
		}
		cout << "YES" << endl;
		cout << m.first - res.first << " " << m.second - res.second << endl;
		cout << m.first + res.first << " " << m.first + res.second << endl;
	}
	return 0;
}