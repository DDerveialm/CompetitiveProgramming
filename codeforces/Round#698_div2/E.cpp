#include <iostream>
#include <vector>
#include <optional>
#include <stack>

using namespace std;

// segment tree
// range query & range modify
template <typename T>
class SGT {
	int n;
	vector<T> t;
	vector<optional<T>> lz;
	inline int left(int tv) { return tv + 1; }
	// [ tv+1 : tv+2*(tm-tl)-1 ) -> left subtree
	inline int right(int tv, int tl, int tm) { return tv + 2 * (tm - tl); }
	/*****differ from case to case*****/
	inline T merge(const T& x, const T& y) { // associative function
		return x + y;
	}
	void update(int tv, int _n, const T& x) {
		lz[tv] = x;
		t[tv] = _n * x;
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
	T query(int l, int r, int tv, int tl, int tr) {
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
	T query(int l, int r) { return query(l, r, 0, 0, n); } // [l:r)
};

void solve() {
	int n, q;
	cin >> n >> q;

	vector<int> v(n);
	for (int i{0}; i < n; ++i) {
		char x; cin >> x;
		v[i] = x - '0';
	}

	SGT<int> sgt{n};
	for (int i{0}; i < n; ++i) {
		char x; cin >> x;
		sgt.modify(i, i + 1, x - '0');
	}

	stack<pair<int, int>> stk{};
	while (q--) {
		int l, r;
		cin >> l >> r, --l; // --r, ++r;
		stk.emplace(l, r);
	}

	while (!stk.empty()) {
		auto [l, r]{stk.top()}; stk.pop();

		auto s{sgt.query(l, r)};
		if (s * 2 == r - l) {
			cout << "NO\n";
			return ;
		}

		if (s * 2 > r - l) sgt.modify(l, r, 1);
		else sgt.modify(l, r, 0);
	}

	for (int i{0}; i < n; ++i)
		if (sgt.query(i, i + 1) != v[i]) {
			cout << "NO\n";
			return ;
		}
	cout << "YES\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
