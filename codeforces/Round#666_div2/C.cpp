#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<long long> vec(n);
	for (auto& e : vec) cin >> e;

	cout << "1 1" << endl; // let vec[1] = 0
	cout << -1 * vec[0] << endl;
	vec[0] = 0;

	if (n != 1) { // let vec[2:n] become a multiply of n
		cout << 2 << " " << n << endl;
		for (int i{1}; i < n; ++i) {
			long long b = (vec[i] % n) * (n - 1);
			vec[i] += b;
			cout << b << " ";
		}
		cout << endl;
	} else cout << "1 1\n0" << endl;

	cout << 1 << " " << n << endl;
	for (int i{}; i < n; ++i)
		cout << -1 * vec[i] << " ";
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	solve();

	return 0;
}
