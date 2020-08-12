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
		int r, g, b, w;
		cin >> r >> g >> b >> w;
		int num_of_odd =  (r % 2) + (g % 2) + (b % 2) + (w % 2);

		if (num_of_odd == 2 || (num_of_odd == 3 && (r == 0 || g == 0 || b ==0))) cout << "No" << endl;
		else cout << "Yes" << endl;
	}
	return 0;
}
