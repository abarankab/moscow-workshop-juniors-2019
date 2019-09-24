#include <iostream>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 1005;

int n, k, type[MAXN][MAXN], pos[MAXN][MAXN], can[MAXN];

/*
struct fw {
	int q, t[MAXN];

	fw() {}

	int get(int p) {
		int res = 0;
		for (; p >= 0; p = (p & (p + 1)) - 1) {
			res += t[p];
		}
		return res;
	}
	
	void inc(int p) {
		for (; p < q; p = (p | (p + 1))) {
			++t[p];
		}
	}
};

fw f[MAXN];
*/

signed main() {
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= k; ++j) {
			cin >> type[i][j];
			pos[i][type[i][j]] = j;
		}
		//f[i].q = k + 2;
	}
	
	/*can[0] = 1;
	for (int i = 0; i < n; ++i) {
		f[i].inc(pos[i][0]);
	}*/
	int last = 0;

	for (int i = k; i > 0; --i) {
		int cnt = 0;
		for (int j = 0; j < n; ++j) {
			//if (!f[j].get(pos[j][i])) ++cnt;
			if (pos[j][i] < pos[j][last]) ++cnt;
		}
		if (cnt > n / 2) {
			last = i;
			/*can[i] = 1;
			for (int j = 0; j < n; ++j) {
				f[j].inc(pos[j][i]);
			}*/
		}
	}

	if (last == 0) {
		cout << "Nothing" << endl;
	}
	else cout << last << endl;

	/*
	bool flag = 0;
	for (int i = 1; i <= k; ++i) {
		if (can[i]) {
			cout << i << endl;
			flag = 1;
			break;
		}
	}
	if (!flag) cout << "Nothing" << endl;
	*/
	return 0;
}