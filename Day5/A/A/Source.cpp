#include <iostream>
#include <algorithm>

using namespace std;

struct point {
	int x, y;

	point() {}

	point(int _x, int _y) {
		x = _x, y = _y;
	}

	bool zero() {
		return x == 0 &&  y == 0;
	}
};

istream& operator >> (istream &is, point &p) {
	is >> p.x >> p.y;
	return is;
}

ostream& operator << (ostream &os, point &p) {
	os << p.x << " " << p.y;
	return os;
}

point operator-(point a, point b) {
	return point(a.x - b.x, a.y - b.y);
}

point a, b, c, d;

signed main() {
	while (1) {
		bool v1, v2;
		cin >> a >> b >> c >> d;
		if (a.zero() && b.zero() && c.zero() && d.zero()) {
			break;
		}
		v1 = (b - a).x == 0;
		v2 = (c - d).x == 0;

		if (!v1 && v2) {
			swap(a, c);
			swap(b, d);
			swap(v1, v2);
		}

		if (v1 && !v2) {
			if (d.x < c.x) swap(d, c);
			if (b.y < a.y) swap(a, b);
			if (a.x <= d.x && a.x >= c.x && c.y <= b.y && c.y >= a.y) {
				cout << "1 " << a.x << " " << c.y << "\n";
			}
			else cout << "0\n";
		}
		else if (v1 && v2) {
			if (b.y < a.y) swap(a, b);
			if (d.y < c.y) swap(c, d);
			if (a.y > c.y) {
				swap(a, c);
				swap(b, d);
			}

			if (a.x == c.x && b.y >= c.y) {
				point n = c, m = point(b.x, min(b.y, d.y));
				if (n.x != m.x || n.y != m.y) {
					cout << 2 << " " << n << " " << m << "\n";
				}
				else {
					cout << 1 << " " << n << "\n";
				}
			}
			else cout << "0\n";
		}
		else if (!v1 && !v2) {
			if (b.x < a.x) swap(a, b);
			if (d.x < c.x) swap(c, d);
			if (a.x > c.x) {
				swap(a, c);
				swap(b, d);
			}

			if (a.y == c.y && b.x >= c.x) {
				point n = c, m = point(min(b.x, d.x), b.y);
				if (n.x != m.x || n.y != m.y) {
					cout << 2 << " " << n << " " << m << "\n";
				}
				else {
					cout << 1 << " " << n << "\n";
				}
			}
			else cout << "0\n";
		}
	}
	return 0;
}