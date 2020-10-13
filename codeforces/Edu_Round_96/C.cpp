#include <iostream>
#include <queue>

using namespace std;

void solve() {
	int n;
	cin >> n;
	priority_queue<int> pq{};
	for (int i{1}; i <= n; ++i) pq.push(i);

	vector<pair<int, int>> ans{};
	for (int i{0}; i < n - 1; ++i) {
		int mx1{pq.top()};
		pq.pop();
		int mx2{pq.top()};
		pq.pop();

		ans.push_back({mx1, mx2});
		pq.push((mx1 + mx2 + 1) / 2);
	}
	cout << pq.top() << '\n';
	for (auto& x : ans) cout << x.first << " " << x.second << '\n';
}

void solve2() {
	int n;
	cin >> n;
	cout << "2\n";
	cout << n << ' ' << n - 1 << '\n';
	for (int i{n}; i >= 3; --i) cout << i << ' ' << i - 2 << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while (t--) solve2();

	return 0;
}
