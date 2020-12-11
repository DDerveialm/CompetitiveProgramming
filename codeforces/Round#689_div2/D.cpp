#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

#define fi first
#define se second

using namespace std;

set<long long> value{};

void dfs(vector<int>&& v) {
	auto p{minmax_element(v.begin(), v.end())};
	int mn{*(p.fi)}, mx{*(p.se)}, mid{(mn + mx) / 2};

	vector<int> L{}, R{};
   	long long ls{}, rs{};
	for (auto& x : v)
		if (x <= mid) L.push_back(x), ls += x;
		else R.push_back(x), rs += x;
	value.insert(ls), value.insert(rs);

	if (!L.empty() && !R.empty()) dfs(move(L)), dfs(move(R));
}

void solve() {
	value.clear();

	int n, q;
	cin >> n >> q;

	long long sum{0};
	vector<int> v(n);
	for (auto& x : v) cin >> x, sum += x;
	value.insert(sum);

   	vector<long long> s(q);
	for (auto& x : s) cin >> x;

	dfs(move(v));

	for (auto& x : s) {
		if (value.find(x) != value.end()) cout << "Yes\n";
		else cout << "No\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
