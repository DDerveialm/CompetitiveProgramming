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
	
	long long n;
	cin >> n;
	long long sum = 0;
	for (int i = 0; i < n; ++i) {
		long long h;
		cin >> h;
		sum += h;
	}
	long long x = (sum - n * (n - 1) / 2) / n;
	long long d = sum - n * x - n * (n - 1) / 2;

	for (int i = 0; i < n; ++i)
		if (i < d) cout << x + i + 1 << " ";
		else cout << x + i << " ";
	cout << endl;
	return 0;
}
