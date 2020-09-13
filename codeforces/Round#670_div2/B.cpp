#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> pos{}, neg{};
	for (int i{0}; i < n; ++i) {
		int a;
		cin >> a;
		if (a >= 0) pos.push_back(a);
		else if (a < 0) neg.push_back(-1 * a);
	}
	sort(pos.rbegin(), pos.rend());
	sort(neg.rbegin(), neg.rend());
		
	long long ans{1};
	if (!pos.empty() && ((pos.size() - 1) / 2 + neg.size() / 2) >= 2) {
		priority_queue<int> cand;
		if (pos.size() >= 3) cand.push(pos[1] * pos[2]);
		if (pos.size() >= 5) cand.push(pos[3] * pos[4]);
		if (neg.size() >= 2) cand.push(neg[0] * neg[1]);
		if (neg.size() >= 4) cand.push(neg[2] * neg[3]);

		ans = pos[0];
		for (int i{0}; i < 2; ++i)
			ans *= cand.top(), cand.pop();
	} else {
		priority_queue<int> cand;
		for (auto it{pos.rbegin()}; it!= pos.rbegin() + 5 && it != pos.rend(); ++it) cand.push(*it);
		for (auto it{neg.rbegin()}; it!= neg.rbegin() + 5 && it != neg.rend(); ++it) cand.push(*it);

		ans = -1;	
		for (int i{0}; i < 5; ++i)
			ans *= cand.top(), cand.pop();
	}
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
