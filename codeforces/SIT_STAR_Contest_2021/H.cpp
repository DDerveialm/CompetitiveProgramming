#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

void solve() {
	int n;
	cin >> n;
	priority_queue<int, vector<int>, greater<int>> pq1{}, pq2{};
	for (int i{0}; i < n; ++i) {
		int c, t;
		cin >> c >> t;
		if (t == 1) pq1.emplace(c);
		else pq2.emplace(c);
	}

	int cnt1{0}, cnt2{0}, ans{0};
	for (int i{1}; i <= n; ++i) {
		if (cnt2 >= 2 * cnt1 + 2) { // take from 1
			if (!pq1.empty()) {
				ans += pq1.top(), pq1.pop(), ++cnt1;
			} else ans = -1;
		} else if (cnt1 >= 2 * cnt2 + 2) { // take from 2
			if (!pq2.empty()) {
				ans += pq2.top(), pq2.pop(), ++cnt2;
			} else ans = -1;
		} else {
			if (pq2.empty() || (!pq1.empty() && pq1.top() <= pq2.top())) ans += pq1.top(), pq1.pop(), ++cnt1;
			else ans += pq2.top(), pq2.pop(), ++cnt2;
		}
		cout << ans << '\n' << flush;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	// cin >> t;
	while (t--) solve();

	return 0;
}
