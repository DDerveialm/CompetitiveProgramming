#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, first, last, useless;
		cin >> n >> first;
		for (int i = 1; i <= n - 2; ++i) cin >> useless;
		cin >> last;
		if (last > first) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
