#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

constexpr int MAX = 25 * 2;

void solve(const int& n, long long k) {
	int x = 0, y = 0;
	cout << "1 1" << endl;
	while (x + 1 < n || y + 1 < n) {
		k >>= 1;
		bool f1 = k & 1; // k contains 2 ^ i
		bool f2 = (x + 1) % 2; // grid[x + 1][y] != 0
		if (f1 == f2) ++x; // f1 xnor f2
		else ++y;
		cout << x + 1 << " " << y + 1 << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			long long entry;
			if (i % 2) entry = 1ll << (i + j);
			else entry = 0;
			cout << entry << " ";
		}
		cout << endl;
	}
	int q;
	cin >> q;
	while (q--) {
		long long k;
		cin >> k;
		solve(n, k);
	}
	return 0;
}
