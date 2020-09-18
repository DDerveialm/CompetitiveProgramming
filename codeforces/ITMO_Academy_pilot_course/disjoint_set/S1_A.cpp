#include <iostream>
#include <vector>
#include <string>

using namespace std;

class DS { //disjoint set
public:
	explicit DS(int);
	int getID(int);
	int unionn(int, int);
	void deBug() {
		for (auto& x : set) cout << x << " ";
		cout << endl;
		for (auto& x : sz) cout << x << " ";
		cout << endl;
	}
private:
	vector<int> set, sz;
};

DS::DS(int n) : set(n), sz(n) {
	for (int i{0}; i < n; ++i)
		set[i] = i, sz[i] = 1;
}

int DS::getID(int x) {
	if (x == set[x]) return x;

	auto r{getID(set[x])};
	set[x] = r;
	return r;
}

int DS::unionn(int x, int y) {
	auto rx{getID(x)}, ry{getID(y)};
	if (rx != ry) {
		if (sz[rx] < sz[ry]) swap(rx, ry);
		set[ry] = rx;
		sz[rx] += sz[ry], sz[ry] = 0;
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
		string op{};
		int u, v;
		cin >> op >> u >> v, --u, --v;
		if (op == "union"s)
			ds.unionn(u, v);
		else if (op == "get"s)
			if (ds.getID(u) == ds.getID(v)) cout << "YES" << endl;
			else cout << "NO" << endl;
	}

	return 0;
}
