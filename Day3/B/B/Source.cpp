#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, l, f;
bool closed, found;
vector<pair<int, int> > ban;
string s;

string solve() {
	n = s.size();
	for (int i = 0; i < n; ++i) {
		if (s[i] == '(' && found && closed) {
			ban.push_back({ f, l });
			f = i;
			closed = 0;
		}
		else if (s[i] == '(' && !found) {
			f = i;
			found = 1;
		}
		else if (s[i] == ')') {
			l = i;
			closed = 1;
		}
	}
	if (found) ban.push_back({ f, l });
	for (auto p : ban) {
		for (int i = p.first; i <= p.second; ++i) s[i] = '*';
	}
	return s;
}

signed main() {
	cin >> s;
	cout << solve() << endl;
	return 0;
}
