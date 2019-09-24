#include <iostream>
#include <map>

using namespace std;

const int MAXN = 1e5 + 5;

struct node {
	int x, res;
	node *l, *r;

	node() {}

	node(int _x) {
		x = _x;
		res = _x;
	}
};

void build(node *v, int tl, int tr) {
	if (tr - tl == 1) {
		v->x = 0;
		v->res = 0;
	}
	int m = (tl + tr) / 2;
	v->l = new node(0);
	v->r = new node(0);
	build(v->l, tl, m);
	build(v->r, m, tr);
}

void upgrade(node *pr, node *cur, int tl, int tr, int i) {
	if (tr - tl == 1) {
		++cur->x;
		cur->res = (cur->x == 1);
		return;
	}
	int m = (tl + tr) / 2;
	if (i < m) {
		cur->r = pr->r;
		upgrade(pr->l, cur->l, tl, m, i);
	}
	else {
		cur->l = pr->l;
		upgrade(pr->r, cur->r, m, tr, i);
	}
	cur->res = cur->l->res + cur->r->res;
}

void add(node *v, int tl, int tr, int i) {
	if (tr - tl == 1) {
		++v->x;
		v->res = (v->x == 1);
		return;
	}
	int m = (tl + tr) / 2;
	if (i < m) add(v->l, tl, m, i);
	else add(v->r, m, tr, i);
	v->res = v->l->res + v->r->res;
}

void remove(node *v, int tl, int tr, int i) {
	if (tr - tl == 1) {
		--v->x;
		v->res = (v->x == 1);
		return;
	}
	int m = (tl + tr) / 2;
	if (i < m) add(v->l, tl, m, i);
	else add(v->r, m, tr, i);
	v->res = v->l->res + v->r->res;
}

int get(node *a, node *b, int tl, int tr) {
	if (a->res - b->res == 0) return -1;
	
}

int n, q, a[MAXN];
char type;
node *root[MAXN];

signed main() {
	cin >> n >> q;
	root[0] = new node(0);
	build(root[0], 1, MAXN + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		root[i] = new node(0);
		upgrade(root[i - 1], root[i], 1, MAXN + 1, a[i]);
	}
	for (int i = 0; i < q; ++i) {
		cin >> type;
		if (type == 'C') {
			int id, x;
			cin >> id >> x;
			remove(root[id], 1, MAXN, a[id]);
			a[id] = x;
			add(root[id], 1, MAXN, a[id]);
		}
		else {
			int l, r;
			cin >> l >> r;

		}
	}
}
