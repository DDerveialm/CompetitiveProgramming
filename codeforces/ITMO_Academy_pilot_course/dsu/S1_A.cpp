#include <iostream>
#include <vector>
#include <string>

using namespace std;

// fast disjoint set union
class DSU {
	vector<int> p, sz;
public:
	explicit DSU(int n) : p(n, -1), sz(n, 1) {}
	int find(int x) { // path compression
		if (p[x] == -1) return x;
		return p[x] = find(p[x]);
	}
	void unionn(int x, int y) { // union by size
		auto rx{find(x)}, ry{find(y)};
		if (rx == ry) return ;
		if (sz[rx] < sz[ry]) swap(rx, ry);
		p[ry] = rx, sz[rx] += sz[ry];
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	DSU dsu{n};
	while (m--) {
		string op{};
		int u, v;
		cin >> op >> u >> v, --u, --v;
		if (op == "union"s) {
			dsu.unionn(u, v);
		} else if (op == "get"s) {
			if (dsu.find(u) == dsu.find(v)) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}

	return 0;
}
