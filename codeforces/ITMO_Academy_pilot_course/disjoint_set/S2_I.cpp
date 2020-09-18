#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Info { int set, sz, pt; };

class DS { //disjoint set
public:
	explicit DS(int);
	int getID(int);
	int unionn(int, int);
	bool check(int, int);
private:
	vector<Info> v;
};

DS::DS(int n) : v(n) {
	for (int i{0}; i < n; ++i)
		v[i] = {i, 1, 0};
}

int DS::getID(int x) {
	if (x == v[x].set) return x;

	auto rx{getID(v[x].set)};
	if (v[x].set != rx) {
		v[x].pt ^= v[ v[x].set ].pt;
		v[x].set = rx;
	}
	return rx;
}

int DS::unionn(int x, int y) {
	auto rx{getID(x)}, ry{getID(y)};
	if (rx != ry) {
		if (v[rx].sz < v[ry].sz) swap(rx, ry);
		v[ry].set = rx;
		v[rx].sz += v[ry].sz, v[ry].sz = 0;
		v[ry].pt = v[x].pt ^ v[y].pt ^ 1;
	}
	return rx;
}

bool DS::check(int x, int y) {
	getID(x), getID(y);
	if (v[x].pt == v[y].pt) return true;
	else return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	DS ds{n};
	int shift{0};
	while (m--) {
		int op, u, v;
		cin >> op >> u >> v, --u, --v;
		if (op == 0) {
			ds.unionn((u + shift) % n, (v + shift) % n);
		} else if (op == 1) {
			if (ds.check((u + shift) % n, (v + shift) % n)) shift = (shift + 1) % n, cout << "YES\n";
			else cout << "NO\n";
		}
	}

	return 0;
}
