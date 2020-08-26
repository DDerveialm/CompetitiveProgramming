#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <tuple>
#include <algorithm>

using namespace std;

int recur(vector<int>::iterator b, vector<int>::iterator e, int dec) {
	if (b >= e) return 0;

	auto m = min_element(b, e);
	return min(static_cast<int> (e - b), recur(b, m, *m) + recur(m + 1, e, *m) + *m - dec);
}

void solve() {
	int n;
	cin >> n;
	vector<int> vec(n);
	for (auto& e : vec) cin >> e;
	cout << recur(vec.begin(), vec.end(), 0) << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	solve();

	return 0;
}
