#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

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
	T query(int l, int r) {
		if (l >= r) return {}; //
		return query(l, r, 0, 0, n);
	} // [l:r)
};

void solve() {
	struct data_t {
		int p, mn, mx;
		data_t()=default;
		data_t(int _p, int _mn, int _mx) : p{_p}, mn{_mn}, mx{_mx} {}
	};
	auto merge = [](const data_t& d, const data_t& d2) -> data_t {
		return {d.p + d2.p, min(d.mn, d.p + d2.mn), max(d.mx, d.p + d2.mx)};
	};

	int n, m;
   	cin >> n >> m;

	SGT<data_t> sgt{n, merge};

	for (int i{0}; i < n; ++i) {
		data_t x{};
		char c; cin >> c;
		if (c == '+') x.p = 1, x.mx = 1;
		else if (c == '-') x.p = -1, x.mn = -1;

		sgt.modify(i, x);
	}

	while (m--) {
		int l, r;
		cin >> l >> r, --l, --r;

		auto res{merge(sgt.query(0, l), sgt.query(r + 1, n))};

		cout << res.mx - res.mn + 1 << '\n';
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
