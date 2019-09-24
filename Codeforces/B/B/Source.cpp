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
	for (int i = 0; i < s.size(); ++i) {
		if (i == 0) now = s[i];
		else {
			if (s[i] != now) t.push_back(now), now = s[i];
		}
	}
	t.push_back(now);
	while (!t.empty()) {
		int minr = t.size();
		char to;
		for (char c = 'a'; c <= 'z'; ++c) {
			vector<int> t2;
			int cnt = 0;
			for (int i : t) t2.push_back(i);
			bool f = 1;
			while (f) {
				f = 0;
				for (int i = 0; i < t2.size(); ++i) {
					if (t2[i] == c) {
						f = 1, t2.erase(t2.begin() + i);
						break;
					}
				}
			}
			f = 1;
			while (f) {
				f = 0;
				for (int i = 0; i < t2.size() - 1; ++i) {
					if (t2[i] == t2[i + 1]) {
						f = 1, t2.erase(t2.begin() + i), cnt += 1;
						break;
					}
				}
			}
			if (minr > cnt) {
				minr = cnt;
				to = c;
			}
		}

		bool f = 1;
		while (f) {
			f = 0;
			for (int i = 0; i < t.size(); ++i) {
				if (t[i] == to) {
					f = 1, t.erase(t.begin() + i), ++res;
					break;
				}
			}
		}
		f = 1;
		while (f) {
			f = 0;
			for (int i = 0; i < t.size() - 1; ++i) {
				if (t[i] == t[i + 1]) {
					f = 1, t.erase(t.begin() + i);
					break;
				}
			}
		}
	}
	cout << res << endl;
	return 0;
}