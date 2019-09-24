#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

#define int long long

const int MAXN = 1e5 + 5;

int n, a, b, arr[MAXN];
int d[MAXN], w[MAXN];

bool ok(int t) {
	int time = 0;
	for (int i = 0; i < n; ++i) {
		d[arr[i]] = time + a;
		time += a;
		w[i] = t;
		t += b;
	}
	for (int i = 0; i < n; ++i) {
		if (d[i] > w[i]) return 0;
	}
	return 1;
}

signed main() {
	cin >> n >> a >> b;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		--arr[i];
	}
	int l = -1, r = a * n;
	while (r - l > 1) {
		int m = (l + r) / 2;
		if (ok(m)) {
			r = m;
		}
		else l = m;
	}
	cout << r << endl;
	return 0;
}