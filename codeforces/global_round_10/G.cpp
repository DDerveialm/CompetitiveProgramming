#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

inline int mask(const string& s) {
	int m = 0;
	for (int i = 0; i < s.size(); ++i)
		if (s[i] == '1')
			m |= (1 << i);
	return m;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, m, k;
	cin >> n >> m >> k;
	string S, T;
	cin >> S >> T;
	vector<int> dpS(1 << k, 1e9), dpT(1 << k, -1e9);
	dpS[mask(S)] = 0;
	dpT[mask(T)] = 0;
	vector<int> p(k); // record the i-th bit in begining is now at p[i]
	for (int i = 0; i < k; ++i) p[i] = i;
	for (int i = 1; i <= n; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		swap(S[p[a]], S[p[b]]);
		swap(T[p[a]], T[p[b]]);
		swap(p[a], p[b]);
		dpS[mask(S)] = min(i, dpS[mask(S)]);
		dpT[mask(T)] = i;
	}

	int c1 = count(S.begin(), S.end(), '1'), c2 = count(T.begin(), T.end(), '1');
	int Max = -1;
	pair<int, int> ans;
	for (int i = (1 << k) - 1; i >= 0; --i) {
		if (dpT[i] - dpS[i] >= m) {
			int cb = k - c1 - c2 + 2 * __builtin_popcount(i);
			if (cb > Max) {
				Max = cb;
				ans = {dpS[i] + 1, dpT[i]};
			}
		}
		for (int j = 0; j < k; ++j)
			if (i & (1 << j)) {
				dpS[i ^ (1 << j)] = min(dpS[i ^ (1 << j)], dpS[i]);
				dpT[i ^ (1 << j)] = max(dpT[i ^ (1 << j)], dpT[i]);
			}
	}
	cout << Max << endl;
	cout << ans.first << " " << ans.second << endl;
	return 0;
}
