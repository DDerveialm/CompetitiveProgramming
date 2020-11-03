#include <iostream>
#include <vector>

using namespace std;

int closest_power2(int x) {
	x -= 1;
	x |= x >> 1;
	x |= x >> 2;
	x |= x >> 4;
	x |= x >> 8;
	x |= x >> 16;
	x += 1;
	return x;
}

class segTree {
	int n;
	vector<int> t{};
	inline int left(const int& v) { return 2 * v + 1; }
	inline int right(const int& v) { return 2 * v + 2; }
	void _modify(int p, int x, int tv, int tl, int tr) {
		if (tr - tl == 1) t[tv] = x;
		else {
			int tm{(tl + tr) / 2};
			if (p < tm) _modify(p, x, left(tv), tl, tm);
			else _modify(p, x, right(tv), tm, tr);
			t[tv] = min(t[left(tv)], t[right(tv)]);
		}
	}
	int _getMin(int l, int r, int tv, int tl, int tr) {
		int tm{((tl + tr) / 2)};
		if (r - l <= 0) return n;
		if (l == tl && r == tr) return t[tv];
		else return min(_getMin(l, min(tm, r), left(tv), tl, tm), _getMin(max(l, tm), r, right(tv), tm, tr));
	}
public:
	explicit segTree(int n) : n{n}, t(2 * closest_power2(n), n) {}
	void modify(int p, int x) { _modify(p, x, 0, 0, n); }
	int getMin(int l, int r) { return _getMin(l, r, 0, 0, n); }
};

void solve() {
	int n;
	cin >> n;
	vector<int> v(n), last(n + 1, -1), pre(n);
	vector<bool> e(n + 2, false);
	for (int i{0}; i < n; ++i) {
		cin >> v[i], --v[i];
		pre[i] = last[v[i]];
		last[v[i]] = i;
	}

	segTree st{n + 1};
	for (int i{0}; i <= n; ++i) st.modify(i, last[i]);
	for (int i{0}; i <= n; ++i)
		if (last[i] < n - 1 && st.getMin(0, i) > last[i]) e[i] = true;
	for (int i{n - 1}; i >= 0; --i) {
		if (pre[i] < i - 1 && st.getMin(0, v[i]) > pre[i]) e[v[i]] = true;
		st.modify(v[i], pre[i]);
	}

	int ans{0};
	while (e[ans]) ++ans;
	cout << ans + 1 << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();

	return 0;
}
