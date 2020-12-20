#include <iostream>
#include <vector>

using namespace std;

// fast disjoint set union
class DSU {
	vector<int> p, sz;
public:
	explicit DSU(int n) : p(n, -1), sz(n, 1) {}
	int find(int x) { // path compression
		return (p[x] == -1 ? x : p[x] = find(p[x]));
	}
	bool unionn(int x, int y) { // union by size
		auto rx{find(x)}, ry{find(y)};
		if (rx == ry) return false;
		if (sz[rx] < sz[ry]) swap(rx, ry);
		p[ry] = rx, sz[rx] += sz[ry];
		return true;
	}
};

void solve() {
	int n, m;
	cin >> n >> m;

	int ans{m};
	DSU dsu{n};
	while (m--) {
		int x, y;
		cin >> x >> y, --x, --y;
		if (x == y) {
			--ans;
			continue;
		}

		if (!dsu.unionn(x, y)) ++ans;
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
