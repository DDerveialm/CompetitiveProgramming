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
	int sum(int, int);
	void set(int, int);
private:
	inline int left(int);
	inline int right(int);
	int aux_sum(int, int, int, int, int);
	void aux_set(int, int, int, int, int);
	int n; // [0:n)
	vector<int> t;
};

segmentTree::segmentTree(int n) : n(n), t(2 * closest_power2(n) - 1, 0) {}

inline int segmentTree::left(int v) { return 2 * v + 1; }
inline int segmentTree::right(int v) { return 2 * v + 2; }

int segmentTree::sum(int l, int r) {
	return aux_sum(l, r, 0, 0, n);
}

int segmentTree::aux_sum(int l, int r, int v, int tl, int tr) {
	int tm{(tl + tr) / 2};
	if (l >= r) return 0;
	else if (l == tl && r == tr) return t[v];
	else return aux_sum(l, min(tm, r), left(v), tl, tm) + aux_sum(max(l, tm), r, right(v), tm, tr);
}

void segmentTree::set(int p, int x) {
	aux_set(p, x, 0, 0, n);
}

void segmentTree::aux_set(int p, int x, int v, int l, int r) {
	if (l == r - 1) t[v] = x;
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
	vector<int> per(n), inv(n);
	for (auto& x : per) cin >> x, --x;

	segmentTree ST{n};
	for (int i{0}; i < n; ++i) {
		inv[i] = ST.sum(per[i] + 1, n);
		ST.set(per[i], 1);
	}

	for (auto& x : inv) cout << x << " ";
	cout << endl;

	return 0;
}
