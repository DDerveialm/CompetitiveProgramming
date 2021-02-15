#include <iostream>
#include <vector>
#include <functional>
#include <limits>
#include <algorithm>

using namespace std;

// segment tree
template<typename T>
class SGT {
	int n;
	vector<T> t;
	inline int left(int tv) { return tv + 1; }
	// [ tv+1 : tv+2*(tm-tl)-1 ) -> left subtree
	inline int right(int tv, int tl, int tm) { return tv + 2 * (tm - tl); }

	// associative function for SGT
	function<T(const T&, const T&)> merge;
	void modify(int p, const T& x, int tv, int tl, int tr) {
		if (tl == tr - 1) t[tv] = x;
		else {
			int tm{(tl + tr) / 2}, lc{left(tv)}, rc{right(tv, tl, tm)};
			if (p < tm) modify(p, x, lc, tl, tm);
			else modify(p, x, rc, tm, tr);
			t[tv] = merge(t[lc], t[rc]);
		}
	}
	T query(int l, int r, int tv, int tl, int tr) {
		if (l == tl && r == tr) return t[tv];
		int tm{(tl + tr) / 2};
		if (r <= tm) return query(l, r, left(tv), tl, tm);
		else if (l >= tm) return query(l, r, right(tv, tl, tm), tm, tr);
		else return merge(query(l, tm, left(tv), tl, tm)
				, query(tm, r, right(tv, tl, tm), tm, tr));
	}
public:
	explicit SGT(int _n, const decltype(merge)& m) : n{_n}, t(2 * n - 1), merge(m) {}
	explicit SGT(int _n, decltype(merge)&& m) : n{_n}, t(2 * n - 1), merge(m) {}
	void modify(int p, const T& x) { modify(p, x, 0, 0, n); };
	T query(int l, int r) { return query(l, r, 0, 0, n); } // [l:r)
};

void solve() {
	array<int, 4> n;
	for (auto& x : n) cin >> x;
	array<vector<int>, 4> v{};
	for (int i{0}; i < 4; ++i) {
		v[i].assign(n[i], {});
		for (auto& x : v[i]) cin >> x;
	}

	for (int i{0}; i < 3; ++i) {
		int m;
		cin >> m;
		vector<vector<int>> d(n[i + 1]);
		while (m--) {
			int x, y;
			cin >> x >> y, --x, --y;
			d[y].push_back(x);
		}

		SGT<int> sgt{n[i], [](const int& x, const int& y){return min(x, y);}};
		for (int j{0}; j < n[i]; ++j) sgt.modify(j, v[i][j]);

		for (int j{0}; j < n[i + 1]; ++j) {
			d[j].push_back(-1), d[j].push_back(n[i]);
			sort(d[j].begin(), d[j].end());

			int mn{numeric_limits<int>::max()};
			for (int k{0}; k + 1 < d[j].size(); ++k) {
				if (d[j][k] + 1 < d[j][k + 1]) mn = min(mn, sgt.query(d[j][k] + 1, d[j][k + 1]));
			}

			if (mn != numeric_limits<int>::max()) v[i + 1][j] += mn;
			else v[i + 1][j] = numeric_limits<int>::max();
		}
	}

	int ans{*min_element(v[3].begin(), v[3].end())};

	if (ans == numeric_limits<int>::max()) cout << "-1\n";
	else cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	// cin >> t;
	while (t--) solve();

	return 0;
}
