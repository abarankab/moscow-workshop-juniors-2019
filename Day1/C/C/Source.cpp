#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <algorithm>

#define all(x) x.begin(), x.end()
#define int long long

using namespace std;

const int MAXN = 1e3 + 5, MAXM = 1e4 + 5, INF = 1e10;

int n, t, res = INF;
pair<int, int> arr[MAXM];
int dp[MAXM][MAXN];

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> t;

	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		arr[i + 1] = { x, y };
	}

	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= t; ++j) {
			dp[i][j] = INF;
		}
	}

	dp[0][t] = 0;

	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= t; ++j) {
			int pegasus = min(arr[i].second, t - j);
			dp[i][j] = min(dp[i][j], dp[i - 1][j + pegasus] + arr[i].second - pegasus);
		}

		for (int j = 0; j <= t; ++j) {
			dp[i][j] = min(dp[i][j], dp[i - 1][j] + arr[i].first);
		}
	}
	

	for (int i = 0; i <= t; ++i) {
		if (dp[n][i] < res) res = dp[n][i];
	}
	cout << res << endl;
	return 0;
}

/*

3 6
3 6
1 8
7 8

*/