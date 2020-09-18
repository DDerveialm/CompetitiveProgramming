#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string t{}, p{};
	cin >> t >> p;
	vector<int> vec(t.size());
	for (auto& x : vec) cin >> x, --x;

	auto check = [&](int end) {
		vector<int> rm(t.size(), 0);
		for (int i{0}; i <= end; ++i) rm[vec[i]] = 1;

		int j{0};
		for (int i{0}; i < t.size(); ++i) {
			if (rm[i]) continue;
	
			if (t[i] == p[j]) ++j;
			if (j == p.size()) return true;
		}
		return false;
	};

	int l{-1}, r{static_cast<int>(t.size())};
	while (l < r - 1) {
		int m{(l + r) / 2};
		if (check(m)) l = m;
		else r = m;
	}
	cout << l + 1 << endl;
	return 0;
}
