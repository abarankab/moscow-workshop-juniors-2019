#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#define int unsigned short int
typedef long long ll;

const int MAXN = 5005;
const ll MAXA = 1e18;

int n, k, w, x, y, q;
ll res = MAXA;
int idr, ilr, irr, qq[MAXN];
int a[MAXN];
int dpl[MAXN][MAXN], dpr[MAXN][MAXN], pl[MAXN][MAXN], pr[MAXN][MAXN];

signed main() {
	cin >> n >> k >> w;
	for (int i = 0; i < n; ++i) cin >> a[i + 1];

	for (int i = 0; i <= n + 1; ++i) {
		for (int j = 0; j <= w; ++j) {
			dpl[i][j] = MAXN;
			dpr[i][j] = MAXN;
			pl[i][j] = MAXN;
			pr[i][j] = MAXN;
		}
	}

	dpl[0][0] = 0;

	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= w; ++j) {
			dpl[i][j] = dpl[i - 1][j];
			pl[i][j] = pl[i - 1][j];
			if (j >= a[i] && dpl[i][j] > dpl[i][j - a[i]] + 1) {
				dpl[i][j] = dpl[i][j - a[i]] + 1;
				pl[i][j] = a[i];
			}
		}
	}

	dpr[n + 1][0] = 0;

	for (int i = n; i > 0; --i) {
		for (int j = 0; j <= w; ++j) {
			dpr[i][j] = dpr[i + 1][j];
			pr[i][j] = pr[i + 1][j];
			if (j >= a[i] && dpr[i][j] > dpr[i][j - a[i]] + 1) {
				dpr[i][j] = dpr[i][j - a[i]] + 1;
				pr[i][j] = a[i];
			}
		}
	}

	for (int i = 0; i < k; ++i) { 
		vector<pair<int, int> > l; // TLE fix
		vector<pair<int, int> > r; // TLE fix

		cin >> x >> y >> q;
		qq[i] = q;

		for (int j = 0; j <= w; ++j) {
			if (dpl[q - 1][j] != MAXN) {
				l.push_back({ j, dpl[q - 1][j] });
			}
		}

		for (int j = 0; j <= w; ++j) {
			if (dpr[q + 1][j] != MAXN) {
				r.push_back({ j, dpr[q + 1][j] });
			}
		}

		int ir = r.size() - 1;
		for (int il = 0; il < l.size(); ++il) {
			while (ir - 1 >= 0 && r[ir].first + l[il].first > w) {
				--ir;
			}

			if (l[il].first + r[ir].first == w && (ll)x * (ll)w + (ll)((ll)l[il].second + (ll)r[ir].second) * (ll)y < res) {
				res = (ll)x * (ll)w + (ll)((ll)l[il].second + (ll)r[ir].second) * (ll)y;
				idr = i;
				ilr = l[il].first;
				irr = r[ir].first;
			}
		}
	}

	if (res == MAXA) {
		cout << "0 0\n";
	}
	else {
		if (res < 0) while (1) {}
		cout << res << " " << idr + 1 << endl;
		vector<int> al, ar;
		
		int i = qq[idr] - 1;
		int pn = pl[i][ilr];

		map<int, int> mp;
		for (int i = 1; i <= n; ++i) mp[a[i]] = 0;

		while (pn != MAXN) {
			++mp[pn];
			ilr -= pn;
			if (a[i] != pn) --i;
			pn = pl[i][ilr];
		}
		i = qq[idr] + 1;
		pn = pr[i][irr];
		while (pn != MAXN) {
			++mp[pn];
			irr -= pn;
			if (a[i] != pn) ++i;
			pn = pr[i][irr];
		}

		for (int i = 1; i <= n; ++i) cout << mp[a[i]] << " ";
		cout << endl;
	}

	return 0;
}

/*
3 3 9
2 4 3
0 0 1
0 0 2
0 0 3
*/