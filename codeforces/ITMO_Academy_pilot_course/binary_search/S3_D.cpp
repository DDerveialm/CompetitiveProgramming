#include <iostream>
#include <vector>
#include <queue>

using namespace std;

namespace G {
	vector<vector<pair<int, int>>> adj{};
	vector<int> p{};
	int S, T;
	int d;

	void read() {
		int n, m;
		cin >> n >> m >> d;
		adj.assign(n, {});
		p.assign(n, {});
		S = 0, T = n - 1;
		while (m--) {
			int a, b, c;
			cin >> a >> b >> c, --a, --b;
			adj[a].emplace_back(b, c);
		}
	}

	int bfs(int c) {
		for (auto& x : p) x = -1;

		vector<int> vis(adj.size(), false);
		queue<int> q1, q2;
		int len{0};
		vis[S] = true;
		q1.push(S);
		while (!q1.empty() && len < d && !vis[T]) {
			while (!q1.empty()) {
				auto u{q1.front()};
				q1.pop();
				
				for (auto& e : adj[u]) {
					if (e.second > c || vis[e.first]) continue;
					vis[e.first] = true;
					p[e.first] = u;
					q2.push(e.first);
				}
			}
			q1.swap(q2);
			++len;
		}

		return (vis[T] ? len : -1);
	}

	void aux(int x) {
		if (p[x] != -1) aux(p[x]);
		cout << x + 1 << " ";
	}
	void print_path() {
		if (p[T] != -1) {
			aux(T);
			cout << endl;
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	G::read();

	int l{0}, r{static_cast<int>(1e9) + 1};
	while (l < r - 1) {
		int m{(l + r) / 2};
		if (G::bfs(m - 1) == -1) l = m;
		else r = m;
	}
	cout << G::bfs(l) << endl;
	G::print_path();

	return 0;
}
