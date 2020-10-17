#include <iostream>
#include <queue>

using namespace std;

long long cut(long long l, int p) {
	long long res{0};
	res += (l % p) * (l / p + 1) * (l / p + 1);
	res += (p - l % p) * (l / p) * (l / p);
	return res;
}

void solve() {
	int n, k;
	cin >> n >> k;
	vector<long long> v(n);
	priority_queue<pair<long long, pair<long long, int>>> pq{};
	for (int i{0}; i < n; ++i) {
		long long x;
		cin >> x;
		pq.push({cut(x, 1) - cut(x, 2), {x, 1}});
	}

	for (int i{n}; i < k; ++i) {
		auto mx{pq.top()};
		pq.pop();
		++mx.second.second;
		mx.first = cut(mx.second.first, mx.second.second) - cut(mx.second.first, mx.second.second + 1);
		pq.push(mx);
	}

	long long ans{0};
	while (!pq.empty()) {
		auto t{pq.top()};
		pq.pop();
		ans += cut(t.second.first, t.second.second);
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();

	return 0;
}
