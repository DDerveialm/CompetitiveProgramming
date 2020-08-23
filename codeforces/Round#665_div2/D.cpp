#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

constexpr int MOD = 1e9 + 7;

namespace DFS {
	vector<vector<int>> adjLists;
	vector<long long> weight;
	int dfs(int u, int w = -1) {
		int count = 1;
		for (const auto& v : adjLists[u])
		if (v != w) count += dfs(v, u);
		if (w != -1) weight.push_back(static_cast<long long>(count) * static_cast<long long>(adjLists.size() - count));
		return count;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		DFS::adjLists.assign(n, {});
		DFS::weight.clear();
		for (int i = 0; i < n - 1; ++i) {
			int u, v;
			cin >> u >> v;
			--u, --v;
			DFS::adjLists[u].push_back(v);
			DFS::adjLists[v].push_back(u);
		}
		DFS::dfs(0);
		sort(DFS::weight.begin(), DFS::weight.end());

		int m;
		cin >> m;
		vector<long long> p(m);
		for (auto& e : p) cin >> e;
		while (p.size() < n - 1) // add more 1's
			p.push_back(1);
		sort(p.begin(), p.end());
		while (p.size() > n - 1) { // multiply all greatest numbers together until p.size() == n - 1
			*(p.end() - 2) *= *(p.end() - 1);
			*(p.end() - 2) %= MOD;
			p.pop_back();
		}
		
		long long ans = 0;
		for (int i = 0; i < n - 1; ++i) {
			ans += DFS::weight[i] * p[i];
			ans %= MOD;
		}
		cout << ans << endl;
	}
	return 0;
}
