#include <iostream>
#include <vector>
#include <stack>
#include <limits>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> h(n);
	for (auto& e : h) cin >> e;
	
	vector<int> Rl(n), Rg(n), Ll(n), Lg(n);
	stack<int> stk{};
	for (int i = 0; i < n; ++i) { // first j in the left that is h[j] >= h[i]
		while (!stk.empty() && h[stk.top()] < h[i]) stk.pop();
		if (!stk.empty()) Lg[i] = stk.top();
		else Lg[i] = -1;
		stk.push(i);
	}
	stk = {};
	for (int i = 0; i < n; ++i) { // first j in the left that is h[j] <= h[i]
		while (!stk.empty() && h[stk.top()] > h[i]) stk.pop();
		if (!stk.empty()) Ll[i] = stk.top();
		else Ll[i] = -1;
		stk.push(i);
	}
	stk = {};
	for (int i = n - 1; i >= 0; --i) { // first j in the right that is h[j] >= h[i]
		while (!stk.empty() && h[stk.top()] < h[i]) stk.pop();
		if (!stk.empty()) Rg[i] = stk.top();
		else Rg[i] = -1;
		stk.push(i);
	}
	stk = {};
	for (int i = n - 1; i >= 0; --i) { // first j in the right that is h[j] <= h[i]
		while (!stk.empty() && h[stk.top()] > h[i]) stk.pop();
		if (!stk.empty()) Rl[i] = stk.top();
		else Rl[i] = -1;
		stk.push(i);
	}

	vector<vector<int>> from(n);
	for (int i{0}; i < n; ++i) {
		if (Lg[i] != -1) from[i].push_back(Lg[i]);
		if (Ll[i] != -1) from[i].push_back(Ll[i]);
		if (Rg[i] != -1) from[Rg[i]].push_back(i);
		if (Rl[i] != -1) from[Rl[i]].push_back(i);
	}
	
	vector<int> dp(n, 1e9);
	dp[0] = 0;
	for (int i{0}; i < n; ++i) {
		for (auto& e : from[i])
			dp[i] = min(dp[i], dp[e] + 1);
	}
	cout << dp[n - 1] << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();

	return 0;
}
