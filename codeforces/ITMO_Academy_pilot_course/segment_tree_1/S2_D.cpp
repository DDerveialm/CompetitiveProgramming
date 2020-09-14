#include <iostream>
#include <vector>
#include <limits>

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

class segmentTree {
public:
	explicit segmentTree(vector<int>&&);
	int first_above(int, int);
	void set(int, int);
private:
	inline int left(int);
	inline int right(int);
	void build(int, int, int);
	int aux_first_above(int, int, int, int, int, int);
	void aux_set(int, int, int, int, int);
	vector<int> a;
	vector<int> t;
};

segmentTree::segmentTree(vector<int>&& vec) : a(vec), t(2 * closest_power2(a.size()) - 1) {
	build(0, 0, a.size() - 1);
}

inline int segmentTree::left(int v) { return 2 * v + 1; }
inline int segmentTree::right(int v) { return 2 * v + 2; }

void segmentTree::build(int v, int l, int r) {
	if (l == r) t[v] = a[l];
	else {
		int m{(l + r) / 2};
		build(left(v), l, m);
		build(right(v), m + 1, r);
		t[v] = max(t[left(v)], t[right(v)]);
	}
}

int segmentTree::first_above(int x, int l) {
	return aux_first_above(x, l, a.size() - 1, 0, 0, a.size() - 1);
}

int segmentTree::aux_first_above(int x, int l, int r, int v, int tl, int tr) {
	int tm{(tl + tr) / 2};
	if (l > r) return -1;
	else if (tl == tr) return (t[v] >= x ? l : -1);

	if (t[left(v)] >= x) {
		auto re{ aux_first_above(x, l, min(r, tm), left(v), tl, tm) };
		if (re != -1) return re;
	}
	return aux_first_above(x, max(l, tm + 1), r,right(v), tm + 1, tr);
}

void segmentTree::set(int p, int x) {
	aux_set(p, x, 0, 0, a.size() - 1);
}

void segmentTree::aux_set(int p, int x, int v, int l, int r) {
	if (l == r) t[v] = x;
	else {
		int m{(l + r) / 2};
		if (p <= m) aux_set(p, x, left(v), l, m);
		else aux_set(p, x, right(v), m + 1, r);
		t[v] = max(t[left(v)], t[right(v)]);
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
	while (m--) {
		int op;
		cin >> op;
		if (op == 1) {
			int i, v;
			cin >> i >> v;
			ST.set(i, v);
		} else if (op == 2) {
			int x, l;
			cin >> x >> l;
			cout << ST.first_above(x, l) << endl;
		}
	}
	
	return 0;
}
