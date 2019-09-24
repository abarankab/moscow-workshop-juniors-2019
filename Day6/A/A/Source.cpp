#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int t, n, x;
int dp[55][55][2], a[55];

signed main() {
	cin >> t;
	for (; t > 0; --t) {
		cin >> n;
		memset(a, 0, sizeof(a));
		memset(dp, 0, sizeof(dp));

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) dp[i][j][0] = INF, dp[i][j][1] = INF;
		}
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		sort(a, a + n);
		cin >> x;

		for (int i = 0; i < n; ++i) {
			a[i] -= x;
			dp[i][i][0] = (n + 1) * abs(a[i]) + 1;
			dp[i][i][1] = (n + 1) * abs(a[i]) + 1;
		}

		for (int len = 2; len <= n; ++len) {
			for (int i = 0; i + len <= n; ++i) {
				int j = i + len - 1;
				dp[i][j][0] = min(
					dp[i + 1][j][0] + (a[i + 1] - a[i]) * (n - len + 2),
					dp[i + 1][j][1] + (a[j] - a[i]) * (n - len + 2)
					) + 1;

				dp[i][j][1] = min(
					dp[i][j - 1][1] + (a[j] - a[j - 1]) * (n - len + 2),
					dp[i][j - 1][0] + (a[j] - a[i]) * (n - len + 2)
					) + 1;
			}
		}
		cout << min(dp[0][n - 1][0], dp[0][n - 1][1]) << endl;
	}
	return 0;
}