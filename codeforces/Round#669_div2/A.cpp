#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> vec(n);
	for (auto& e : vec) cin >> e;

	vector<int> ck(vec);
	for (int i{1}; i < n; ++i)
		if (ck[i] && ck[i - 1]) ck[i] = ck[i - 1] = 0;
	
	cout << count(ck.begin(), ck.end(), 0) << endl;
	for (int i{0}; i < n; ++i)
		if (!ck[i]) cout << vec[i] << " ";
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
