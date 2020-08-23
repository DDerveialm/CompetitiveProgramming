#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int n;
		cin >> n;
		vector<int> vec(n);
		for (auto& e : vec) cin >> e;
		vec.push_back(2e9 + 1);
		auto last = numeric_limits<int>::max(), cnt = 0;
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			auto d = vec[i] - vec[i - 1];
			if (d == last) {
				++cnt;
			} else {
				if (cnt > ans) ans = cnt;
				last = d;
				cnt = 1;
			}
		}

		cout << "Case #" << t << ": " << ans + 1 << endl;
	}
	return 0;
}
