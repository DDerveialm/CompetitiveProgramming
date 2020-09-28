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
#include <limits>
#include <cmath>

using namespace std;

void solve() {
	int n;
	cin >> n;
	array<int, 3> A, B;
	for (int i{0}; i < 3; ++i) cin >> A[i];
	for (int i{0}; i < 3; ++i) cin >> B[i];

	int mn, mx;
	mn = max(0, A[0] - B[0] - B[2]) + max(0, A[1] - B[0] - B[1]) + max(0, A[2] - B[1] - B[2]);
	mx = min(A[0], B[1]) + min(A[1], B[2]) +  min(A[2], B[0]);

	cout << mn << " " << mx << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();

	return 0;
}
