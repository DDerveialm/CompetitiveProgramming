#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n;
	cin >> n;

	vector<long long> d(n);
	for (auto& x : d) cin >> x;
	long long a0{d[0]};
	long long K{0};
	for (int i{n - 1}; i >= 1; --i) {
		d[i] -= d[i - 1];
		K += max(0ll, d[i]);
	}
	if (a0 + K >= 0) cout << (a0 + K + 1) / 2 << endl; // initial value
	else cout << (a0 + K) / 2 << endl;

	int q;
	cin >> q;
	while (q--) {
		int l, r;
		long long x;
		cin >> l >> r >> x, --l, --r;

		if (l == 0) a0 += x;
		else {
			K -= max(0ll, d[l]);
			d[l] += x;
			K += max(0ll, d[l]);
		}

		if (r + 1 < n) {
			K -= max(0ll, d[r + 1]);
			d[r + 1] -= x;
			K += max(0ll, d[r + 1]);
		}

		// max(c1, a1 - c1 + K);
		if (a0 + K >= 0) cout << (a0 + K + 1) / 2 << endl;
		else cout << (a0 + K) / 2 << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();

	return 0;
}
