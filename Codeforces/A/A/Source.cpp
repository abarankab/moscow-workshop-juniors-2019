#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cstring>

using namespace std;

#define int long long

const int MAXN = 2e5 + 5;

int n, res;
string s;
char now = '$';
vector<int> t;

signed main() {
	cin >> n >> s;
	for (int i = 0; i < n; ++i) {
		if (i == 0) now = s[i];
		else {
			if (s[i] != now) t.push_back(now), now = s[i];
		}
	}
	t.push_back(now);
	while (!t.empty()) {
		bool f = 0;
		int cnt[50];
		++res;

		for (int i = 1; i < t.size() - 1; ++i) {
			if (t[i - 1] = t[i + 1]) {
				
			}
		}

		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < t.size(); ++i) {
			++cnt[t[i] - 'a'];
		}
		int maxr = 1000, to;
		for (int i = 0; i < 50; ++i) {
			if (cnt[i] && cnt[i] < maxr) {
				maxr = cnt[i];
				to = i + 'a';
			}
		}
		for (int i = 0; i < t.size(); ++i) {
			if (t[i] == to) {
				t.erase(t.begin() + i);
				break;
			}
		}

		for (int i = 0; i < (int)t.size() - 1; ++i) {
			if (t[i] == t[i + 1]) {
				t.erase(t.begin() + i);
			}
		}
	}
	cout << res << endl;
	return 0;
}