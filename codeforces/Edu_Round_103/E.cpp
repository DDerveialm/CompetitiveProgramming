#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <optional>
#include <unordered_map>

using namespace std;

// topological sort 1
optional<vector<int>> top_sort(vector<vector<int>>& adj) {
    vector<int> res{};
    int n{static_cast<int>(adj.size())}; vector<int> cnt(n, 0); // predecessor count
    for (int u{0}; u < n; ++u)
        for (auto& v : adj[u]) ++cnt[v];
    
    queue<int> qu{};
    for (int u{0}; u < n; ++u) if (!cnt[u]) qu.push(u);
    while (!qu.empty()) {
        auto u{qu.front()}; qu.pop();
        res.push_back(u);
        
        for (auto& v : adj[u]) {
            --cnt[v];
            if (!cnt[v]) qu.push(v);
        }
    }
    
    for (int u{0}; u < n; ++u) if (cnt[u]) return nullopt;
    return res;
}

namespace E {
	vector<string> res{};
	void dfs(string& s, int p = 0) {
		if (p >= s.size()) res.push_back(s);
		else {
			dfs(s, p + 1);

			char t{s[p]}; 
			s[p] = '_', dfs(s, p + 1);
			s[p] = t;
		}
	}
	vector<string> all_ptn(string& s) {
		dfs(s);
		return move(res);
	}
}

void solve() {
	int k, n, m;
	cin >> n >> m >> k;
	vector<string> p(n), s(m);
	vector<int> t(m);
	for (auto& x : p) cin >> x;
	for (int i{0}; i < m; ++i) cin >> s[i] >> t[i], --t[i];

	auto match = [&k](const string& a, const string& b) {
		for (int i{0}; i < k; ++i)
			if (a[i] != '_' && b[i] != '_' && a[i] != b[i]) return false;
		return true;
	};
	for (int i{0}; i < m; ++i) // check if p[t[i]] 
		if (!match(s[i], p[t[i]])) {
			cout << "NO\n";
			return ;
		}

	unordered_multimap<string, int> mm{};
	for (int i{0}; i < n; ++i) mm.emplace(p[i], i);

	vector<vector<int>> adj(n);
	for (int i{0}; i < m; ++i) {
		for (auto& ptn : E::all_ptn(s[i])) {
			auto [b, e]{mm.equal_range(ptn)};
			for (auto it{b}; it != e; ++it) {
				auto& [_, idx]{*it};
				if (idx != t[i]) adj[t[i]].push_back(idx);
			}
		}
	}

	auto res{top_sort(adj)};
	if (res) {
		cout << "YES\n";
		for (auto& x : res.value()) cout << x + 1 << ' ';
		cout << '\n';
	} else cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	// cin >> t;
	while (t--) solve();

	return 0;
}
