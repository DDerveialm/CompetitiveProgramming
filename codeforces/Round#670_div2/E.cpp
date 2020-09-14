#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long opA(long long x) {
	cout << "A " << x << endl;
	long long ret;
	cin >> ret;
	return ret;
}

long long opB(long long x) {
	cout << "B " << x << endl;
	long long ret;
	cin >> ret;
	return ret;
}

void opC(long long x) {
	cout << "C " << x << endl;
}


void solve() {
	long long n;
	cin >> n;
	
	vector<long long> spri{}, lpri{}, vis(n + 1, 0);
	for (long long i{2}; i <= n; ++i) {
		if (!vis[i]) {
			if (i <= sqrt(n)) spri.push_back(i);
			else lpri.push_back(i);
			for (long long j{i * i}; j <= n; j += i)
				vis[j] = 1;
		}
	}
	long long ans{1};
	auto last{n};
	int l{0}, r{int(lpri.size())};
	while (l < r) { // only one large prime can be divisor
		int m{(l + r) / 2};
		for (int i{l}; i <= m; ++i)
			last -= opB(lpri[i]);
		if (last != opA(1)) { r = m + 1; break; }
		else l = m + 1;
	}
	for (int i{l}; i < r; ++i)
		if (opA(lpri[i])) {
			ans *= lpri[i];
			break;
		}

	vector<long long> spri_div{};
	for (auto& x : spri) {
		opB(x);
		if (opA(x)) {
			ans *= x;
			spri_div.push_back(x);
		}
	}
	for (auto& x : spri_div)
		for (long long pow{x * x}; pow <= n; pow *= x) {
			if (!opA(pow)) break;
			ans *= x;
		}

	opC(ans);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();

	return 0;
}
