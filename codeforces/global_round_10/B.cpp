#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

template<class T>
inline void print(const vector<T>& vec) {
	for (auto& e : vec) cout << e << " ";
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t;
	cin >> t;
	while (t--) {
		int n;
		long long k;
		cin >> n >> k;
		vector<long long> vec(n);
		for (auto& e : vec) cin >> e;
		auto p = minmax_element(vec.begin(), vec.end());
		auto d = *p.second;
		for (auto& e : vec) e = d - e;
		--k;

		d = *p.first;
		if (k % 2) for (auto& e : vec) e = d - e;
		print(vec);
	}
	return 0;
}
