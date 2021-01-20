#include <iostream>
#include <vector>

using namespace std;

vector<bool> p(30000, true);

void build_table() {
	p[0] = p[1] = false;
	for (int i{2}; i < p.size(); ++i) {
		if (!p[i]) continue;
		for (int j{i * i}; j < p.size(); j += i)
			p[j] = false;
	}
}

void solve() {
	int d;
	cin >> d;

	int x{1 + d};
	while (!p[x]) ++x;
	int y{x + d};
	while (!p[y]) ++y;

	cout << x * y << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	build_table();

	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
