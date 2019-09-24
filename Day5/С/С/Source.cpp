#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#define int long long

const int MAXN = 3000;

int n, k, a[MAXN], dp[MAXN][MAXN];
vector<pair<int, int> > g[MAXN];
vector<int> from[MAXN];

void dfs(int v, int pr = -1) {
	multiset<pair<int, int> > st;

	for (auto p : g[v]) {
		int u = p.first;
		int mx = p.second;

		if (u != pr) {
			dfs(u, v);
			for (int take = 1; take <= k; ++take) {
				//if (take > 1 && dp[u][take] - dp[u][take - 1] > dp[u][take - 1] - dp[u][take - 2]) while (1) {}
				st.insert({ min(dp[u][take - 1], mx) - min(dp[u][take], mx), u });
			}
		}
	}

	st.insert({ -a[v], v });
	int take = 0, got = 0;
	while (!st.empty() && take < k)
	{
		got -= (*st.begin()).first;
		from[v].push_back((*st.begin()).second);
		++take;
		st.erase(st.begin());
		dp[v][take] = got;
	}
	reverse(from[v].begin(), from[v].end());
}

int get(int v) {
	if (from[v].back() == v) {
		from[v].pop_back();
		return v;
	}
	else {
		int res = get(from[v].back());
		from[v].pop_back();
		return res;
	}
}

signed main() {
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n - 1; ++i) {
		int u, v, c;
		cin >> u >> v >> c;
		--u, --v;
		g[u].push_back({ v, c });
		g[v].push_back({ u, c });
	}
	dfs(0);

	int ak, maxr = -1;

	for (int i = 0; i <= k; ++i) {
		if (dp[0][i] > maxr) {
			maxr = dp[0][i];
			ak = i;
		}
	}

	cout << maxr << endl << ak << endl;
	for (int i = 0; i < ak; ++i) cout << get(0) + 1 << " ";
	return 0;
}