#include <iostream>
#include <array>
#include <queue>
#include <functional>

using namespace std;

void solve() {
	array<int, 3> n;
	for (auto& x : n) cin >> x;

	long long s{0};
	priority_queue<long long, vector<long long>, greater<long long>> pq{};

	array<long long, 3> mn;
	for (int k{0}; k < 3; ++k) {
		long long ls{0};
		mn[k] = numeric_limits<long long>::max();

		for (int i{0}; i < n[k]; ++i) {
			long long x;
			cin >> x, mn[k] = min(mn[k], x), ls += x;

			pq.push(ls);
			s += ls;
		}
	}

	sort(mn.begin(), mn.end());
	pq.push(mn[0] + mn[1]);

	cout << s - 2 * pq.top() << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	// cin >> t;
	while (t--) solve();

	return 0;
}
