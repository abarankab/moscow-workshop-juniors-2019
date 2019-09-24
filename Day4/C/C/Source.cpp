#include <iostream>
#include <algorithm>

using namespace std;

#define int long long

const int MAXN = 1e6 + 5;

int q, p, h, n, pw[MAXN], now;
string res;

signed main() {
	pw[0] = 1;
	for (int i = 1; i < MAXN; ++i) {
		pw[i] = pw[i - 1] * p;
		if (pw[i] > q) pw[i] %= q;
	}
	while (now != h) {
		for (char c = 'a'; c < 'z'; ++c) {
			if (c)
		}
		++n;

	}
}