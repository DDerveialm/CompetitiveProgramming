#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> cnt(100 + 1);

	for (int i{0}; i < n; ++i) {
		int a;
		cin >> a;
		++cnt[a];
	}

	int A{0}, B{0};
	for (int i{0}; i <= 100; ++i)
		if (cnt[i]) A = i + 1, --cnt[i];
		else break;
	for (int i{0}; i <= 100; ++i)
		if (cnt[i]) B = i + 1;
		else break;

	cout << A + B << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}
