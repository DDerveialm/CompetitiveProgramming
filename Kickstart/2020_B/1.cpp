#include <iostream>

using namespace std;

int main() {
	int T, N;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cin >> N;
		int before = 100, now, after, ans = 0;
		cin >> now;
		for (int i = 1; i < N; ++i) {
			cin >> after;
			if (now > after && now > before) ++ans;
			before = now;
			now = after;
		}
		cout << "Case #" << t << ": " << ans << endl;
	}

	return 0;
}
