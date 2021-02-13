#include <iostream>
#include <vector>

using namespace std;

/* Iterative Function to calculate (x^y) in O(log y) */
long long power(long long x, int y) { 
    long long ret{1};
    while (y > 0) {
        if (y & 1) ret *= x; 
        y >>= 1; 
        x = x * x;
    }
    return ret; 
}

namespace F {
	vector<long long> v{};
	void dfs(int n, long long x = 0, int i = 0) {
		if (i < n) {
			dfs(n, x * 10 + 1, i + 1);
			dfs(n, x * 10 + 2, i + 1);
		} else v.push_back(x);
	};

	vector<long long> get_all(int n) {
		dfs(n);
		return move(v);
	}
}

void solve() {
	int n;
	cin >> n;

	auto p{power(2, n)};

	auto all{F::get_all(n)};
	for (auto& x : all)
		if ((x % p) == 0) {
			cout << x << '\n';
			return ;
		}
	cout << "-1\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	// cin >> t;
	while (t--) solve();

	return 0;
}
