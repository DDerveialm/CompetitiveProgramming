#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

void solve() {
	int n, q;
	cin >> n >> q;
	
	set<int> p{};
	multiset<int> d{};
	for (int i{0}; i < n; ++i) {
		int x;
		cin >> x;
		p.insert(x);
	}
	for (auto it{p.begin()}; next(it) != p.end(); ++it) d.insert(*it - *next(it));
	cout << *prev(p.end()) - *p.begin() + (d.empty() ? 0 : *d.begin()) << endl; // initial

	while (q--) {
		int op, x;
		cin >> op >> x;
		if (op == 0) { // rm x
			auto it{p.find(x)};

			if (it != p.begin()) d.erase(d.find( *prev(it) - *it ));
			if (next(it) != p.end()) d.erase(d.find( *it - *next(it) ));

			if (it != p.begin() && next(it) != p.end()) d.insert( *prev(it) - *next(it) );

			p.erase(it);
		} else if (op == 1) { // add x
			auto it{p.lower_bound(x)};

			if (it != p.begin() && it != p.end()) d.erase(d.find( *prev(it) - *it ));

			if (it != p.begin()) d.insert( *prev(it) - x );
			if (it != p.end()) d.insert( x - *it );

			p.insert(x);
		}
		if (!p.empty()) cout << *prev(p.end()) - *p.begin() + (d.empty() ? 0 : *d.begin()) << endl;
		else cout << 0 << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();

	return 0;
}
