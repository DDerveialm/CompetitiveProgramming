#include <iostream>
#include <vector>
#include <array>
#include <queue>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	array<queue<int>, 4> qu{};
	for (int i{0}; i < n; ++i) cin >> v[i], qu[v[i]].push(i);

	bool pos{true};
	vector<pair<int, int>> ans{};
	vector<int> row(n, 0);
	int r{0};
	for (int i{0}; i < n; ++i) {
		if (qu[v[i]].front() == i) qu[v[i]].pop();

		if (v[i] == 1) {
			if (!row[i]) ans.emplace_back(++r, i + 1);
		} else if (v[i] == 2) {
			auto j{row[i] ? row[i] : ++r};
			if (!row[i]) ans.emplace_back(j, i + 1); // first
			if (!qu[1].empty()) row[qu[1].front()] = j, ans.emplace_back(j, qu[1].front() + 1), qu[1].pop(); // second
			else pos = false;
		} else if (v[i] == 3) {
			auto j{row[i] ? row[i] : ++r};
			if (!row[i]) ans.emplace_back(j, i + 1); // first
			if (!qu[3].empty()) {
				ans.emplace_back(j, qu[3].front() + 1); // second
				ans.emplace_back(++r, qu[3].front() + 1); // thrid
				row[qu[3].front()] = r;
				qu[3].pop();
			} else if (!qu[2].empty()) ans.emplace_back(j, qu[2].front() + 1), ans.emplace_back(++r, qu[2].front() + 1), row[qu[2].front()] = r, qu[2].pop();
			else if (!qu[1].empty()) ans.emplace_back(j, qu[1].front() + 1),ans.emplace_back(++r, qu[1].front() + 1), row[qu[1].front()] = r, qu[1].pop();
			else pos = false;
		}
	}

	if (pos) {
		cout << ans.size() << '\n';
		for (auto& x : ans) cout << x.first << ' ' << x.second << '\n';
	} else cout << "-1\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();

	return 0;
}
