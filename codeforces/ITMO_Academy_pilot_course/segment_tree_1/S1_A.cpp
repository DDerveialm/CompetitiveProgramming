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
	explicit segmentTree(vector<int>&&);
	long long sum(int, int);
	void set(int, int);
private:
	inline int left(int);
	inline int right(int);
	void build(int, int, int);
	long long aux_sum(int, int, int, int, int);
	void aux_set(int, int, int, int, int);
	vector<int> a;
	vector<long long> t;
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
		t[v] = t[left(v)] + t[right(v)];
	}
}

long long segmentTree::sum(int l, int r) {
	return aux_sum(l, r, 0, 0, a.size() - 1);
}

long long segmentTree::aux_sum(int l, int r, int v, int tl, int tr) {
	int tm{(tl + tr) / 2};
	if (l > r) return 0;
	else if (l == tl && r == tr) return t[v];
	else return aux_sum(l, min(tm, r), left(v), tl, tm) + aux_sum(max(l, tm + 1), r, right(v), tm + 1, tr);
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
		t[v] = t[left(v)] + t[right(v)];
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
		int op, v1, v2;
		cin >> op >> v1 >> v2;
		if (op == 1) {
			ST.set(v1, v2);
		} else if (op == 2) {
			cout << ST.sum(v1, v2 - 1) << endl;
		}
	}
	
	return 0;
}
