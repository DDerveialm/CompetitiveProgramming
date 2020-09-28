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
#include <limits>
#include <cmath>

using namespace std;

void solve() {
	int n;
	cin >> n;
	int ans{0};
	long long tot{0};
	set<long long> s{};
	for (int i{0}; i < n; ++i) {
		long long x;
		cin >> x;
		tot += x;
		if (tot == 0 || s.find(tot) != s.end()) {
			++ans;
			s.clear();
			tot = x;
		}
		s.insert(tot);
	}
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();

	return 0;
}
