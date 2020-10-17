#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<char> v(n);
	for (auto& x : v) cin >> x;

	vector<int> p(n + 1, -1);
	long long ans{0}, cum{0}, cont{0};
	for (int i{0}; i < n; ++i) {
		if (v[i] == '0') {
			for (int j{1}; j <= cont; ++j) p[j] = i - j;
			cont = 0;
		} else if (v[i] == '1') {
			++cont;
			cum += i - p[cont];
		}
		ans += cum;
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();

	return 0;
}
