#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool is_pri(int n) {
	for (int i{2}; i * i <= n; ++i)
		if (n % i == 0) return false;
	return true;
}

void solve() {
	int n;
	cin >> n;

	vector<int> d{}; // divisor
	for (int i{2}; i * i <= n; ++i)
		if (n % i == 0) {
			d.push_back(i);
			if (n / i != i) d.push_back(n / i);
		}
	d.push_back(n);
	sort(d.begin(), d.end());

	if (d.size() == 3 && is_pri(d[0]) && is_pri(d[1])) { // need one operation
		for (auto& x : d) cout << x << " ";
	   	cout << endl << 1 << endl;
		return ;
	}

	vector<int> pd{}; // prime divisor
	for (int i{2}; i * i <= n; ++i)
		if (n % i == 0) {
			pd.push_back(i);
			while (n % i == 0) n /= i;
		}
	if (n > 1) pd.push_back(n);

	map<int, bool> used{};
	vector<int> cn(pd.size()); // connect number (p1 * p2)
	for (int i{0}; i < pd.size(); ++i) {
		int p1{pd[i]}, p2{pd[(i + 1) % pd.size()]};
		for (int j{0}; j < d.size(); ++j) {
			if (!used[d[j]] && d[j] % (p1 * p2) == 0) {
				used[d[j]] = true;
				cn[i] = d[j];
				break;
			}
		}
	}
	
	for (int i{0}; i < pd.size(); ++i) {
		int p{pd[i]};
		used[p] = true;
		cout << p << " ";
		for (int j{0}; j < d.size(); ++j) {
			if (!used[d[j]] && d[j] % p == 0) {
				used[d[j]] = true;
				cout << d[j] << " ";
			}
		}
		cout << cn[i] << " ";
	}
	cout << endl << 0 << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}
