#include <iostream>

using namespace std;

#define int long long

const int MAXN = 1005;
const int MOD = 1e9 + 7;

int n, pw[MAXN * MAXN], dp[MAXN], c[MAXN][MAXN];

signed main() {
	pw[0] = 1;
	dp[2] = 1;
	dp[0] = 1;
	c[0][0] = 1;
	for (int i = 1; i < MAXN * MAXN; ++i) {
		pw[i] = pw[i - 1] * 2;
		if (pw[i] > MOD) pw[i] %= MOD;
		if (pw[i] < 0) pw[i] += MOD;
	}

	for (int i = 1; i < MAXN; ++i) {
		for (int j = 0; j < MAXN; ++j) {
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
		}
	}

	cin >> n;
	for (int i = 3; i <= n; ++i) {
		dp[i] = pw[i * (i - 1) / 2];
		for (int j = 1; j <= i; ++j) {
			dp[i] -= (c[i][j] * dp[i - j]) % MOD;
			if (dp[i] < 0) dp[i] += MOD;
		}
		dp[i] %= MOD;
	}

	cout << dp[n];
	return 0;
}

//536023191