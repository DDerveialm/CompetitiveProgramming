#include <iostream>
#include <vector>

using namespace std;

int AND(int i, int j) {
	cout << "AND " << i + 1 << ' ' << j + 1 << endl;
	int res;
	cin >> res;
	return res;
}

int OR(int i, int j) {
	cout << "OR " << i + 1 << ' ' << j + 1 << endl;
	int res;
	cin >> res;
	return res;
}

int XOR(int i, int j) {
	cout << "XOR " << i + 1 << ' ' << j + 1 << endl;
	int res;
	cin >> res;
	return res;
}

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);

	vector<int> lst(n, 0);
	int j{0}, k{0};
	for (int i{1}; i < n; ++i) {
		v[i] = XOR(0, i);
		if (v[i] == 0) j = 0, k = i;
		if (lst[v[i]]) j = lst[v[i]], k = i;
		lst[v[i]] = i;
	}
	if (k) {
		v[0] = v[j] ^ AND(j, k);
	} else {
		if (v[1] == n - 1) j = 2; // v[0] & v[1] == 0, find another pair
		else j = 1;
		for (k = j + 1; k < n; ++k) 
			if ((v[j] ^ v[k]) == n - 1) break;
		int and0j{AND(0, j)}, and0k{AND(0, k)};
		v[0] = ((v[j] + (and0j << 1)) + (v[k] + (and0k << 1)) - (n - 1)) / 2;
	}

	for (int i{1}; i < n; ++i) v[i] ^= v[0];
	cout << "! ";
	for (auto& x : v) cout << x << ' ';
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t{1};
	// cin >> t;
	while (t--) solve();

	return 0;
}
