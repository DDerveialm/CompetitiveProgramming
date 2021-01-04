#include <iostream>
#include <vector>
#include <set>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	set<int> s{};

	for (int i{0}; i < n; ++i) {
		cin >> v[i];
		for (int j{0}; j < i; ++j) s.insert(v[i] - v[j]);
	}

	cout << s.size() << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
