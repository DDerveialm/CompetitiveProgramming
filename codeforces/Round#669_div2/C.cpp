#include <iostream>
#include <vector>

using namespace std;

int ask(int x, int y) {
	int mod;
	cout << "? " << x + 1 << " " << y + 1 << endl;
	cin >> mod;
	return mod;
}

void solve() {
	int n;
	cin >> n;
	vector<int> vec(n);
	int mx = 0;
	for (int i{1}; i < n; ++i) {
		int mod1 = ask(i, mx);
		int mod2 = ask(mx, i);
		if (mod1 > mod2) vec[i] = mod1;
		else {
			vec[mx] = mod2;
			mx = i;
		}
	}
	vec[mx] = n;
	
	cout << "! ";
	for (auto& e : vec) cout << e << " ";
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();

	return 0;
}
