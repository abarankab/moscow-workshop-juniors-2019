#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; ++i)
#define all(c) c.begin(), c.end()
#define int long long

typedef long long ll;
typedef long double ld;

template <typename T> void uax(T &a, T b) { if (a < b) a = b; }
template <typename T> void uin(T &a, T b) { if (a > b) a = b; }

const int MAXN = 1e3 + 5;

int n, t[MAXN * 4], res;
int need[MAXN * 4];

void push(int v, int d) {
	need[v] += d;
}

void update(int v, int l, int r, int tl, int tr) {
	if (tl >= tr || l > tr - 1 || r < tl) return;
	if (tl >= l && tr - 1 <= r) {
		++need[v];
		t[v] += need[v];

		if (tr - tl != 1) {
			push(v * 2, need[v]);
			push(v * 2 + 1, need[v]);
		}

		need[v] = 0;
		return;
	}
	
	int m = (tl + tr) / 2;
	update(v * 2, l, r, tl, m);
	update(v * 2 + 1, l, r, m, tr);
}

int get(int v, int i, int tl, int tr) {
	t[v] += need[v];

	if (tr - tl != 1) {
		push(v * 2, need[v]);
		push(v * 2 + 1, need[v]);
	}

	need[v] = 0;

	if (tr - tl == 1) return t[v];
	
	int m = (tl + tr) / 2;
	if (i < m) {
		return get(v * 2, i, tl, m);
	}
	else {
		return get(v * 2 + 1, i, m, tr);
	}
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		int l1, r1;
		l1 = i;
		r1 = 2 * i;
		if (r1 > n) {
			update(1, l1 + 1, n, 1, n + 1);
			l1 = 0, r1 %= n;
		}
		update(1, l1 + 1, r1 + 1, 1, n + 1);
		res += get(1, i + 1, 1, n + 1);
	}

	cout << res << endl;
	
	return 0;
}