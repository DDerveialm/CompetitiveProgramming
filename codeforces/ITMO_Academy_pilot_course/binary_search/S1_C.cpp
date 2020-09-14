#include <iostream>
#include <vector>

using namespace std;

int bs(const vector<int>& vec, int q) {
	int l{0}, r{int(vec.size()) + 1}; // min index that vec[i] >= q is in [0, n + 1)
	while (l < r - 1) {
		int m{(l + r) / 2};
		if (vec[m - 1] < q) l = m;
		else r = m;
	}
	return l + 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;
	vector<int> vec(n);
	for (auto& x : vec) cin >> x;
	while (k--) {
		int q;
		cin >> q;
		cout << bs(vec, q) << endl;
	}

	return 0;
}
