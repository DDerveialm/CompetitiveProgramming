#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <tuple>
#include <algorithm>

using namespace std;

void solve() {
	int p, f, cnts, cntw, s, w;
	cin >> p >> f >> cnts >> cntw >> s >> w;
	if (s > w) {
		swap(s, w);
		swap(cnts, cntw);
	}

	int ans = 0;
	int a, b, x, y;
	for (a = min(min(p / s, cnts), max((p - cntw * w) / s, 0)); a <= cnts && a * s <= p; ++a) {
		b = min((p - a * s) / w, cntw);
		int rs = cnts - a, rw = cntw - b;
		x = min(f / s, rs);
		y = min((f - x * s) / w, rw);
		ans = max(ans, a + b + x + y);
	}
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}
