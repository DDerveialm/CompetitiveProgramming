#include <iostream>
#include <vector>

using namespace std;

int recur(vector<int> v, int i) {
	if (v.size() <= 1) return v.size();

	vector<int> s0{}, s1{};
	int S0{0}, S1{0};
	for (auto& x : v)
		if (x & (1 << i)) s1.push_back(x);
		else s0.push_back(x);
	return max(!!s1.size() + recur(s0, i - 1), !!s0.size() + recur(s1, i - 1));
}

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	cout << n - recur(move(v), 29) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();

	return 0;
}
