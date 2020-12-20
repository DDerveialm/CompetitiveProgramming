#include <iostream>
#include <string>

using namespace std;

void solve() {
	string s;
	cin >> s;
	long long x, y;
	cin >> x >> y;

	long long n0{0}, n1{0}, nq{0};
	for (auto& c : s)
		if (c == '0') ++n0;
		else if (c == '1') ++n1;
		else if (c == '?') ++nq;

	long long cnt0{0}, cnt1{0}, cntq;
	long long var{0}, dp{0};
	for (auto& c : s) {
		if (c == '0') {
			++cnt0;
			var += (n1 - cnt1) * x; // 01
		} else if (c == '1') {
		   	++cnt1;
			var += (n0 - cnt0) * y; // 10
		} else if (c == '?') {
			if (x >= y) dp += (n1 - cnt1) * x + cnt1 * y; // be 0
			else dp += cnt0 * x + (n0 - cnt0) * y; // be 1
		}
	}

	long long ans{dp};
	cnt0 = cnt1 = cntq = 0;
	for (auto& c : s) {
		if (c == '0') ++cnt0;
		else if (c == '1') ++cnt1;
		else if (c == '?') {
			++cntq;
			if (x >= y) {
				dp -= (n1 - cnt1) * x + cnt1 * y;
				dp += cnt0 * x + (n0 - cnt0) * y; // 0 -> 1
				ans = min(ans, dp + cntq * (nq - cntq) * y);
			} else {
				dp -= cnt0 * x + (n0 - cnt0) * y;
				dp += (n1 - cnt1) * x + cnt1 * y; // 1 -> 0
				ans = min(ans, dp + cntq * (nq - cntq) * x);
			}
		}
	}
	
	cout << var + ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	// cin >> t;
	while (t--) solve();

	return 0;
}
