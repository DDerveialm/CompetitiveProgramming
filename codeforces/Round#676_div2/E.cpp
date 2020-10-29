#include <iostream>
#include <vector>
#include <algorithm>

#define fi first
#define se second

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	long long sum{0};
	for (int i{0}; i < n; ++i) {
		cin >> v[i].fi;
		v[i].se = i;
		sum += v[i].fi;
	}
	sort(v.begin(), v.end());

	long long ans{numeric_limits<long long>::min()};
	if (n % 3 == 1) ans = sum;
	vector<int> ck(n - 1, true);
	int cnt{n - 1};
	for (int i{0}; i < n; ++i) {
		sum -= 2 * v[i].fi;
		if (v[i].se > 0) {
			ck[v[i].se - 1] = !ck[v[i].se - 1];
			cnt += ck[v[i].se - 1] ? 1 : -1;
		}
		if (v[i].se + 1 < n) {
			ck[v[i].se] = !ck[v[i].se];
			cnt += ck[v[i].se] ? 1 : -1;
		}
		if ((n + i + 1) % 3 == 1) {
			if (cnt) ans = max(ans, sum);
			else ans = max(ans, sum + 2 * v[i].fi - 2 * v[i + 1].fi);
		}
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();

	return 0;
}
