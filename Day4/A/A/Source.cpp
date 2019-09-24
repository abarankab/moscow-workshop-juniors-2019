#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int MAXN = 1e6 + 5;
const int A = 'Z' - 'A' + 1;

#define int long long

string s;
bool f;
int k, n;
int posmod[A], pw[MAXN];
vector<int> letters, p;
set<int> st;

signed main() {
	cin >> s >> k;
	pw[0] = 1;
	n = s.size();
	for (int i = 1; i <= n; ++i) {
		pw[i] = (pw[i - 1] * 10) % k;
	}
	for (int i = 0; i < n; ++i) {
		posmod[s[i] - 'A'] += pw[n - i - 1];
		posmod[s[i] - 'A'] %= k;
		if (!st.count(s[i] - 'A')) {
			letters.push_back(s[i] - 'A');
			st.insert(s[i] - 'A');
		}
	}
	for (int i = 0; i < 10; ++i) p.push_back(i);
	if (letters.size() <= 10) {
		do {
			if (p[0] != 0 || n == 1) {
				int res = 0;
				for (int i = 0; i < letters.size(); ++i) {
					res += (posmod[letters[i]] * p[i]) % k;
					res %= k;
				}
				if (res == 0) {
					f = 1;
					break;
				}
			}
		} while (next_permutation(p.begin(), p.end()));
	}
	if (f) {
		int id[A];
		for (int i = 0; i < letters.size(); ++i) id[letters[i]] = i;
		for (char c : s) {
			cout << p[id[c - 'A']];
		}
		cout << endl;
	}
	else {
		cout << -1 << endl;
	}
	return 0;
}