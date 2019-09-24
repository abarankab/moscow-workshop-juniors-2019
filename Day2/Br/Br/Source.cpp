#include <iostream>
#include <random>

using namespace std;

const int MAXN = 1e5 + 5;
mt19937_64 mersenne;
int all;

struct node {
	int pos, cnt, id, l, r;
	long long key;

	node() {}

	node(int _id) {
		pos = all;
		++all;
		id = _id;
		cnt = 1;
		key = mersenne();
		l = -1;
		r = -1;
	}
};

node tt[MAXN];

int get(int tid) {
	return (tid == -1) ? 0 : tt[tid].cnt;
}

void push(int tid) {
	if (tid == -1) return;
	tt[tid].cnt = 1 + get(tt[tid].l) + get(tt[tid].r);
}

pair<int, int> split(int tid, int id) {
	if (tid == -1) return{ -1, -1 };
	push(tid);
	if (id <= tt[tid].id) {
		auto p = split(tt[tid].l, id);
		tt[tid].l = p.second;
		push(tid);
		push(p.first);
		return{ p.first, tid };
	}
	else {
		auto p = split(tt[tid].r, id);
		tt[tid].r = p.first;
		push(tid);
		push(p.second);
		return{ tid, p.second };
	}
}

int merge(int t1, int t2) {
	if (t2 == -1) return t1;
	if (t1 == -1) return t2;

	push(t1);
	push(t2);

	if (tt[t1].key > tt[t2].key) {
		tt[t1].r = merge(tt[t1].r, t2);
		push(t1);
		return t1;
	}
	else {
		tt[t2].l = merge(t1, tt[t2].r);
		push(t2);
		return t2;
	}
}

int add(int tid, int id) {
	auto p = split(tid, id);
	node nw = node(id);
	tt[nw.pos] = nw;
	return merge(merge(p.first, nw.pos), p.second);
}

int n, m, l, r;
int dd[10];
int sp[10][3], sp2[10][3];

signed main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		char now;
		cin >> now;
		now -= '0';
		dd[now] = add(dd[now], i + 1);
	}
	for (int i = 0; i < m; ++i) {
		cin >> l >> r;
		int res = 0;
		for (int i = 0; i < 10; ++i) {
			auto p = split(dd[i], l);
			sp[i][0] = p.first;
			sp2[i][0] = p.first;
			auto p2 = split(p.second, r + 1);
			sp[i][1] = p2.first;
			sp[i][2] = p2.second;
			sp2[i][1] = p2.first;
			sp2[i][2] = p2.second;
			res += get(sp[i][1]) * i;
		}
		for (int i = 0; i < 10; ++i) {
			sp[i][1] = sp2[(i + 9) % 10][1];
		}
		for (int i = 0; i < 10; ++i) {
			dd[i] = merge(merge(sp[i][0], sp[i][1]), sp[i][2]);
		}
		cout << res << "\n";
	}
	return 0;
}