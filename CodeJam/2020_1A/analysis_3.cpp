#include <iostream>
#include <queue>
#include <cstring>
#include <iomanip>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T, R, C;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cin >> R >> C;
		long long ans = 0, total_skill = 0;
		int s;
		int skill[R][C], up[R][C], down[R][C], left[R][C], right[R][C];
		bool in_queue[R][C];

		queue<pair<int, int>> curr_queue, next_queue, eliminated;
		for (int i = 0; i < R; ++i) //initialize
			for (int j = 0; j < C; ++j) {
				up[i][j] = i - 1;
				down[i][j] = (i == R - 1) ? (-1) : (i + 1);
				left[i][j] = j - 1;
				right[i][j] = (j == C - 1) ? (-1) : (j + 1);

				cin >> skill[i][j];
				total_skill += skill[i][j];
				curr_queue.emplace(i, j);
			}

		bool flag = true;
		while(flag) {
			ans += total_skill;
			flag = false;
			memset(in_queue, 0, sizeof(in_queue));

			int total, counter, avg;
			while(!curr_queue.empty()) {
				int x, y;
				x = curr_queue.front().first;
				y = curr_queue.front().second;
				curr_queue.pop();
				if (!skill[x][y]) continue;

				total = counter = 0; //count avg
				if (up[x][y] != -1) {
					total += skill[up[x][y]][y];
					counter += 1;
				}
				if (down[x][y] != -1) {
					total += skill[down[x][y]][y];
					counter += 1;
				}
				if (left[x][y] != -1) {
					total += skill[x][left[x][y]];
					counter += 1;
				}
				if (right[x][y] != -1) {
					total += skill[x][right[x][y]];
					counter += 1;
				}
				if (counter == 0) continue;
				avg = (total-1) / counter;
				if (skill[x][y] <= avg) { //going to be eliminated
					eliminated.emplace(x, y);
					if (up[x][y] != -1 && !in_queue[up[x][y]][y]) { //to checked next round
						next_queue.emplace(up[x][y], y);
						in_queue[up[x][y]][y] = true;
					}
					if (down[x][y] != -1 && !in_queue[down[x][y]][y]) {
						next_queue.emplace(down[x][y], y);
						in_queue[down[x][y]][y] = true;
					}
					if (left[x][y] != -1 && !in_queue[x][left[x][y]]) {
						next_queue.emplace(x, left[x][y]);
						in_queue[x][left[x][y]] = true;
					}
					if (right[x][y] != -1 && !in_queue[x][right[x][y]]) {
						next_queue.emplace(x, right[x][y]);
						in_queue[x][right[x][y]] = true;
					}
				}
			}
			while (!eliminated.empty()) {
				flag = true;
				int x, y;
				x = eliminated.front().first;
				y = eliminated.front().second;
				eliminated.pop();
				total_skill -= skill[x][y];
				skill[x][y] = 0;
				if (down[x][y] != -1) up[down[x][y]][y] = up[x][y]; //update neighbor
				if (up[x][y] != -1) down[up[x][y]][y] = down[x][y];
				if (right[x][y] != -1) left[x][right[x][y]] = left[x][y];
				if (left[x][y] != -1) right[x][left[x][y]] = right[x][y];
			}
			curr_queue.swap(next_queue);
		}
		cout << "Case #" << t << ": " << ans << endl;
	}
	return 0;
}
