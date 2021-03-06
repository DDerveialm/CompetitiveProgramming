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
		array<int, 3> c1, c2;
		for (auto& e : c1) cin >> e;
		for (auto& e : c2) cin >> e;
		
		int ans = 0;
		auto tmp = min(c1[2], c2[1]);
		ans += 2 * tmp;
		c1[2] -= tmp;
		c2[1] -= tmp;

		tmp = c1[1] - c2[0] - c2[1];
		if (tmp > 0) ans -= 2 * tmp;

		cout << ans << endl;
	}
	return 0;
}
