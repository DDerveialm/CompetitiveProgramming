#include <iostream>
#include <vector>

using namespace std;

bool bs(const vector<int>& vec, int q) {
	int l{0}, r{int(vec.size())};
	while (l < r) {
		int m{(l + r) / 2};
		if (vec[m] == q) return true;
		else if (vec[m] < q) l = m + 1;
		else r = m;
	}
	return false;
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
		if (bs(vec, q)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}
