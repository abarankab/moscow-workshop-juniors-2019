#include <iostream>
#include <random>
#include <vector>
#include <set>
#include <map>
#include <string>

using namespace std;

template <typename T> void uax(T &a, T b) {
	if (a < b) a = b;
}

template <typename T> void uin(T &a, T b) {
	if (a > b) a = b;
}

const int MAXN = 2002;

int n, m;
int a[MAXN][MAXN], p[MAXN][MAXN], c00[MAXN][MAXN], c01[MAXN][MAXN], c10[MAXN][MAXN], c11[MAXN][MAXN], h0[MAXN][MAXN], h1[MAXN][MAXN], v0[MAXN][MAXN], v1[MAXN][MAXN];

int mod(int a) {
	return (a + (int)1e9) % 10;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			char tmp;
			cin >> tmp;
			a[i][j] = tmp - '0';
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			p[i][j] = mod(a[i][j] + p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1]);
			c00[i][j] = mod(a[i][j] * i * j + c00[i - 1][j] + c00[i][j - 1] - c00[i - 1][j - 1]);
			v0[i][j] = mod(a[i][j] * i + v0[i - 1][j] + v0[i][j - 1] - v0[i - 1][j - 1]);
			h0[i][j] = mod(a[i][j] * j + h0[i - 1][j] + h0[i][j - 1] - h0[i - 1][j - 1]);
		}
	}
	for (int i = n; i > 0; --i) {
		for (int j = 1; j <= m; ++j) {
			c10[i][j] = mod(a[i][j] * (n - i + 1) * j + c10[i + 1][j] + c10[i][j - 1] - c10[i + 1][j - 1]);
			v1[i][j] = mod(a[i][j] * (n - i + 1) + v1[i + 1][j] + v1[i][j - 1] - v1[i + 1][j - 1]);
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = m; j > 0; --j) {
			c01[i][j] = mod(a[i][j] * i * (m - j + 1) + c01[i - 1][j] + c01[i][j + 1] - c01[i - 1][j + 1]);
			h1[i][j] = mod(a[i][j] * (m - j + 1) + h1[i - 1][j] + h1[i][j + 1] - h1[i - 1][j + 1]);
		}
	}
	for (int i = n; i > 0; --i) {
		for (int j = m; j > 0; --j) {
			c11[i][j] = mod(a[i][j] * (n - i + 1) * (m - j + 1) + c11[i + 1][j] + c11[i][j + 1] - c11[i + 1][j + 1]);
		}
	}

	cout << endl;

	for (int w = 0; w < n; ++w) {
		for (int h = 0; h < m; ++h) {
			int res = 0;
			res += mod((w + 1) * (h + 1) * mod(p[n - w][m - h] - p[n - w][h] - p[w][m - h] + p[w][h]));

			res += c00[w][h];
			res += c10[n - w + 1][h];
			res += c01[w][m - h + 1];
			res += c11[n - w + 1][m - h + 1];

			res = mod(res);

			/*
			res += w * (p[n - w][h] - p[w][h] + v0[n - w][h] - v0[w][h]);
			res += w * (p[n - w][m] - p[n - w][m - h] - p[w][m] + p[w][m - h] + v1[n - w][m] - v1[n - w][m - h] - v1[w][m] + v1[w][m - h]);

			res += h * (p[w][m - h] - p[w][h] + h0[w][m - h] - h0[w][h]);
			res += h * (p[n][m - h] - p[n - w][m - h] - p[n][h] + p[n - w][h]);
			*/

			res += (h + 1) * mod(v0[w][m - h] - v0[w][h]);
			res += (h + 1) * mod(v1[n - w + 1][m - h] - v1[n - w + 1][h]);

			res += (w + 1) * mod(h0[n - w][h] - h0[w][h]);
			res += (w + 1) * mod(h1[n - w][m - h + 1] - h1[w][m - h + 1]);

			cout << mod(res);
		}
		cout << endl;
	}
	return 0;
}