#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int bs(const vector<int>& vec, int q1, int q2) {
	int l{0}, r{int(vec.size()) + 1};
	while (l < r - 1) { // first which is not less than q1
		int m{(l + r) / 2};
		if (vec[m - 1] < q1) l = m;
		else r = m;
	}
	int lower_bound{l};

	l = 0, r = vec.size() + 1;
	while (l < r - 1) { // first which is greater than q2
		int m{(l + r) / 2};
		if (vec[m - 1] <= q2) l = m;
		else r = m;
	}
	int upper_bound{l};
	return upper_bound - lower_bound;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> vec(n);
	for (auto& x : vec) cin >> x;
	sort(vec.begin(), vec.end());

	int k;
	cin >> k;
	while (k--) {
		int q1, q2;
		cin >> q1 >> q2;
		cout << bs(vec, q1, q2) << endl;
	}

	return 0;
}
