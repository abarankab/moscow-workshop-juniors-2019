#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

const int MAXN = 5005;
const int MAXM = 55;

int n, k;
vector<int> pos[MAXN];
set<int> has[MAXM];
int nxt[MAXM][MAXN];

signed main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> k;
		pos[i].resize(k);
		for (int j = 0; j < k; ++j) {
			cin >> pos[i][j];
			has[pos[i][j]].insert(i);
		}
	}
	for (int x = 1; x <= 50; ++x) {
		for (int type = 0; type < n; ++type) {
			if (lower_bound(pos[type].begin(), pos[type].end(), x) != pos[type].end()) {
				int p = *lower_bound(pos[type].begin(), pos[type].end(), x);
				nxt[x][type] = p;
			}
			else {
				nxt[x][type] = -1;
			}
		}
	}
	for (int type = 0; type < n; ++type) {
		
	}
}