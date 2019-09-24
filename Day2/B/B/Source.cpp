#include <iostream>
#include <random>
#include <time.h>

using namespace std;

mt19937 mersenne(time(0));

struct node {
	int cnt, id;
	int key;
	node *l, *r;

	node() {}

	node(int _id) {
		id = _id;
		cnt = 1;
		key = mersenne();
		l = NULL;
		r = NULL;
	}
};

int get(node *t) {
	return !t ? 0 : t->cnt;
}

void push(node *t) {
	if (!t) return;
	t->cnt = 1 + get(t->l) + get(t->r);
}

pair<node*, node*> split(node *t, int id) {
	if (!t) return{ NULL, NULL };
	if (id <= t->id) {
		auto p = split(t->l, id);
		t->l = p.second;
		push(t);
		push(p.first);
		return{ p.first, t };
	}
	else {
		auto p = split(t->r, id);
		t->r = p.first;
		push(t);
		push(p.second);
		return{ t, p.second };
	}
}

node* merge(node *t1, node *t2) {
	if (!t2) return t1;
	if (!t1) return t2;

	if (t1->key > t2->key) {
		t1->r = merge(t1->r, t2);
		push(t1);
		return t1;
	}
	else {
		t2->l = merge(t1, t2->l);
		push(t2);
		return t2;
	}
}

node* add(node *t, int id) {
	pair<node*, node*> p = split(t, id);
	return merge(merge(p.first, new node(id)), p.second);
}

int n, m, l, r;
node *dd[10];
node *sp[10][3], *sp2[10];

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
	for (int q = 0; q < m; ++q) {
		cin >> l >> r;
		int res = 0;
		for (int i = 0; i < 10; ++i) {
			auto p = split(dd[i], l);
			sp[i][0] = p.first;
			auto p2 = split(p.second, r + 1);
			sp[i][1] = p2.first;
			sp[i][2] = p2.second;
			sp2[i] = p2.first;
			res += get(sp[i][1]) * i;
		}
		for (int i = 0; i < 10; ++i) {
			if (i == 0) {
				sp[i][1] = sp2[9];
			}
			else {
				sp[i][1] = sp2[i - 1];
			}
		}
		for (int i = 0; i < 10; ++i) {
			dd[i] = merge(merge(sp[i][0], sp[i][1]), sp[i][2]);
		}
		cout << res << "\n";
	}
	return 0;
}