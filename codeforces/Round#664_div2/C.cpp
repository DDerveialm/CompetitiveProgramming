#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

bool check(const vector<int>& A, const vector<int>& B, int x) { // check if it's possible
	for (const auto& a : A) {
		auto b = B.cbegin();
		for (; b != B.cend(); ++b)
			if (((a & *b) | x) == x) break;
		if (b == B.cend()) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	vector<int> b(m);
	for (auto& e : a) cin >> e;
	for (auto& e : b) cin >> e;
	
	int ans = 0;
	//while (!check(a, b, ans)) ++ans;
//
	ans = (1 << 9) - 1;
	for(int i = 8; i >= 0; --i)
		if (check(a, b, ans ^ (1<<i))) ans ^= (1 << i);
//
	cout << ans << endl;
	return 0;
}
