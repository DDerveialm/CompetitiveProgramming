#include <iostream>
#include <string>
#include <queue>

using namespace std;

void solve() {
	int a, b;
	cin >> a >> b;
	string s;
	cin >> s;
	s += '0';

	priority_queue<int, vector<int>, greater<int>> pq{};
	int cnt{0}, last{0};
	while (last < s.length() && s[last] == '0') ++last;
	for (int i{last + 1}; i < s.length(); ++i) {
		if (s[i] == '0' && s[i - 1] == '1') ++cnt; // 11..10
		if (s[i] == '1' && s[i - 1] == '0') pq.push(i - last - 1); // 100..01

		if (s[i] == '1') last = i;
	}

	int ans{cnt * a};
	while (!pq.empty() && pq.top() * b < a)
		ans -= a, ans += pq.top() * b, pq.pop();
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}
