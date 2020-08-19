#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits>

using namespace std;

inline int common_bits(const string& a, const string& b) {
	int cnt = 0;
	for (int i = 0; i < a.size() && i < b.size(); ++i)
		if (a[i] == b[i]) ++cnt;
	return cnt;
}

inline int changed(const string& a, const string& b, const pair<int, int>& p) {
	int before = (a[p.first] == b[p.first]) + (a[p.second] == b[p.second]);
	int after = (a[p.first] == b[p.second]) + (a[p.second] == b[p.first]);
	return after - before;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, m, k;
	cin >> n >> m >> k;
	string O, I;
	cin >> O >> I;
	vector<pair<int, int>> elves(n + 1);
	elves[0].first = elves[0].second = 0; // don't swap
	for (auto it = elves.begin() + 1; it != elves.end(); ++it) {
		cin >> it -> first >> it -> second;
		--it -> first;
		--it -> second;
	}

	int max = -1;
	pair<int, int> ans;

	vector<int> rec(k);
	for (int i = 0; i < k; ++i) rec[i] = i;
	string Ol = O;
	string Il = I;
	auto x = common_bits(O, I);
	for (int l = 0; l < n; ++l) {
		const auto& a = elves[l].first;
		const auto& b = elves[l].second;
		swap(Ol[rec[a]], Ol[rec[b]]);
		swap(Il[rec[a]], Il[rec[b]]);
		swap(rec[a], rec[b]);

		auto rec2(rec);
		string Ir = Il;
		auto cb = x;
		for (int r = l + 1; r <= n; ++r) {
			const auto& a = elves[r].first;
			const auto& b = elves[r].second;
			cb += changed(Ol, Ir, {rec2[a], rec2[b]});
			swap(Ir[rec2[a]], Ir[rec2[b]]);
			swap(rec2[a], rec2[b]);
			if (r - l >= m && cb > max) {
				max = cb;
				ans = {l + 1, r};
			}
		}
	}
	cout << max << endl;
	cout << ans.first << " " << ans.second << endl;
	return 0;
}
