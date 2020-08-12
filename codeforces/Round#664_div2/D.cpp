#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

pair<int, int> operator+ (const pair<int, int>& a, const pair<int, int>& b) {
	return {a.first + b.first, a.second + b.second};
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, d, m;
	cin >> n >> d >> m;
	++d;
	vector<int> L, H;
	for (int i = 0; i < n; ++i) {
		int f;
		cin >> f;
		if (f > m) H.push_back(f);
		else L.push_back(f);
	}
	sort(L.rbegin(), L.rend());
	sort(H.rbegin(), H.rend());

	vector<long long> dp(n + 1);
	vector<pair<int, int>> used(n + 1);
	dp[0] = 0;
	long long last;
	if (H.size())  {
		used[0] = make_pair(1, 0);
		last = H.front();
	} else {
		used[0] = make_pair(0, 1);
		last = L.front();
	}
	for (int i = 1; i < n; ++i) {
		long long a = 0;
		if (i - d >= 0 && used[i - d].first < H.size())
			a = dp[i - d] + H[used[i - d].first];
		long long b = dp[i - 1];
		if (used[i - 1].second < L.size()) b += L[used[i - 1].second];

		if (a > b) {
			used[i] = used[i - d] + make_pair(1, 0);
			dp[i] = a;
		} else {
			used[i] = used[i - 1] + make_pair(0, 1);
			dp[i] = b;
		}
	}

	cout << dp[n - 1] + last << endl;
	return 0;
}
