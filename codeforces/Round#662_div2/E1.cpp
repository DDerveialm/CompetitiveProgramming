#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

constexpr int maxL = 2e4 + 1;
constexpr int MOD = 1e9 + 7;

bool Scmp(const string& s1, const int& a, const string& s2, const int& b) { // return true if s1 >= s2
	int i = 0, j = 0;
	if (i == a) ++i;
	if (j == b) ++j;
	while (i < s1.length() && j < s2.length()) {
		if (s1[i] != s2[j]) return s1[i] > s2[j];
		++i; ++j;
		if (i == a) ++i;
		if (j == b) ++j;
	}
	if (j >= s2.length()) return true;
	else return false;
}

void Ssort(const string& word, vector<int>& ans) {
	vector<int> c(word.length());
	for (int i = 0; i < c.size() - 1; ++i) {
		if (word[i] < word[i + 1]) c[i] = 1;
		else if (word[i] == word[i + 1]) c[i] = 0;
		else c[i] = -1;
	}
	c.back() = -1;
	
	deque<int> dq;
	dq.push_back(word.length());
	int last;
	for (int i = c.size() - 1; i >= 0; --i) {
		if (c[i] == 0) c[i] = last;
		else last = c[i];

		if (c[i] == 1) dq.push_back(i);
		else if (c[i] == -1) dq.push_front(i);
	}
	for (int i = 0; i < word.length() + 1; ++i) {
		ans[i] = dq.front();
		dq.pop_front();
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	vector<string> scroll(n);
	for (int i = 0; i < n; ++i)
		cin >> scroll[i];

	vector<vector<int>> dp(2, vector<int>(maxL));
	vector<vector<int>> sub(2, vector<int>(maxL));
	for (int j = 0; j < scroll[0].length() + 1; ++j)
		dp[1][j] = j + 1;
	Ssort(scroll[0], sub[1]);

	for (int i = 1; i < n; ++i) {
		sub[1].swap(sub[0]);
		Ssort(scroll[i], sub[1]);

		dp[1].swap(dp[0]);
		int last = -1; // record last left bound
		for (int j = 0; j < scroll[i].length() + 1; ++j) {
			dp[1][j] = 0;
			int l = last, r = scroll[i - 1].length() + 1; // [l:r)
			while (l < r - 1) {
				int m = (l + r) / 2;
				if (Scmp(scroll[i], sub[1][j], scroll[i - 1], sub[0][m])) l = m;
				else r = m;
			}
			last = l;
			if (l != -1) dp[1][j] = dp[0][l];
			if (j != 0) dp[1][j] += dp[1][j - 1];
			if (dp[1][j] >= MOD) dp[1][j] -= MOD;
		}
	}

	int ans = dp[1][scroll[n - 1].length()];
	cout << ans << endl;
	return 0;
}
