#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int GCD(int a, int b) {
	if (a < b) swap(a, b);
	while (b != 0) {
		a %= b;
		swap(a, b);
	}
	return a;
}

void solve() {
	int n;
	cin >> n;
	vector<int> A(n);
	for (auto& e : A) cin >> e;

	vector<bool> taken(n, false);
	int c = *max_element(A.begin(), A.end());
	for (int i{0}; i < n; ++i) {
		int max = 0, idx;
		for (int j{0}; j < n; ++j) {
			if (taken[j]) continue;
			auto m = GCD(A[j], c);
			if (max < m) {
				max = m;
				idx = j;
			}
		}
		taken[idx] = true;
		cout << A[idx] << " ";
		c = max;
	}
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}
