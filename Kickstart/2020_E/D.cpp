#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <tuple>

using namespace std;

namespace G {
	constexpr long long BN = 1e12;
	vector<vector<int>> adjList;
	vector<vector<long long>> cost;
	vector<vector<bool>> visited;
	vector<vector<pair<vector<int>, int>>> recipe;

	using pq_type = pair<long long, pair<int, int>>;
	priority_queue<pq_type, vector<pq_type>, greater<pq_type>> pq;

	void read() {
		int n, m, s, r;
		cin >> n >> m >> s >> r;
		adjList.assign(n, {});
		cost.assign(n, vector<long long>(s, BN));
		visited.assign(n, vector<bool>(s, false));
		recipe.assign(s, {});
		while (!pq.empty()) pq.pop(); // clear pq

		for (int i = 0; i < m; ++i) {
			int u, v;
			cin >> u >> v, --u, --v;
			adjList[u].push_back(v);
			adjList[v].push_back(u);
		}
		for (int i = 0; i < n; ++i) {
			int C;
			cin >> C;
			for (int j = 0; j < C; ++j) {
				int t;
				cin >> t, --t;
				cost[i][t] = 0;
				pq.push(make_pair(0, make_pair(i, t)));
			}
		}
		for (int i = 0; i < r; ++i) {
			int K;
			cin >> K;
			pair<vector<int>, int> R {vector<int> (K), {}};
			for (auto& e : R.first)
				cin >> e, --e;
			cin >> R.second, --R.second;
			for (auto& e : R.first)
				recipe[e].push_back(R);
		}
	}

	inline long long applyRecipe(int& u, vector<int>& igd) {
		long long ret = 0;
		for (auto& e : igd)
			ret += cost[u][e];
		return ret;
	}

	void Dijkstra() {
		while(true) {
			int u, c;
			bool found = true;
			do {
				if (pq.empty()) {
					found = false;
					break;
				}
				tie(u, c) = pq.top().second;
				pq.pop();
			} while (visited[u][c]);
			if (!found) break;

			visited[u][c] = true;
			for (auto& v : adjList[u])
				if (cost[v][c] > cost[u][c] + 1) {
					cost[v][c] = cost[u][c] + 1;
					pq.push({cost[v][c], {v, c}});
				}
			for (auto& r : recipe[c]) {
				auto _c = applyRecipe(u, r.first);
				if (cost[u][r.second] > _c) {
					cost[u][r.second] = _c;
					pq.push({cost[u][r.second], {u, r.second}});
				}
			}
		}
	}

	long long ans() {
		long long a = BN;
		for (auto& e : cost)
			a = min(e[0], a);
		return (a == BN ? -1 : a);
	}

	void print() {
		for (int i = 0; i < cost.size(); ++i)
			for (int j = 0; j < cost[i].size(); ++j)
				cout << "cost[" << i << "][" << j << "] = " << cost[i][j] << endl;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		G::read();
		G::Dijkstra();
		cout << "Case #" << t << ": " << G::ans() << endl;
	}
	return 0;
}
