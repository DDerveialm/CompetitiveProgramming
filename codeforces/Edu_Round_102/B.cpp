#include <iostream>
#include <string>
#include <numeric>

using namespace std;

void solve() {
	string s{}, t{};
	cin >> s >> t;

	string S{}, T{};
	int x{lcm(s.size(), t.size())};
	for (int i{0}; i < x / s.size(); ++i) S += s;
	for (int i{0}; i < x / t.size(); ++i) T += t;

	if (S == T) cout << S << '\n';
	else cout << "-1\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
