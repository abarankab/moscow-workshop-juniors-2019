#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <math.h>

using namespace std;

//#define int long long

#pragma unroll
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

const int MAXN = 1e5 + 5;

int n, r;
vector<pair<int, int> > pyth;
vector<pair<int, int> > points;
set<pair<int, int> > st; 

void add(int a, int b) {
	set<pair<int, int> > to;
	to.insert({ -a, b });
	to.insert({ -a, -b });
	to.insert({ a, -b });
	to.insert({ a, b });
	swap(a, b);
	to.insert({ -a, b });
	to.insert({ -a, -b });
	to.insert({ a, -b });
	to.insert({ a, b });
	for (pair<int, int> p : to) pyth.push_back(p);
}

signed main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (1) {
		cin >> n >> r;
		if (n == 0 && r == 0) return 0;
		pyth.clear();
		points.clear();
		st.clear();
		for (int i = 0; i < n; ++i) {
			int x, y;
			cin >> x >> y;
			st.insert({ x, y });
			points.push_back({ x, y });
		}

		int a = 0, b = sqrt(r);

		if (b * b == r) {
			add(a, b);
		}

		b += 1;

		while (a <= b) {
			++a;
			while (b * b + a * a > r) --b;
			if (b * b + a * a == r && a <= b) add(a, b);
		}

		for (pair<int, int> p : points) {
			int res = 0;
			for (pair<int, int> d : pyth) {
				if (st.count({ p.first + d.first, p.second + d.second })) ++res;
			}
			cout << res << " ";
		}

		cout << endl;
	}
	return 0;
}