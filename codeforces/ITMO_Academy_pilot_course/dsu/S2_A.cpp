#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Info { int set, sz, ans; };

class DS { //disjoint set
public:
	explicit DS(int);
	int getID(int);
	int unionn(int, int);
	int getAns(int);
private:
	vector<Info> v;
};

DS::DS(int n) : v(n + 1) {
	for (int i{0}; i < n + 1; ++i)
		v[i] = {i, 1, i};
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
		v[rx].ans = max(v[rx].ans, v[ry].ans), v[ry].ans = 0;
	}
	return rx;
}

int DS::getAns(int x) {
	return v[getID(x)].ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	DS ds{n};
	while (m--) {
		string op{};
		int p;
		cin >> op >> p, --p;
		if (op == "-"s)
			ds.unionn(p + 1, p);
		else if (op == "?"s)
			if (ds.getAns(p) != n) cout << ds.getAns(p) + 1 << '\n';
			else cout << -1 << '\n';
	}

	return 0;
}
