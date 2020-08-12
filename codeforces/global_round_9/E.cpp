#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <functional>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> vec(n);
	for (auto& i : vec)
		cin >> i;
	queue<pair<int, int>> ans;
	for (int i = n - 1; i > 0; --i) {
			priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pos;
		for (int j = 0; j < i; ++j) {
			if (vec[j] > vec[i]) {
				pos.push({vec[j], j});
			}
		}
		while(!pos.empty()) {
			auto j = pos.top().second;
			pos.pop();
			ans.push({j + 1, i + 1});
		}
	}
	cout << ans.size() << endl;
	while(!ans.empty()) {
		auto p = ans.front();
		ans.pop();
		cout << p.first << " " << p.second << endl;
	}
	return 0;
}
