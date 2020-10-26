#include <iostream>
#include <vector>
#include <stack>

#define fi first
#define se second

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<pair<char, int>> v(2 * n);
	for (auto& x : v) {
		cin >> x.fi;
		if (x.fi == '-') cin >> x.se;
	}

	bool flag{true};
	stack<int> stk{};
	for (auto it{v.rbegin()}; it != v.rend(); ++it) {
		if (it -> fi == '-') {
			if (!stk.empty() && stk.top() < it -> se) {
				flag = false;
				break;
			}
			stk.push(it -> se);
		} else {
			if (stk.empty()) {
				flag = false;
				break;
			}
			it -> se = stk.top(), stk.pop();
		}
	}

	if (flag) {
		cout << "YES\n";
		for (auto& x : v) if (x.fi == '+') cout << x.se << ' ';
		cout << '\n';
	} else cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();

	return 0;
}
