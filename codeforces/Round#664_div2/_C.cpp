#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

int main() { // the same problem but to find maximum
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	vector<int> b(m);
	for (auto& e : a) cin >> e;
	for (auto& e : b) cin >> e;
	
	vector<bool> c(n, false);

	int ans = 0, max, index;
	for (int k = 0; k < n; ++k) {
		max = -1;
		for (int i = 0; i < n; ++i) {
			if (c[i]) continue;
			for (int j = 0; j < m; ++j) {
				int t = a[i] & b[j] & ~ans;
				if (t > max) {
					max = t;
					index = i;
				}
			}
		}
		ans |= max;
		c[index] = true;
	}
	cout << ans << endl;
	return 0;
}
