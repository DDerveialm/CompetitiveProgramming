#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> suffix(string s) {
	s += '$';
	const auto& n{s.size()};
	vector<int> cmp(n);
	{ // init
		// k == 0
		vector<pair<char, int>> vec(n);
		for (int i{0}; i < n; ++i) vec[i] = {s[i], i};
		sort(vec.begin(), vec.end());

		cmp[vec[0].second] = 0;
		for (int i{1}; i < n; ++i) {
			if (vec[i].first == vec[i - 1].first) cmp[vec[i].second] = cmp[vec[i - 1].second];
			else cmp[vec[i].second] = cmp[vec[i - 1].second] + 1;
		}
	}
	int k{0};
	vector<pair<pair<int, int>, int>> vec(n);
	while ((1 << k) < n) {
		// k -> k + 1
		for (int i{0}; i < n; ++i) vec[i] = {{cmp[i], cmp[(i + (1 << k)) % n]}, i};
		sort(vec.begin(), vec.end());

		cmp[vec[0].second] = 0;
		for (int i{1}; i < n; ++i) {
			if (vec[i].first == vec[i - 1].first) cmp[vec[i].second] = cmp[vec[i - 1].second];
			else cmp[vec[i].second] = cmp[vec[i - 1].second] + 1;
		}

		++k;		
	}

	vector<int> order(n);
	for (int i{0}; i < n; ++i) order[i] = vec[i].second;
	return order;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string s;
	cin >> s;
	auto ans = suffix(s);
	for (auto& e : ans) cout << e << " ";
	cout << endl;
	
	return 0;
}
