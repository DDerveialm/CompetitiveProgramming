#include <iostream>
#include <vector>
#include <functional>
#include <optional>

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
    void modify(int p, T x, int tv, int tl, int tr) {
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
    void modify(int p, T x) { modify(p, x, 0, 0, n); };
    T query(int l, int r) {
        if (l >= r) return {}; //
        return query(l, r, 0, 0, n);
    } // [l:r)
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	SGT<long long> sgt{n, plus<long long>{}};
	for (int i{0}; i < n; ++i) {
		long long x;
		cin >> x;
		sgt.modify(i, x);
	}

	while (m--) {
		int op, v1, v2;
		cin >> op >> v1 >> v2;
		if (op == 1) sgt.modify(v1, v2);
		else if (op == 2) cout << sgt.query(v1, v2) << endl;
	}
	
	return 0;
}
