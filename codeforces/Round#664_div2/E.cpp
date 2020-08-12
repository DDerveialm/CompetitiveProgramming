#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<pair<int, int>>> E(n);
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		E[u - 1].emplace_back(w, v - 1);
	}
	for (auto& e : E) sort(e.begin(), e.end());

	return 0;
}
