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
		int n;
		cin >> n;
		int last;
		cin >> last;
		long long ans = 0;
		for (int i = 1; i < n; ++i) {
			int h;
			cin >> h;
			if (h < last) ans += last - h;
			last = h;
		}

		cout << ans << endl;
	}
	return 0;
}
