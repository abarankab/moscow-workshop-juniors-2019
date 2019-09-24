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
#define dec dec228

typedef long long ll;
typedef long double ld;

template <typename T> void uax(T &a, T b) { if (a < b) a = b; }
template <typename T> void uin(T &a, T b) { if (a > b) a = b; }

const int MAXN = 1e6 + 5;

int now, res, n, cnt1, cnt2, cnt3;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		if (i == 0) ++cnt1;
		else {
			if (i % 2 == 0) {
				cnt3 += (i / 2) - 1;
				cnt2 += 2;
			}
			else {
				cnt3 += (i + 1) / 2 - 1;
				cnt2 += 1;
			}
		}
		if ((n - 1 - i) % 2 == 1) {
			cnt3 += (n - 1 - i) / 2;
			cnt2 += 1;
		}
		else {
			cnt3 += (n - 1 - i) / 2;
		}

		int q = n - i;
		if (i - q - 2 >= 0 && (i - q - 2) % 2 == 0) {
			--cnt3;
		}
		if (i != 0 && (i * 2) % n == 0) --cnt2;
	}

	cout << cnt3 * 6 + cnt2 * 3 + cnt1;

	return 0;
}