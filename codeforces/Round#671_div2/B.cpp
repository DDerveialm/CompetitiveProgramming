#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void solve(const vector<long long>& cost) {
	long long x;
	cin >> x;
	long long ans{0};
	for (auto& e : cost) {
		if (x < e) break;
		++ans;
		x -= e;
	}
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<long long> cost;
	cost.push_back(1);
	for (int i{1}; ; ++i) {
		auto nxt = cost.back() * 2 + pow(2, 2 * i); // (2 ^ i) ^ 2
		if (nxt <= 1e18) cost.push_back(nxt);
		else break;
	}

	int t;
	cin >> t;
	while (t--) solve(cost);

	return 0;
}
