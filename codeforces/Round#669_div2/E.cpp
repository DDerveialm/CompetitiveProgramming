#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

constexpr int NONE = numeric_limits<int>::max();

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> bg(n), wg(n);
	while (m--) {
		int u, v, t;
		cin >> u >> v >> t, --u, --v;
		if (t) wg[v].push_back(u);
		else bg[v].push_back(u);
	}

	int S{0}, T{n - 1}; // source, target
	vector<int> b(n, NONE), w(n, NONE), dp(n, NONE);
	b[T] = w[T] = dp[T] = 0;
	queue<int> qu;
	qu.push(T);
	while (!qu.empty()) {
		auto x = qu.front();
		qu.pop();
		
		for (auto& to : bg[x]) {
			if (b[to] != NONE) continue;
			b[to] = dp[x] + 1;
			if (w[to] != NONE) {
				qu.push(to);
				dp[to] = b[to]; // b[to] >= w[to]
			}
		}
		for (auto& to : wg[x]) {
			if (w[to] != NONE) continue;
			w[to] = dp[x] + 1;
			if (b[to] != NONE) {
				qu.push(to);
				dp[to] = w[to];
			}
		}
	}
	if (dp[0] == NONE) cout << -1 << endl;
	else cout << dp[0] << endl;
	for (int i{0}; i < n; ++i) {
		if (b[i] > w[i]) cout << 0;
		else cout << 1;
	}
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();	

	return 0;
}
