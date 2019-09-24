#include <iostream>
#include <vector>
#include <set>
#include <cstring>

using namespace std;

#define int long long

const int MAXN = 105, INF = 1e18;

int h, w, a[MAXN][MAXN], d[MAXN * MAXN];
vector<pair<int, int> > g[MAXN * MAXN];

signed main() {
	while (1) {
		memset(a, 0, sizeof(a));
		set<pair<int, int> > st;
		for (int i = 0; i < MAXN * MAXN; ++i) g[i].clear(), d[i] = INF, st.insert({ INF, i });

		cin >> h >> w;
		if (h == 0 && w == 0) break;

		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				cin >> a[h - i - 1][j];
			}
		}
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				for (int ni = i + 1; ni < h - 1; ++ni) {
					if (a[ni + 1][j] > 0) {
						g[i * w + j].push_back({ ni * w + j, a[ni + 1][j] });
					}
				}
				for (int nj = j; nj < w - 1; ++nj) {
					if (a[i][nj + 1] > 0) {
						g[i * w + j].push_back({ i * w + nj, a[i][nj + 1] });
					}
				}
			}
		}

		d[0] = 0;
		st.erase({ INF, 0 });
		st.insert({ 0, 0 });

		while (!st.empty()) {
			if ((*st.begin()).first == INF) break;

			int v = (*st.begin()).second;
			st.erase(st.begin());
			for (auto p : g[v]) {
				int u = p.first;
				int l = p.second;
				if (d[u] > d[v] + l) {
					st.erase({ d[u], u });
					d[u] = d[v] + l;
					st.insert({ d[u], u });
				}
			}
		}

		if (d[(h - 2) * w + (w - 2)] == INF) {
			cout << "Mission impossible" << endl;
		}
		else {
			cout << d[(h - 2) * w + (w - 2)] << endl;
		}
	}

	return 0;
}