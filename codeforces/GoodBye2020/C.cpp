#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve() {
	string s{};
	cin >> s;
	const size_t& n{s.size()};

	int ans{0};
	for (int i{0}; i < n; ++i) {
		if (!s[i]) continue;

		if (i + 1 < n && s[i + 1] == s[i]) ++ans, s[i + 1] = 0;
		if (i + 2 < n && s[i + 2] == s[i]) ++ans, s[i + 2] = 0;
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
