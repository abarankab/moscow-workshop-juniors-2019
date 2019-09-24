#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

//#define int long long

//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma unroll


const int INF = 1e9;

const int MAXN = 1000000;

int t, n, k;
int arr[MAXN];
long long pr[MAXN];
multiset<long long> st;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	while (1) {
		st.clear();
		cin >> n >> k;
		if (n == 0 && k == 0) {
			break;
		}

		long long p = 0, res = -INF;
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}
		for (int i = n; i < 2 * n; ++i) {
			arr[i] = arr[i - n];
		}

		int l = 0, r = 0;
		pr[0] = arr[0];
		p = arr[0];
		st.insert(-p);

		while (l < n) {
			while (r - l + 1 < k) {
				++r;
				p += arr[r];
				pr[r] = p;
				st.insert(-p);
			}

			res = max(res, -(*st.begin()) - ((l == 0) ? 0 : pr[l - 1]));
			st.erase(st.find(-pr[l]));

			++l;
		}
		cout << res << "\n";
	}
	return 0;
}