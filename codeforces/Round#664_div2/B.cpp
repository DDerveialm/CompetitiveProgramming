#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

inline void print(int x, int y) {
	cout << x << " " << y << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, m, x, y;
	cin >> n >> m >> x >> y;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			print(x, y);
			if (j != m) ++y;
			if (y > m) y -= m;
		}
		++x;
		if (x > n) x -= n;
	}
	
	return 0;
}
