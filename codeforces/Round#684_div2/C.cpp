#include <iostream>
#include <vector>
#include <tuple>
#include <stack>

#define fi first
#define se second

using namespace std;

void solve() {
	using pii = pair<int, int>;

	int n, m;
	cin >> n >> m;
	vector<vector<int>> t(n, vector<int>(m));
	for (auto& x : t)
		for (auto& y : x) {
			char c;
			cin >> c;
			y = c - '0';
		}

	vector<tuple<pii, pii, pii>> ans{};

	for (int j{m - 1}; j >= 2; --j) // compress to left
		for (int i{0}; i < n; ++i)
			if (t[i][j]) {
				int x;
				if (i) x = i - 1;
				else x = i + 1;
				ans.emplace_back(pii{i, j}, pii{i, j - 1}, pii{x, j - 1});
				t[i][j] = 0;
				t[i][j - 1] = !t[i][j - 1];
				t[x][j - 1] = !t[x][j - 1];
			}

	for (int i{n - 1}; i >= 2; --i) // compress to up
		for (int j{0}; j < 2; ++j)
			if (t[i][j]) {
				ans.emplace_back(pii{i, j}, pii{i - 1, 0}, pii{i - 1, 1});
				t[i][j] = 0;
				t[i - 1][0] = !t[i - 1][0];
				t[i - 1][1] = !t[i - 1][1];
			}

	stack<pii> s0{}, s1{};
	for (int i{0}; i < 2; ++i)
		for (int j{0}; j < 2; ++j)
			if (t[i][j]) s1.emplace(i, j);
			else s0.emplace(i, j);

	auto last = [&s0, &s1, &ans]() {
		stack<pii> t0{}, t1{};
		vector<pii> op{};
		if (s1.size() >= 3) { // turn three '1' to '0'
			for (int i{0}; i < 3; ++i)
				t0.push(s1.top()), op.push_back(s1.top()), s1.pop();
		} else if (s1.size() >= 1) { // turn one '1' to '0' and two '0' to '1'
			t0.push(s1.top()), op.push_back(s1.top()), s1.pop();
			t1.push(s0.top()), op.push_back(s0.top()), s0.pop();
			t1.push(s0.top()), op.push_back(s0.top()), s0.pop();
		} else return false;
		while (!s0.empty()) t0.push(s0.top()), s0.pop();
		s0 = move(t0);
		while (!s1.empty()) t1.push(s1.top()), s1.pop();
		s1 = move(t1);

		ans.emplace_back(op[0], op[1], op[2]);

		return true;
	};
	while (last()) ;

	cout << ans.size() << '\n';
	for (auto& x : ans) {
		cout << get<0>(x).fi + 1 << ' ' << get<0>(x).se + 1 << ' '
		   	<< get<1>(x).fi + 1 << ' ' << get<1>(x).se + 1 << ' '
		   	<< get<2>(x).fi + 1 << ' ' << get<2>(x).se + 1 << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
