#include <iostream>
#include <string>

using namespace std;

void solve() {
	string s;
	cin >> s;
	int cnt{0}, ans{0};
	for (int i{3}; i < s.size(); ++i) {
		bool not_KICK{false}, not_START{false};

		if (s[i - 3] != 'K') not_KICK = true;
		if (s[i - 2] != 'I') not_KICK = true;
		if (s[i - 1] != 'C') not_KICK = true;
		if (s[i    ] != 'K') not_KICK = true;

		if (!not_KICK) ++cnt;

		if (i - 4 < 0) not_START = true;
		else if (s[i - 4] != 'S') not_START = true;
		if (s[i - 3] != 'T') not_START = true;
		if (s[i - 2] != 'A') not_START = true;
		if (s[i - 1] != 'R') not_START = true;
		if (s[i    ] != 'T') not_START = true;
		if (!not_START) ans += cnt;
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": ";
		solve();
	}
	return 0;
}
