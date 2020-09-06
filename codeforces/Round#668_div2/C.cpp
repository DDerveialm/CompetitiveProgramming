#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<char> vec(n);
	for (auto& e : vec) cin >> e;
	
	bool ans{true};
	queue<int> q;
	for (int i{0}; i < n; ++i)
		if (vec[i] != '?') q.push(i);
	while (!q.empty()) {
		int i{q.front()};
		q.pop();
		if (i - k >= 0) {
			if (vec[i - k] == '?') {
				vec[i - k] = vec[i];
				q.push(i - k);
			} else if (vec[i] != vec[i - k]) {
				ans = false;
				break;
			}
		}   
		if (i + k < n) {
			if (vec[i + k] == '?') {
				vec[i + k] = vec[i];
				q.push(i + k);
			} else if (vec[i] != vec[i + k]) {
				ans = false;
				break;
			}
		}   
	}
	
	int cnt0{0}, cnt1{0};
	for (int i{0}; i < k; ++i) {
		if (vec[i] == '0') ++cnt0;
		else if (vec[i] == '1') ++cnt1;
	}
	if (cnt0 > k / 2 || cnt1 > k / 2) ans = false;

	if (ans) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}
