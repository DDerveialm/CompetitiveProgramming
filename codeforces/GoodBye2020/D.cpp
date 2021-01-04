#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> w(n), d(n, 0);

	long long ans{0};

	for (auto& x : w) cin >> x, ans += x;
	for (int i{0}; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		++d[u], ++d[v];
	}

	priority_queue<int> pq{};
	for (int u{0}; u < n; ++u)
		for (int i{0}; i < d[u] - 1; ++i) pq.push(w[u]);

	cout << ans << ' ';
	for (int i{2}; i <= n - 1; ++i) {
		ans += pq.top(), pq.pop();
		cout << ans << ' ';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
