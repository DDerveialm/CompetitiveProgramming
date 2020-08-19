#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<char> vec(n);
		for (auto& e : vec) cin >> e;

		int ans = 0;
		auto fd = vec.end(); // first element that differs from the last
		for (auto it = vec.begin(); it != vec.end(); ++it)
			if (*it != vec.back()) {
				fd = it;
				break;
			}

		if (fd == vec.end()) {
			if (n <= 2) ans = 0;
			else ans = (n + 2) / 3;
		} else {
			rotate(vec.begin(), fd, vec.end());
			vec.push_back('$');
			auto cnt = 1;
			for (int i = 0; i < n; ++i) {
				if (vec[i] == vec[i + 1]) {
					++cnt;
				} else {
					ans += cnt / 3;
					cnt = 1;
				}
				
			}
		}
		cout << ans << endl;
	}
	return 0;
}
