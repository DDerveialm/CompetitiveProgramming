#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Info { int set, sz; };

class DS { //disjoint set
public:
	explicit DS(int);
	int getID(int);
	bool unionn(int, int);
private:
	vector<Info> v;
};

DS::DS(int n) : v(n + 1) {
	for (int i{0}; i < n + 1; ++i)
		v[i] = {i, 1};
}

int DS::getID(int x) {
	if (x == v[x].set) return x;

	auto rx{getID(v[x].set)};
	v[x].set = rx;
	return rx;
}

bool DS::unionn(int x, int y) {
	auto rx{getID(x)}, ry{getID(y)};
	if (rx != ry) {
		if (v[rx].sz < v[ry].sz) swap(rx, ry);
		v[ry].set = rx;
		v[rx].sz += v[ry].sz, v[ry].sz = 0;
		return true;
	} else return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	DS ds{n};
	vector<pair<int, pair<int, int>>> e;
	while (m--) {
		int u, v, w;
		cin >> u >> v >> w, --u, --v;
		e.push_back({w, {u, v}});
	}
	sort(e.begin(), e.end());

	long long w{0};
	for (auto& x : e) {
		if (ds.unionn(x.second.first, x.second.second))
			w += x.first;
	}
	cout << w << endl;

	return 0;
}
