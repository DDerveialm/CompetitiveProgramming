#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>

using namespace std;

// fast disjoint set union
class DSU {
public:
    vector<int> p, sz, ck;
    explicit DSU(int n) : p(n, -1), sz(n, 1), ck(n, false) {}
    int find(int x) { // path compression
        return (p[x] == -1 ? x : p[x] = find(p[x]));
    }
    void unionn(int x, int y) { // union by size
        auto rx{find(x)}, ry{find(y)};
        if (rx == ry) return ;
        if (sz[rx] < sz[ry]) swap(rx, ry);
        p[ry] = rx, sz[rx] += sz[ry], ck[rx] |= ck[ry];
    }
};

// Kruskal¡¦s algorithm
class graph {
public:
    int n;
    vector<tuple<int, int, int>> edges{};
    vector<tuple<int, int, int>> mst{};
    int Kruskal() {
        int weight{0};
        DSU dsu{n};
        sort(edges.begin(), edges.end());
        for (auto& [w, u, v] : edges)
            if (dsu.find(u) != dsu.find(v))
                dsu.unionn(u, v), mst.emplace_back(w, u, v), weight += w;
        return weight;
    }
};

void solve() {
	int n, m;
	cin >> n >> m;

	graph gph{m + 1};

	for (int i{1}; i <= n; ++i) {
		int k, x1, x2{m};

		cin >> k >> x1, --x1;
		if (k == 2) cin >> x2, --x2;

		gph.edges.emplace_back(i, x1, x2);
	}

	gph.Kruskal();

	int T{1};
	for (int i{0}; i < gph.mst.size(); ++i)
		T *= 2, T %= (static_cast<int>(1e9) + 7);
	
	cout << T << ' ' << gph.mst.size() << '\n';
	for (auto& [w, u, v] : gph.mst) cout << w << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	// cin >> t;
	while (t--) solve();

	return 0;
}
