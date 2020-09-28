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

constexpr long long P{static_cast<long long>(1e9) + 7}; 

void solve() {
	int n;
	cin >> n;
	vector<char> v(n);
	for (auto& x : v) cin >> x;

	long long cnta{0}, cntab{0}, ans{0}, k{1};
	for (auto& x : v) {
		if (x == 'a') {
			cnta += k, cnta %= P;
		} else if (x == 'b') {
			cntab += cnta, cntab %= P;
		} else if (x == 'c') {
			ans += cntab, ans %= P;
		} else if (x == '?') {
			long long t1{cnta}, t2{cntab};
			cnta *= 3, cntab *= 3, ans *= 3;
			ans += t2, ans %= P; // as c
			cntab += t1, cntab %= P; // as b
			cnta += k, cnta %= P; // as a
			k *= 3, k %= P;
		}
	}
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();

	return 0;
}
