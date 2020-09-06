#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<long long> vec(n);
	cin >> vec[0];
	long long ans{vec[0]};
	for (int i{1}; i < n; ++i) {
		cin >> vec[i];
		vec[i] += vec[i - 1];
		if (vec[i] < ans) ans = vec[i];
	}
	ans *= -1;
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}
