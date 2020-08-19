#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> pwd(n);
		for (auto& e : pwd) cin >> e;
		auto x = pwd.front();
		auto it = pwd.begin() + 1;
		for (; it != pwd.end() && *it == x; ++it) ;

		if (it == pwd.end()) cout << n << endl;
		else cout << "1" << endl;
	}
	return 0;
}
