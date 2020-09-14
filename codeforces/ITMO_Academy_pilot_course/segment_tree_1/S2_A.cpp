#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct info {
	explicit info() = default;
	explicit info(long long x) : pre{max(0ll, x)}, suf{max(0ll, x)}, tot{x}, mx{max(0ll, x)} {}
	long long pre, suf, tot, mx;
};

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

class segmentTree {
public:
	explicit segmentTree(vector<int>&&);
	long long maxsum(int, int);
	void set(int, int);
private:
	inline int left(int);
	inline int right(int);
	void build(int, int, int);
	long long aux_maxsum(int, int, int, int, int);
	void aux_set(int, int, int, int, int);
	vector<int> a;
	vector<info> t;
};

segmentTree::segmentTree(vector<int>&& vec) : a(vec), t(2 * closest_power2(a.size()) - 1) {
	build(0, 0, a.size() - 1);
}

inline int segmentTree::left(int v) { return 2 * v + 1; }
inline int segmentTree::right(int v) { return 2 * v + 2; }

void segmentTree::build(int v, int l, int r) {
	if (l == r) {
		t[v] = info{a[l]};
	} else {
		int m{(l + r) / 2};
		build(left(v), l, m);
		build(right(v), m + 1, r);

		t[v].pre = max(t[left(v)].pre, t[left(v)].tot + t[right(v)].pre);
		t[v].suf = max(t[left(v)].suf + t[right(v)].tot, t[right(v)].suf);
		t[v].tot = t[left(v)].tot + t[right(v)].tot;
		t[v].mx = max(max(t[left(v)].mx, t[right(v)].mx), t[left(v)].suf + t[right(v)].pre);
	}
}

long long segmentTree::maxsum(int l, int r) {
	return aux_maxsum(l, r, 0, 0, a.size() - 1);
}

long long segmentTree::aux_maxsum(int l, int r, int v, int tl, int tr) {
	int tm{(tl + tr) / 2};
	if (l > r) return numeric_limits<long long>::min();
	else if (l == tl && r == tr) return t[v].mx;
	else return max(aux_maxsum(l, min(tm, r), left(v), tl, tm), aux_maxsum(max(l, tm + 1), r, right(v), tm + 1, tr));
}

void segmentTree::set(int p, int x) {
	aux_set(p, x, 0, 0, a.size() - 1);
}

void segmentTree::aux_set(int p, int x, int v, int l, int r) {
	if (l == r) {
		t[v] = info{x};
	} else {
		int m{(l + r) / 2};
		if (p <= m) aux_set(p, x, left(v), l, m);
		else aux_set(p, x, right(v), m + 1, r);

		t[v].pre = max(t[left(v)].pre, t[left(v)].tot + t[right(v)].pre);
		t[v].suf = max(t[left(v)].suf + t[right(v)].tot, t[right(v)].suf);
		t[v].tot = t[left(v)].tot + t[right(v)].tot;
		t[v].mx = max(max(t[left(v)].mx, t[right(v)].mx), t[left(v)].suf + t[right(v)].pre);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> vec(n);
	for (auto& x : vec) cin >> x;
	segmentTree ST{move(vec)};
	cout << ST.maxsum(0, n - 1) << endl; // initial
	while (m--) {
		int i, v;
		cin >> i >> v;
		ST.set(i, v);
		cout << ST.maxsum(0, n - 1) << endl;
	}
	
	return 0;
}
