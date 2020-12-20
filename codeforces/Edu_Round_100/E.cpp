#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <queue>

using namespace std;
class DSU {
	vector<int> p, sz;
	vector<list<int>> c;
public:
	explicit DSU(int n) : p(n, -1), sz(n, 1), c(n) {
		for (int i{0}; i < n; ++i) c[i].push_back(i);
	}
	int find(int x) { // path compression
		return (p[x] == -1 ? x : p[x] = find(p[x]));
	}
	void unionn(int x, int y) { // union by size
		auto rx{find(x)}, ry{find(y)};
		if (rx == ry) return ;
		list<int> t{}; t.splice(t.end(), c[rx]), t.splice(t.end(), c[ry]);
		if (sz[rx] < sz[ry]) swap(rx, ry);
		p[ry] = rx, sz[rx] += sz[ry], c[rx] = move(t);
	}

	list<int> extract_content(int x) { // x must be root of the set
		return move(c[x]);
	}
};

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> pre(n);
	for (auto& x : pre) cin >> x, --x;

	bool has_ans{true};
	vector<int> ans{};
	DSU dsu{n};
	while (k--) {
		int x, y;
		cin >> x >> y, --x, --y;
		if (dsu.find(x) == dsu.find(y)) has_ans = false; // form a cycle
		dsu.unionn(x, y);
	}

	vector<set<int>> adj(n);
	vector<int> pc(n, 0); // predecessor count
	for (int i{0}; i < n; ++i) {
		if (pre[i] == -1) continue;
		auto u{dsu.find(pre[i])}, v{dsu.find(i)};
		if (u == v) continue;

		if (adj[u].find(v) == adj[u].end()) {
			adj[u].insert(v);
			++pc[v];
		}
	}

	vector<bool> vis(n, false);
	queue<int> qu{};
	for (int i{0}; i < n; ++i) if (!pc[i] && dsu.find(i) == i) qu.push(i);
	while (!qu.empty()) {
		auto u{qu.front()}; qu.pop();

		for (auto& x : dsu.extract_content(u)) {
			ans.push_back(x);

			vis[x] = true;
			if (pre[x] == -1 || dsu.find(pre[x]) != dsu.find(x)) continue;
			if (!vis[pre[x]]) has_ans = false; // deal with edge inside a pseudo node
		}

		for (auto& v : adj[u]) {
			--pc[v];
			if (!pc[v]) qu.push(v);
		}
	}

	for (int i{0}; i < n; ++i) if (pc[i]) has_ans = false;

	if (has_ans) {
		for (auto& x : ans) cout << x + 1 << ' ';
		cout << '\n';
	} else cout << "0\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	// cin >> t;
	while (t--) solve();

	return 0;
}
