#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; ++i)
#define all(c) c.begin(), c.end()
#define int long long

typedef long long ll;
typedef long double ld;

template <typename T> void uax(T &a, T b) { if (a < b) a = b; }
template <typename T> void uin(T &a, T b) { if (a > b) a = b; }

const int MAXN = 1e5 + 5;

vector<int> id[6];

int n, t, res, l, r, arr[MAXN];

int gcd(int a, int b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int cnt = 0;
	while (1) {
		++cnt;
		res = 0;
		cin >> n;
		if (!n) break;

		for (int i = 0; i < 6; ++i) id[i].clear();

		for (int i = 0; i < n; ++i) {
			cin >> t;
			id[t].push_back(i);
		}

		for (int high = 0; high < 6; ++high) {
			for (int low = 0; low < high; ++low) {
				l = -1, r = 0;
				while (r < id[high].size()) {
					while (l + 1 < id[low].size() && id[low][l + 1] < id[high][r]) ++l;
					res += (l + 1) * (high - low) * (high - low);
					++r;
				}
			}
		}

		int x = res * 2, y = n * (n - 1), g;
		g = gcd(x, y);

		x /= g;
		y /= g;

		if (y == 1) {
			cout << "Case #" << cnt << ": The contest badness is " << x << ".\n";
		}
		else {
			cout << "Case #" << cnt << ": The contest badness is " << x << "/" << y << ".\n";
		}
	}

		return 0;
}