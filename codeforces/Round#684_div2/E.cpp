#include <iostream>
#include <vector>
#include <optional>
#include <algorithm>

using namespace std;

// segment tree
// range query & range modify
template <typename T>
class SGT {
	struct node_t { T s, mn; };

	int n;
	vector<node_t> t;
	vector<optional<T>> lz;
	inline int left(int tv) { return tv + 1; }
	// [ tv+1 : tv+2*(tm-tl)-1 ) -> left subtree
	inline int right(int tv, int tl, int tm) { return tv + 2 * (tm - tl); }
	/*****differ from case to case*****/
	// query is "sum" and modify is "set" here
	inline node_t merge(const node_t& x, const node_t& y) { // associative function
		return {x.s + y.s, min(x.mn, y.mn)};
	}
	inline void update(int tv, int _n, const T& x) {
		lz[tv] = x;
		t[tv] = {_n * x, x};
	}
	/**********************************/
	void push(int tv, int tl, int tr) { // lazy propagation
		if (!lz[tv]) return;
		
		int tm{(tl + tr) / 2};
		update(left(tv), tm - tl, lz[tv].value());
		update(right(tv, tl, tm), tr - tm, lz[tv].value());
		lz[tv].reset();
	}
	void modify(int l, int r, const T& x, int tv, int tl, int tr) {
		if (l == tl && r == tr) update(tv, tr - tl, x);
		else {
			push(tv, tl, tr);
			int tm{(tl + tr) / 2};
			if (r <= tm) modify(l, r, x, left(tv), tl, tm);
			else if (l >= tm) modify(l, r, x, right(tv, tl, tm), tm, tr);
			else modify(l, tm, x, left(tv), tl, tm),
				modify(tm, r, x, right(tv, tl, tm), tm, tr);
			t[tv] = merge(t[left(tv)], t[right(tv, tl, tm)]);
		}
	}
	node_t query(int l, int r, int tv, int tl, int tr) {
		if (l == tl && r == tr) return t[tv];
		push(tv, tl, tr);
		int tm{(tl + tr) / 2};
		if (r <= tm) return query(l, r, left(tv), tl, tm);
		else if (l >= tm) return query(l, r, right(tv, tl, tm), tm, tr);
		else return merge(query(l, tm, left(tv), tl, tm), 
				query(tm, r, right(tv, tl, tm), tm, tr));
	}
public:
	explicit SGT(int _n) : n{_n}, t(2 * n - 1), lz(2 * n - 1) {}
	void modify(int l, int r, const T& x) { modify(l, r, x, 0, 0, n); } // [l:r)
	T sum(int l, int r) { return query(l, r, 0, 0, n).s; } // [l:r)
	// assume the array is non-increasing
	int bs_first_less_equal(T val) { // find first occurrence s.t. v[i] <= val
		if (!(t[0].mn <= val)) return n;
		int tv{0}, tl{0}, tr{n};
		while (tr - tl > 1) {
			push(tv, tl, tr);
			int tm{(tl + tr) / 2};
			if (t[left(tv)].mn <= val) tv = left(tv), tr = tm;
			else tv = right(tv, tl, tm), tl = tm;
		}
		return tl;
	}
	// assume prefix sum of the array is non-decreasing
	int bs_first_presum_greater(T val) { // find first position s.t. ps[i] > val
		if (!(t[0].s > val)) return n;
		int tv{0}, tl{0}, tr{n};
		while (tr - tl > 1) {
			push(tv, tl, tr);
			int tm{(tl + tr) / 2};
			if (t[left(tv)].s > val) tv = left(tv), tr = tm;
			else val -= t[left(tv)].s, tv = right(tv, tl, tm), tl = tm;
		}
		return tl;
	}
};

void solve() {
	int n, q;
	cin >> n >> q;

	SGT<long long> sgt{n};
	for (int i{0}; i < n; ++i) {
		long long x;
		cin >> x;
		sgt.modify(i, i + 1, x);
	}

	while (q--) {
		int t, x; long long y;
		cin >> t >> x >> y, --x;
		if (t == 1) { // for each 1 <= i <= x, set v[i] = max(v[i], y);
			int l{sgt.bs_first_less_equal(y)};
			if (l < x + 1) sgt.modify(l, x + 1, y); // [l:x+1)
		} else if (t == 2) {
			int p{x}, ans{0};
			while (true) {
				int l{max(p, sgt.bs_first_less_equal(y))};
				if (l == n) break;

				int r{sgt.bs_first_presum_greater(sgt.sum(0, l) + y)}; // find contiguous segment s.t. sum([l:r)) <= y
				y -= sgt.sum(l, r), ans += r - l;
				p = r;
			}
			cout << ans << '\n';
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	// cin >> t;
	while (t--) solve();

	return 0;
}
