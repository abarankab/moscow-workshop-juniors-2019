#include <iostream>
#include <algorithm>

using namespace std;

#define int long long

const int MAXN = 2e6 + 5, INF = 1e18;

int n, a, b, arr[MAXN], p[MAXN], p2[MAXN], res = INF;

signed main() {
	cin >> n;
	for (int i = 0; i < 2 * n; ++i) {
		cin >> arr[i];
		p[i] = (i == 0) ? arr[i] : (arr[i] + p[i - 1]);
		if (i % 2 == 0) p2[i] = (i == 0) ? arr[i] : (arr[i] + p2[i - 2]);
		else p2[i] = p2[i - 1];
	}
	for (int i = 1; i < 2 * n; ++i) {
		int upper = i - 1;
		if (upper + 1 > n) break;
		
		int now = (arr[0] + arr[i]) * (arr[0] + p[i - 1] - p[0] + p2[2 * n - 1] - p2[upper + i]);
		res = min(res, now);
	}
	cout << res;
	return 0;
}