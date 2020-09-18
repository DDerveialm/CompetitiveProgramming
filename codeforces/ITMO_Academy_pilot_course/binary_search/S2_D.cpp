#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

bool check(long long m, const vector<tuple<long long, long long, long long>>& vec, long long t) {
	long long s{0};
	for (auto& x : vec) {
		s += (t / (get<0>(x) * get<1>(x) + get<2>(x))) * get<1>(x);
		s += min(get<1>(x), (t % (get<0>(x) * get<1>(x) + get<2>(x))) / get<0>(x));
	}
	if (s >= m) return true;
	else return false;
}

vector<long long> arrange(long long m, const vector<tuple<long long, long long, long long>>& vec, long long t) {
	vector<long long> ret(vec.size(), 0);
	for (int i{0}; i < vec.size(); ++i) {
		long long w{0};
		w += (t / (get<0>(vec[i]) * get<1>(vec[i]) + get<2>(vec[i]))) * get<1>(vec[i]);
		w += min(get<1>(vec[i]), (t % (get<0>(vec[i]) * get<1>(vec[i]) + get<2>(vec[i]))) / get<0>(vec[i]));
		ret[i] += min(m, w);
		m -= w;
		if (m <= 0) break;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	long long t, n;
	cin >> t >> n;
	vector<tuple<long long, long long, long long>> vec(n);
	for (auto& x : vec) cin >> get<0>(x) >> get<1>(x) >> get<2>(x);
	long long l{0}, r{static_cast<long long>(2e7)};
	while (l < r - 1) {
		long long m{(l + r) / 2};
		if (check(t, vec, m - 1)) r = m;
		else l = m;
	}
	cout << l << endl;
	auto ans{arrange(t, vec, l)};
	for (auto& x : ans) cout << x << " ";
	cout << endl;
	return 0;
}
