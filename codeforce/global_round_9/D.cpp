#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <functional>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, unfixed = 0;
		cin >> n;
		vector<int> vec(n), count(n + 1, 0);
		for (int i = 0; i < n; ++i) {
			cin >> vec[i];
			++count[vec[i]];
			if (vec[i] != i) ++unfixed;
		}
		priority_queue<int, vector<int>, greater<int>> pq;
		for (int i = 0; i <= n; ++i)
			if (count[i] == 0) pq.push(i);
		vector<int> ans;
		ans.reserve(2 * n);
		while (unfixed) {
			auto MEX = pq.top();
			pq.pop();
			if (MEX == n) {
				for (int i = 0; i < n; ++i) {
					if (vec[i] != i) { // unfixed
						--count[vec[i]];
						if (count[vec[i]] == 0)
							pq.push(vec[i]);
						++count[n];
						vec[i] = n;
						ans.push_back(i + 1);
						break;
					}
				}
			} else {
				--count[vec[MEX]];
				if (count[vec[MEX]] == 0)
					pq.push(vec[MEX]);
				++count[MEX];
				vec[MEX] = MEX;
				ans.push_back(MEX + 1);
				--unfixed;
			}
		}
		cout << ans.size() << endl;
		for (const auto& i : ans) cout << i << " ";
		cout << endl;
	}
	return 0;
}
