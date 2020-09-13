#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

namespace T {
	vector<vector<int>> adj{};
	vector<int> rad{};
	vector<int> size{};
	vector<int> fa{};
	int n, mn, cent1, cent2;
	void read() {
		cin >> n;
		adj.assign(n, {});
		rad.assign(n, 0);
		size.assign(n, 0);
		fa.assign(n, 0);
		mn = n;
		cent1 = cent2 = -1;
		for (int i{0}; i < n - 1; ++i) {
			int x, y;
			cin >> x >> y, --x, --y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
	}
	void dfs(int x, int z = -1) {
		size[x] = 1;
		fa[x] = z;
		for (auto& y : adj[x]) {
			if (y == z) continue;
			dfs(y, x);
			size[x] += size[y];
			rad[x] = max(rad[x], size[y]);
		}
		rad[x] = max(n - size[x], rad[x]);
		if (rad[x] < mn) mn = rad[x], cent1 = x, cent2 = -1;
		else if (rad[x] == mn) cent2 = x;
	}

	int dfs2(int x, int z) {
		fa[x] = z;
		for (auto& y : adj[x]) {
			if (y == z) continue;
			return dfs2(y, x);
		}
		return x;
	}

	void find_centroid() { dfs(0); }
	bool is_centriod_unique() { return cent2 == -1; }
	pair<pair<int, int>, pair<int, int>> make_centroid_unique() {
		if (fa[cent2] != cent1) swap(cent1, cent2);
		auto leaf{dfs2(cent2, cent1)};
		return {{fa[leaf], leaf}, {cent1, leaf}};
	}

};

void solve() {
	T::read();
	T::find_centroid();
	if (T::is_centriod_unique()) {
		cout << "1 " << T::adj[0].front() + 1 << endl;
		cout << "1 " << T::adj[0].front() + 1 << endl;
	} else {
		pair<int, int> rm, add;
		tie(rm, add) = T::make_centroid_unique();
		cout << rm.first + 1 << " " << rm.second + 1 << endl;
		cout << add.first + 1 << " " << add.second + 1 << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}
