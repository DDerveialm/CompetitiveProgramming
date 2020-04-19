#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T, t, N;
	cin >> T;
	vector<pair<int, pair<int, int>>> myvec;
	bool C, J;
	int C_end, J_end;
	for (t = 1; t <= T; ++t) {
		C = J = false;
		cout << "case #" << t << ": ";
		cin >> N;
		int s, t;
		for (int i = 0; i < N; ++i) {
			cin >> s >> t;
			myvec.emplace_back(s, make_pair(t, i));
		}
		char ans[N];
		bool flag = true;
		sort(myvec.begin(), myvec.end());
		for (vector<pair<int, pair<int, int>>>::iterator it = myvec.begin(); it != myvec.end(); ++it) {
			if (C && C_end <= it -> first) C = false;
			if (J && J_end <= it -> first) J = false;
			if (!C) {
				ans[it -> second.second] = 'C';
				C = true;
				C_end = it -> second.first;
			} else if (!J) {
				ans[it -> second.second] = 'J';
				J = true;
				J_end = it -> second.first;
			} else {
				flag = false;
				break;
			}
		}

		if (flag) {
			for (int i = 0; i < N; ++i) cout << ans[i];
			cout << endl;
		}
		else cout << "IMPOSSIBLE" << endl;
		myvec.clear();
	}
	return 0;
}
