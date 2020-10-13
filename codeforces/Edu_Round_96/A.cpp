#include <iostream>

using namespace std;

void solve() {
	int n;
	cin >> n;
	for (int i{0}; i <= n; i += 3)
		for (int j{0}; j <= n; j += 5)
			for (int k{0}; k <= n; k += 7)
				if (i + j + k == n) {
					cout << i / 3 << " " << j / 5 << " " << k / 7 << "\n";
					return ;
				}
	cout << "-1\n";
}

void solve2() {
	int n;
	cin >> n;
	if (n == 1 || n == 2 || n == 4) cout << "-1\n";
	else if (n % 3 == 0) cout << n / 3 << " 0 0\n";
	else if (n % 3 == 1) cout << n / 3 - 2 << " 0 1\n";
	else if (n % 3 == 2) cout << n / 3 - 1 << " 1 0\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while (t--) solve2();

	return 0;
}
