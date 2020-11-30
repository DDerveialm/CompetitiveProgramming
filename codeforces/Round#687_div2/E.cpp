#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k, ++k;
	vector<int> v(n);
	for (auto& x : v) cin >> x;
	sort(v.begin(), v.end());

	long long ans{0}, ss{0};
	for (int i{0}; i < n; ++i) ans += i * static_cast<long long>(v[i]), ss += v[i];

	for (int i{0}; (ss -= v[i]) < 0; ++i) // sliding
		if (i % k != k - 1) ans -= ss;

	cout << ans << '\n';
}

void genius_solve() {
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (auto& x : v) cin >> x;
	sort(v.rbegin(), v.rend());

	priority_queue<long long> pq{};
	for (int i{0}; i < k + 1; ++i) pq.push(0);
	
	long long ans{0};
	for (int i{0}; i < n; ++i) {
		auto t{pq.top()};
		pq.pop();
		ans += t;
		pq.push(t + v[i]);
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	// cin >> t;
	while (t--) genius_solve();

	return 0;
}
