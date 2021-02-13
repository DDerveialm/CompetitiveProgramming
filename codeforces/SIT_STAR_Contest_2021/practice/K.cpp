#include <iostream>
#include <vector>
#include <tuple>
#include <stack>
#include <algorithm>

using namespace std;

// SCC
// Kosaraju's algorithm
class graph {
public:
    int n;
    vector<vector<int>> adj;
    vector<vector<int>> rvs; // reverse graph
    vector<bool> vis;
    stack<int> s{};
    vector<int> component{};
    vector<vector<int>> SCC{};
    explicit graph(int _n) : n{_n}, adj(n), rvs(n), vis(n) {}
    void add_edge(int u, int v) {
        adj[u].push_back(v);
        rvs[v].push_back(u);
    }
    void dfs1(int u) {
        vis[u] = true;
        for (auto& v : rvs[u])
            if (!vis[v]) dfs1(v);
        s.push(u);
    }
    void dfs2(int u) {
        vis[u] = true;
        component.push_back(u);
        for (auto& v : adj[u])
            if (!vis[v]) dfs2(v);
    }
    void kosaraju() {
        // find the order on reverse graph
        for (int u{0}; u < n; ++u)
            if (!vis[u]) dfs1(u);

        // find SCC on reverse order
        fill(vis.begin(), vis.end(), false);
        while (!s.empty()) {
            auto u{s.top()}; s.pop();
            if (!vis[u]) {
                dfs2(u);
                SCC.push_back(move(component));
            }
        }
    }
};

void mod_(long long& x) {
	x %= 998244353;
}

/* Iterative Function to calculate (x^y) % P in O(log y) */
long long power(long long x, long long y) {
    long long ret{1};
    while (y > 0) {
        if (y & 1) mod_(ret *= x); 
        y >>= 1; 
        mod_(x *= x);
    }
    return ret; 
}

template <typename T>
T sq(T x) {
	return x * x;
}

void solve() {
	int n;
	cin >> n;
	vector<tuple<int, int, int>> vt(n);
	for (auto& [x, y, p] : vt) cin >> x >> y >> p;

	graph gph{n};
	for (int u{0}; u < n; ++u)
		for (int v{0}; v < n; ++v) {
			if (v == u) continue;
			auto& [x1, y1, p]{vt[u]};
			auto& [x2, y2, _]{vt[v]};
			if (sq(p) >= sq(x1 - x2) + sq(y1 - y2)) gph.add_edge(u, v);
		}

	gph.kosaraju();

	vector<bool> in(gph.SCC.size(), false);

	vector<int> wh(n); // which SCC each vertex belongs to
	for (size_t i{0}; i < gph.SCC.size(); ++i) {
		for (auto& x : gph.SCC[i]) wh[x] = i;
	}
	for (int u{0}; u < n; ++u) { // check if there is an incoming edge from another SCC
		for (auto& v : gph.adj[u])
			if (wh[u] != wh[v]) in[wh[v]] = true;
	}

	long long ans{1};
	for (size_t i{0}; i < gph.SCC.size(); ++i) {
		mod_(ans *= (power(2, gph.SCC[i].size()) - !in[i]));
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	// cin >> t;
	while (t--) solve();

	return 0;
}
