#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Info { int set, sz; };

class DS { //disjoint set
public:
	explicit DS(int);
	int getID(int);
	int unionn(int, int);
	int getAns(int);
private:
	vector<Info> v;
};

DS::DS(int n) : v(n) {
	for (int i{0}; i < n; ++i)
		v[i] = {i, 1};
}

int DS::getID(int x) {
	if (x == v[x].set) return x;

	auto rx{getID(v[x].set)};
	v[x].set = rx;
	return rx;
}

int DS::unionn(int x, int y) {
	auto rx{getID(x)}, ry{getID(y)};
	if (rx != ry) {
		if (v[rx].sz < v[ry].sz) swap(rx, ry);
		v[ry].set = rx;
		v[rx].sz += v[ry].sz, v[ry].sz = 0;
	}
	return rx;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	DS ds{n};
	while (m--) {
		int t, x, y;
		cin >> t >> x >> y, --x, --y;
		if (t == 1) {
			ds.unionn(x, y);
		} else if (t == 2) {
			for (int i{x}; i < y; ++i)
				ds.unionn(i, i + 1);
		} else if (t == 3) {
			if (ds.getID(x) == ds.getID(y)) cout << "YES\n";
			else cout << "NO\n";
		}
	}

	return 0;
}
