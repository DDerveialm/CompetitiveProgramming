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
	int kth_1(int);
	void flip(int);
private:
	inline int left(int);
	inline int right(int);
	void build(int, int, int);
	int aux_kth_1(int, int, int, int);
	void aux_flip(int, int, int, int);
	vector<int> a;
	vector<int> t;
};

segmentTree::segmentTree(vector<int>&& vec) : a(vec), t(2 * closest_power2(a.size()) - 1, 0) {
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

int segmentTree::kth_1(int k) {
	return aux_kth_1(k, 0, 0, a.size() - 1);
}

int segmentTree::aux_kth_1(int k, int v, int l, int r) {
	int m{(l + r) / 2};
	if (l == r) return l;
	else if (k <= t[left(v)]) return aux_kth_1(k, left(v), l, m);
	else return aux_kth_1(k - t[left(v)], right(v), m + 1, r);
}

void segmentTree::flip(int p) {
	aux_flip(p, 0, 0, a.size() - 1);
}

void segmentTree::aux_flip(int p, int v, int l, int r) {
	if (l == r) t[v] = (t[v] == 1 ? 0 : 1);
	else {
		int m{(l + r) / 2};
		if (p <= m) aux_flip(p, left(v), l, m);
		else aux_flip(p, right(v), m + 1, r);
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
		int op, v;
		cin >> op >> v;
		if (op == 1) {
			ST.flip(v);
		} else if (op == 2) {
			cout << ST.kth_1(v + 1) << endl;
		}
	}
	
	return 0;
}
