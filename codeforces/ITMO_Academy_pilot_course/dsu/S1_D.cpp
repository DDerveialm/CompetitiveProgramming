#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

class DS { //disjoint set
public:
	explicit DS(int);
	int getID(int);
	bool unionn(int, int);
	void cut(int, int);
	void deBug() {
		for (auto& x : set) cout << x << " ";
		cout << endl;
	}
private:
	vector<int> set;
};

DS::DS(int n) : set(n) {
	for (int i{0}; i < n; ++i)
		set[i] = i;
}

int DS::getID(int x) {
	if (x == set[x]) return x;
	else return getID(set[x]);
}

bool DS::unionn(int x, int y) {
	if (getID(x) != getID(y)) {
		set[y] = x;
		return true;
	} else return false;
}

void DS::cut(int x, int y) {
	if (y == set[x]) swap(x, y);
	if (x != set[y]) cerr << "Err!!" << endl;
	if (x == set[y]) set[y] = y;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, k;
	cin >> n >> m >> k;
	DS ds{n};
	set<pair<int, int>> saved{};
	while (m--) {
		int u, v;
		cin >> u >> v, --u, --v;
		if (!ds.unionn(u, v)) saved.insert({u, v}); // save edges unused
	}
	while (k--) {
		string op{};
		int u, v;
		cin >> op >> u >> v, --u, --v;
		if (op == "cut"s) {
			auto it1{saved.find({u, v})}, it2{saved.find({v, u})};
			if (it1 != saved.end()) saved.erase(it1); // if edge unsued, just remove it
			else if (it2 != saved.end()) saved.erase(it2);
			else {
				ds.cut(u, v); // remove from disjoint set
				for (auto& e : saved) // try to use edges unused
					if (ds.unionn(e.first, e.second)) {
						saved.erase(e);
						break;
					}
			}
		} else if (op == "ask"s) {
			if (ds.getID(u) == ds.getID(v)) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}

	return 0;
}
