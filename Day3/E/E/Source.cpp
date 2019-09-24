#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int MAXN = 1e6 + 6, INF = 1e9;

int n, m;
pair<int, int> t[MAXN * 4];
int to[MAXN * 4];

void init(int v, int tl, int tr) {
	if (tr - tl == 1) {
		t[v] = { 0, tl };
		return;
	}

	int m = (tl + tr) / 2;
	init(v * 2, tl, m);
	init(v * 2 + 1, m, tr);

	t[v] = min(t[v * 2], t[v * 2 + 1]);
}

void push(int v, bool l) {
	if (to[v]) {
		if (t[v].first < to[v]) t[v].first = to[v];

		if (!l) {
			to[v * 2] = max(to[v * 2], to[v]);
			to[v * 2 + 1] = max(to[v * 2 + 1], to[v]);
			to[v] = 0;
			if (t[v * 2].first < to[v * 2]) t[v * 2].first = to[v * 2];
			if (t[v * 2 + 1].first < to[v * 2 + 1]) t[v * 2 + 1].first = to[v * 2 + 1];
		}
	}
}

void update(int v, int l, int r, int x, int tl, int tr) {
	if (tr - 1 < l || tl > r) {
		return;
	}
	if (tr - 1 <= r && tl >= l) {
		push(v, tr - tl == 1);
		to[v] = x;
		if (t[v].first < x) t[v].first = x;
		return;
	}

	push(v, tr - tl == 1);

	int m = (tl + tr) / 2;
	update(v * 2, l, r, x, tl, m);
	update(v * 2 + 1, l, r, x, m, tr);

	t[v] = min(t[v * 2], t[v * 2 + 1]);
}

pair<int, int> get(int v, int l, int r, int tl, int tr) {
	push(v, tr - tl == 1);

	if (tr - 1 < l || tl > r) {
		return{ INF, -1 };
	}
	if (tr - 1 <= r && tl >= l) {
		return t[v];
	}

	int m = (tl + tr) / 2;
	return min(get(v * 2, l, r, tl, m), get(v * 2 + 1, l, r, m, tr));
}

signed main() {
	cin >> n >> m;

	init(1, 1, n + 1);

	for (int i = 0; i < m; ++i) {
		string type;
		cin >> type;
		if (type[0] == 'a') {
			int l, r;
			cin >> l >> r;
			auto p = get(1, l, r, 1, n + 1);
			cout << p.first << " " << p.second << endl;
		}
		else {
			int l, r, x;
			cin >> l >> r >> x;
			update(1, l, r, x, 1, n + 1);
		}
	}
	return 0;
}