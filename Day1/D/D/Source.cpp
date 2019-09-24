#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <algorithm>
#include <cstring>

#define all(x) x.begin(), x.end()
//#define int long long

using namespace std;

const int MAXN = 1e6 + 5;

int n, m, arr[MAXN], need, one[MAXN], p[MAXN], l, r;
vector<int> now;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;
	memset(one, -1, sizeof(one));

	for (int i = 0; i < n; ++i) {
		char tmp;
		cin >> tmp;
		arr[i] = tmp - '0';
		p[i] = (i == 0) ? (arr[i]) : (arr[i] + p[i - 1]);
	}
	for (int i = 0; i < n; ++i) {
		if (arr[i] == 1) {
			one[i] = i;
			for (int pos : now) one[pos] = i;
			now.clear();
		}
		else now.push_back(i);
	}
	for (int i = 0; i < m; ++i) {
		cin >> need;
		if (p[n - 1] < need) cout << "NO" << "\n";
		else {
			l = -1, r = n - 1;
			while (r - l > 1) {
				int mid = (l + r) / 2;
				if (p[mid] >= need) r = mid;
				else l = mid;
			}
			if (p[r] == need) cout << "1 " << r + 1 << "\n";
			else if (one[0] == -1) cout << "NO" << "\n";
			else {
				if (arr[0] == 1) {
					cout << "2 " << r + 1 << "\n";
				}
				else if (r == 0) {
					if (one[0] != -1) {
						cout << one[0] + 1 << " " << one[0] + 1 << "\n";
					}
					else {
						cout << "NO" << "\n";
					}
				}
				else {
					bool left = 1;
					int shift = one[0], shift2 = one[r] - r;
					if (one[r] == -1) {
						if (r + shift < n) cout << shift + 2 << " " << r + shift + 1 << "\n";
						else cout << "NO" << "\n";
					}
					else {
						if (shift != shift2) {
							if (shift > shift2) left = 0;
							shift = min(shift, shift2);

							if (left) {
								//while (1) {}
								cout << shift + 2 << " " << r + shift + 1 << "\n";
							}
							else {
								//while (1) {}
								cout << shift + 1 << " " << r + shift + 1 << "\n";
							}
						}
						else {
							cout << shift + 1 << " " << r + shift + 1 << "\n";
						}
					}
				}
			}
		}
	}

	return 0;
}
