#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <math.h>

#pragma comment(linker, "/STACK:36777216")

using namespace std;

#define int long long

const int MAXN = 1e6;

int a, b, t[MAXN * 4];
int res = MAXN;

const int conv[10] = { 0, 1, 2, 3, 2, 1, 2, 3, 4, 2 };

int len(int x) {
	return conv[x % 10] + conv[(x / 10) % 10] + conv[(x / 100) % 10] + conv[(x / 1000) % 10] + conv[(x / 10000) % 10] + conv[(x / 100000) % 10];
}

void update(int v, int l, int r, int i) {
	if (r - l == 1) {
		t[v] = len(i);
		return;
	}

	int m = (l + r) / 2;
	if (i < m) {
		update(v * 2, l, m, i);
	}
	else update(v * 2 + 1, m, r, i);
	t[v] = min(t[v * 2], t[v * 2 + 1]);
}

int get(int v, int tl, int tr, int l, int r) {
	if (tl >= r || tr <= l) return MAXN;
	if (tl >= l && tr <= r) return t[v];
	
	int m = (tl + tr) / 2;
	return min(get(v * 2, tl, m, l, r), get(v * 2 + 1, m, tr, l, r));
}

long double as, bs;

signed main() {
	for (int i = 0; i < 4 * MAXN; ++i) t[i] = MAXN;

	cin >> as >> bs;
	a = (int)(as * 1e9);
	b = (int)(bs * 1e9);

	for (int i = 1; i < MAXN; ++i) {
		update(1, 1, MAXN, i);
	}

	for (int x = 1; x < MAXN; ++x) {
		int yr = (int)(((long double)b * (long double)x) / (long double)1e9);
		int yl = ceil(((long double)a * (long double)x) / (long double)1e9);

		if (yl <= yr && get(1, 1, MAXN, yl, yr + 1) + len(x) < res) {
			res = get(1, 1, MAXN + 5, yl, yr + 1) + len(x);
		}
	}

	if (res == MAXN) {
		cout << "IMPOSSIBLE" << endl;
	}
	else {
		cout << res << endl;
	}

	return 0;
}