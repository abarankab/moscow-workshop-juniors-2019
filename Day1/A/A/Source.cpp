#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

const int MAXN = 105;

int n, m;
int arr[MAXN][MAXN];
set<int> rep[MAXN];
set<int> now;

signed main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		now.clear();
		for (int j = 0; j < m; ++j) {
			cin >> arr[i][j];
			if (now.count(arr[i][j])) rep[i].insert(arr[i][j]);
			now.insert(arr[i][j]);
		}
	}

	for (int col = 1; col < min(n, m); ++col) {
		int cnt = 0;
		vector<int> pos;
		for (int row = 0; row < n; ++row) {
			if (rep[row].count(col)) ++cnt, pos.push_back(row);
			if (cnt >= 2) break;
		}
		if (cnt >= 2) {
			vector<int> x;
			for (int i = 0; i < m; ++i) {
				if (arr[pos[0]][i] == col) x.push_back(i);
				if (x.size() >= 2) break;
			}
			cout << 2 + m << endl;
			cout << "H " << pos[0] + 1 << " " << x[0] + 1 << " " << pos[0] + 1 << " " << x[1] + 1 << endl;
			x.clear();
			for (int i = 0; i < m; ++i) {
				if (arr[pos[1]][i] == col) x.push_back(i);
				if (x.size() >= 2) break;
			}
			cout << "H " << pos[1] + 1 << " " << x[0] + 1 << " " << pos[1] + 1 << " " << x[1] + 1 << endl;
			for (int col = 0; col < m; ++col) {
				cout << "V " << pos[0] + 1 << " " << col + 1 << " " << pos[1] + 1 << " " << col + 1 << endl;
			}
			break;
		}
	}

	return 0;
}