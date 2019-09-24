#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1e5 + 5;

bool can[MAXN][31][2];
bool op[MAXN][31][2]; // (1 -- ^) (0 -- |)

int x, y, n, a;
vector<int> now, nxt;


signed main() {
	cin >> n >> y;
	now.push_back(0);
	for (int i = 0; i < n; ++i) {
		cin >> a;
		for (int x : now) {
			nxt.push_back(x ^ now);
		}
	}
}