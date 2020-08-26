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
	int n;
	cin >> n;
	for (int i = 0; i < 2 * n - 1; ++i) {
		char c;
		cin >> c;
		if (i % 2 == 0) cout << c;
	}
	cout << endl;
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
