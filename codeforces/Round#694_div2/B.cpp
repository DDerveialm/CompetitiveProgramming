#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

void solve() {
	int n, x;
	cin >> n >> x;

	long long ans{0};
	vector<int> v(n);
	for (auto& e : v) cin >> e, ans += e;

	queue<pair<int, int>> qu{};
	bool flag{true};
	for (auto& e : v) {
		if (e % x) {
			flag = false;
			break;
		} else {
			ans += e;
			qu.emplace(e / x, e);
		}
	}

	if (flag)
		while (!qu.empty()) {
			auto [e, t]{qu.front()}; qu.pop();

			if (e % x) break;
			else ans += t, qu.emplace(e / x, t);
		}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
