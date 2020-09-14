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
	explicit segmentTree(int n);
	long long sum(int, int);
	void add(int, int);
private:
	inline int left(int);
	inline int right(int);
	long long aux_sum(int, int, int, int, int);
	void aux_add(int, int, int, int, int);
	int n;
	vector<long long> t;
};

segmentTree::segmentTree(int n) : n(n), t(2 * closest_power2(n) - 1, 0) {}

inline int segmentTree::left(int v) { return 2 * v + 1; }
inline int segmentTree::right(int v) { return 2 * v + 2; }

long long segmentTree::sum(int l, int r) {
	return aux_sum(l, r, 0, 0, n);
}

long long segmentTree::aux_sum(int l, int r, int v, int tl, int tr) {
	int tm{(tl + tr) / 2};
	if (l >= r) return 0;
	else if (l == tl && r == tr) return t[v];
	else return aux_sum(l, min(tm, r), left(v), tl, tm) + aux_sum(max(l, tm), r, right(v), tm, tr);
}

void segmentTree::add(int p, int ch) {
	aux_add(p, ch, 0, 0, n);
}

void segmentTree::aux_add(int p, int ch, int v, int l, int r) {
	if (l == r - 1) t[v] += ch;
	else {
		int m{(l + r) / 2};
		if (p < m) aux_add(p, ch, left(v), l, m);
		else aux_add(p, ch, right(v), m, r);
		t[v] = t[left(v)] + t[right(v)];
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	segmentTree ST{n + 1};
	while (m--) {
		int op;
		cin >> op;
		if (op == 1) {
			int l, r, v;
			cin >> l >> r >> v;
			ST.add(l, v);
			ST.add(r, -1 * v);
		} else if (op == 2) {
			int i;
			cin >> i;
			cout << ST.sum(0, i + 1) << endl;
		}
	}
	
	return 0;
}
