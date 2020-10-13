#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <functional>

using namespace std;

long long invcnt(vector<int>& v, int l, int r) {
	if (r - l <= 1) return 0;

	int m{(l + r) / 2};
	long long res{invcnt(v, l, m) + invcnt(v, m, r)};

	int h1{l}, h2{m};
	vector<int> merge{};
	while (h1 < m && h2 < r) {
		if (v[h1] <= v[h2]) merge.push_back(v[h1]), ++h1;
		else merge.push_back(v[h2]), ++h2, res += m - h1;
	}
	while (h1 < m) merge.push_back(v[h1]), ++h1;
	while (h2 < r) merge.push_back(v[h2]), ++h2;
	for (int i{l}; i < r; ++i) v[i] = merge[i - l];
	return res;
}

inline int idx(char c) { return static_cast<int>(c - 'a'); }

void solve() {
	int n;
	cin >> n;
	vector<char> v(n);
	array<priority_queue<int, vector<int>, greater<int>>, 26> r{};
	for (int i{0}; i < n; ++i) {
		cin >> v[i];
		r[idx(v[i])].push(n - i);
	}

	vector<int> p(n);
	for (int i{0}; i < n; ++i) {
		p[i] = r[idx(v[i])].top();
		r[idx(v[i])].pop();
	}

	cout << invcnt(p, 0, n) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();

	return 0;
}
