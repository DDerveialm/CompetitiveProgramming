#include <iostream>
#include <vector>

using namespace std;

bool check(int k, const vector<long long>& vec, long long n) {
	long long s{0};
	for (auto& x : vec) s += min(n, x);
	if ((s / k) >= n) return true;
	else return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int k, n;
	cin >> k >> n;
	vector<long long> vec(n);
	long long s{0};
	for (auto& x : vec) cin >> x, s += x;
	long long l{0}, r{(s + k - 1) / k + 1};
	while (l < r - 1) {
		long long m{(l + r) / 2};
		if (check(k, vec, m)) l = m;
		else r = m;
	}
	cout << l << endl;
	return 0;
}
