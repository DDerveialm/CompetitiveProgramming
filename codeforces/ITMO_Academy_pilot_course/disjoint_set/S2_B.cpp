#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Info { int set, sz, ans; };

class DS { //disjoint set
public:
	explicit DS(int);
	int getID(int);
	int unionn(int, int);
	int getAns(int);
private:
	vector<Info> v;
};

DS::DS(int n) : v(n) {
	for (int i{0}; i < n; ++i)
		v[i] = {i, 1, i};
}

int DS::getID(int x) {
	if (x == v[x].set) return x;

	auto rx{getID(v[x].set)};
	v[x].set = rx;
	return rx;
}

int DS::unionn(int x, int y) {
	auto rx{getID(x)}, ry{getID(y)};
	if (rx != ry) {
		v[ry].ans = -1;
		if (v[rx].sz < v[ry].sz) swap(rx, ry);
		v[ry].set = rx;
		v[rx].sz += v[ry].sz, v[ry].sz = 0;
		v[rx].ans = max(v[rx].ans, v[ry].ans), v[ry].ans = -1;
	}
	return rx;
}

int DS::getAns(int x) {
	return v[getID(x)].ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	DS ds{n};
	for (int i{0}; i < n; ++i) {
		int p;
		cin >> p, --p;
		auto a{ds.getAns(p)};
		cout << a + 1 << ' ';
		ds.unionn((a + 1) % n, a);
	}
	cout << endl;

	return 0;
}
