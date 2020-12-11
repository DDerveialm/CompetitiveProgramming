#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Property{ int mn, mx, sz; };

class DS { // disjoint set
public:
	explicit DS(int);
	const Property& getInfo(int); // parameter should be ID
	int getID(int);
	int unionn(int, int);
	void deBug() {
		for (auto& x : set) cout << x << " ";
		cout << endl;
		for (auto& x : p) cout << "{" << x.mn << ", " << x.mx << ", " << x.sz << "} ";
		cout << endl << endl;
	}
private:
	vector<int> set;
   	vector<Property> p;
};

DS::DS(int n) : set(n), p(n) {
	for (int i{0}; i < n; ++i)
		set[i] = i, p[i] = {i, i, 1};
}

const Property& DS::getInfo(int ID) { return p[ID]; }

int DS::getID(int x) {
	if (x == set[x]) return x;

	auto r{getID(set[x])};
	set[x] = r;
	return r;
}

int DS::unionn(int x, int y) {
	auto rx{getID(x)}, ry{getID(y)};
	if (rx != ry) {
		if (p[rx].sz < p[ry].sz) swap(rx, ry);
		set[ry] = rx;
		p[rx] = {min(p[rx].mn, p[ry].mn), max(p[rx].mx, p[ry].mx), p[rx].sz + p[ry].sz}, p[ry] = {};
	}
	return rx;
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
		if (op == "union"s) {
			int u, v;
			cin >> u >> v, --u, --v;
			ds.unionn(u, v);
		} else if (op == "get"s) {
			int u;
			cin >> u, --u;
			auto p{ds.getInfo(ds.getID(u))};
			cout << p.mn + 1 << " " << p.mx + 1 << " " << p.sz << endl;
		}
	}

	return 0;
}
