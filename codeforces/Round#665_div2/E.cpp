#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <tuple>

using namespace std;

constexpr int SL = 1e6; // side length

class segmentTree {
public:
	segmentTree(int);
	int sum(int, int);
	void add(int, int);
private:
	inline int left(int);
	inline int right(int, int, int);
	int aux_sum(int, int, int, int, int);
	void aux_add(int, int, int, int, int);
	int n; // [0 : n - 1]
	vector<int> t;
};

segmentTree::segmentTree(int _n) : n(_n) {
	t.assign(2 * n - 1, 0);
}

inline int segmentTree::left(int v) { return v + 1; }
inline int segmentTree::right(int v, int l, int m) { return v + 2 * (m - l + 1); }

int segmentTree::sum(int l, int r) {
	return aux_sum(l, r, 0, 0, n - 1);
}

int segmentTree::aux_sum(int l, int r, int v, int tl, int tr) {
	int tm = (tl + tr) / 2;
	if (l > r) return 0;
	else if (l == tl && r == tr) return t[v];
	else return aux_sum(l, min(tm, r), left(v), tl, tm) + aux_sum(max(l, tm + 1), r, right(v, tl, tm), tm + 1, tr);
}

void segmentTree::add(int p, int inc) {
	aux_add(p, inc, 0, 0, n - 1);
}

void segmentTree::aux_add(int p, int inc, int v, int l, int r) {
	if (l == r) t[v] += inc;
	else {
		int m = (l + r) / 2;
		if (p <= m) aux_add(p, inc, left(v), l, m);
		else aux_add(p, inc, right(v, l, m), m + 1, r);
		t[v] = t[left(v)] + t[right(v, l, m)];
	}
}

bool h_cmp(tuple<int, int, int> a, tuple<int, int, int> b) {
	return get<0>(a) < get<0>(b);
}

bool v_cmp(tuple<int, int, int> a, tuple<int, int, int> b) {
	return get<1>(a) < get<1>(b) || (get<1>(a) == get<1>(b) && get<2>(a) > get<2>(b));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long long ans = 1;
	int n, m;
	cin >> n >> m;
	vector<tuple<int, int, int>> h(n), v(2 * m);
	for (int i = 0; i < n; ++i) { // horizontal segments
		int y, lx, rx;
		cin >> y >> lx >> rx;
		h[i] = make_tuple(y, lx, rx);
		if (rx - lx == SL) ++ans;
	}
	sort(h.begin(), h.end(), h_cmp);
	for (int i = 0; i < m; ++i) { // vertical segments
		int x, ly, ry;
		cin >> x >> ly >> ry;
		v[2 * i] = make_tuple(x, ly, 1);
		v[2 * i + 1] = make_tuple(x, ry, -1);
		if (ry - ly == SL) ++ans;
	}
	sort(v.begin(), v.end(), v_cmp);

	segmentTree ST(SL + 1);
	for (auto h_it = h.begin(), v_it = v.begin(); h_it != h.end() && v_it != v.end(); ) {
		if (get<0>(*h_it) < get<1>(*v_it) || (get<0>(*h_it) == get<1>(*v_it) && get<2>(*v_it) < 0)) {
			ans += ST.sum(get<1>(*h_it), get<2>(*h_it));
			++h_it;
		} else {
			ST.add(get<0>(*v_it), get<2>(*v_it));
			++v_it;
		}
	}

	cout << ans << endl;
	return 0;
}
