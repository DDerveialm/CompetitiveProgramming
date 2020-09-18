#include <iostream>
#include <vector>

using namespace std;

constexpr double err = 1e-5;

namespace G {
	vector<vector<pair<int, double>>> adj{};
	vector<int> p{};
	int S, T;
	int d;

	void read() {
		int n, m;
		cin >> n >> m;
		adj.assign(n, {});
		p.assign(n, {});
		S = 0, T = n - 1;
		while (m--) {
			int a, b, c;
			cin >> a >> b >> c, --a, --b;
			adj[a].emplace_back(b, c);
		}
	}

   	int len;
	double w, cst;

	int dfs(int u) {
		if (u == T)
			if (w / len <= cst) return len;
			else return 0;

		for (auto& e : adj[u]) {
			w += e.second, ++len, p[e.first] = u;
			auto r{dfs(e.first)};
			if (r) return r;
			w -= e.second, --len, p[e.first] = -1;
		}
		return 0;
	}

	int DFS(double c) {
		w = 0;
		len = 0;
		cst = c;
		for (auto& x : p) x = -1;

		return dfs(S);
	}

	void aux(int x) {
		if (p[x] != -1) aux(p[x]);
		cout << x + 1 << " ";
	}
	void print_path() {
		aux(T);
		cout << endl;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	G::read();

	double l{0 - err}, r{100}; // ans is in (l,r]
	while (r - l >= err) {
		double m{(l + r) / 2};
		if (G::DFS(m)) r = m;
		else l = m;
	}
	cout << G::DFS(r) << endl;
	G::print_path();

	return 0;
}
