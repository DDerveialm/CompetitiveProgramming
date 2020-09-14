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

class segmentTree {
public:
	explicit segmentTree(int);
	int rkth_1(int);
	void set(int, int);
private:
	inline int left(int);
	inline int right(int);
	void build(int, int, int);
	int aux_rkth_1(int, int, int, int);
	void aux_set(int, int, int, int, int);
	int n; // [0:n)
	vector<int> t;
};

segmentTree::segmentTree(int n) : n(n), t(2 * closest_power2(n) - 1) {
	build(0, 0, n);
}

inline int segmentTree::left(int v) { return 2 * v + 1; }
inline int segmentTree::right(int v) { return 2 * v + 2; }

void segmentTree::build(int v, int l, int r) {
	if (l == r - 1) t[v] = 1;
	else {
		int m{(l + r) / 2};
		build(left(v), l, m);
		build(right(v), m, r);
		t[v] = t[left(v)] + t[right(v)];
	}
}

int segmentTree::rkth_1(int k) {
	return aux_rkth_1(k, 0, 0, n);
}

int segmentTree::aux_rkth_1(int k, int v, int l, int r) {
	int m{(l + r) / 2};
	if (l == r - 1) return l;
	else if (t[right(v)] >= k) return aux_rkth_1(k, right(v), m, r);
	else return aux_rkth_1(k - t[right(v)], left(v), l, m);
}

void segmentTree::set(int p, int x) {
	aux_set(p, x, 0, 0, n);
}

void segmentTree::aux_set(int p, int x, int v, int l, int r) {
	if (l + 1 == r) t[v] = x;
	else {
		int m{(l + r) / 2};
		if (p < m) aux_set(p, x, left(v), l, m);
		else aux_set(p, x, right(v), m, r);
		t[v] = t[left(v)] + t[right(v)];
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> inv(n), per(n);
	for (auto& x : inv) cin >> x;

	segmentTree ST{n};
	for (int i{n - 1}; i >= 0; --i) {
		per[i] = ST.rkth_1(inv[i] + 1);
		ST.set(per[i], 0);
	}

	for (auto& x : per) cout << x + 1 << " ";
	cout << endl;

	return 0;
}
