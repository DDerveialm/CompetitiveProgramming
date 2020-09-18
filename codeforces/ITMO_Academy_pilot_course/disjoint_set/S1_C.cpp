#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Info { int set, sz, val; };

class DS { //disjoint set
public:
	explicit DS(int);
	int getID(int);
	int unionn(int, int);
	int add(int, int);
	int getVal(int);
	void deBug() {
		for (auto& x : v) cout << x.set << " ";
		cout << endl;
		for (auto& x : v) cout << x.sz << " ";
		cout << endl;
		for (auto& x : v) cout << x.val << " ";
		cout << endl;
	}
private:
	vector<Info> v;
};

DS::DS(int n) : v(n) {
	for (int i{0}; i < n; ++i)
		v[i] = {i, 1, 0};
}

int DS::getID(int x) {
	if (x == v[x].set) return x;

	auto rx{getID(v[x].set)};
	if (v[x].set != rx) {
		v[x].val += v[ v[x].set ].val;
		v[x].set = rx;
	}
	return rx;
}

int DS::unionn(int x, int y) {
	auto rx{getID(x)}, ry{getID(y)};
	if (rx != ry) {
		if (v[rx].sz < v[ry].sz) swap(rx, ry);
		v[ry].set = rx;
		v[rx].sz += v[ry].sz, v[ry].sz = 0;
		v[ry].val -= v[rx].val;
	}
	return rx;
}

int DS::add(int x, int val) {
	auto rx{getID(x)};
	v[rx].val += val;
	return rx;
}

int DS::getVal(int x) {
	auto rx{getID(x)};
	return v[x].val + (x != rx ? v[rx].val : 0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	DS ds{n};
	while (m--) {
		string op{};
		cin >> op;
		if (op == "join"s) {
			int x, y;
			cin >> x >> y, --x, --y;
			ds.unionn(x, y);
		} else if (op == "add"s) {
			int x, v;
			cin >> x >> v, --x;
			ds.add(x, v);
		} else if (op == "get"s) {
			int x;
			cin >> x, --x;
			cout << ds.getVal(x) << endl;
		}
	}

	return 0;
}
