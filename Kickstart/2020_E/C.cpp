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
	
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int n;
		cin >> n;
		vector<pair<int, int>> toys(n);
		long long sum = 0;
		for (auto& e : toys) {
			cin >> e.first >> e.second;
			sum += e.first;
		}

		long long max_time {sum}, cur_time {sum};
		int min_rm {0}, cur_rm {0};
		priority_queue<pair<int, int>> pq;
		for (auto& e : toys) {
			pq.push(make_pair(e.first + e.second, e.first));
			cur_time += e.first;
			while (!pq.empty() && pq.top().first > sum) {
				cur_time -= 2 * pq.top().second;
				++cur_rm;
				sum -= pq.top().second;
				pq.pop();
			}
			if (cur_time > max_time) {
				max_time = cur_time;
				min_rm = cur_rm;
			}
		}

		cout << "Case #" << t << ": ";
		if (!pq.empty()) cout << cur_rm << " INDEFINITELY" << endl;
		else cout << min_rm << " " << max_time << endl;
	}
	return 0;
}
