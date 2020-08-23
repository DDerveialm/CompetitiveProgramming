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
		int N, A, B, C;
		cin >> N >> A >> B >> C;
		A -= C;
		B -= C;
		auto U = A + B + C;
		if (U > N || (N != 1 && A == 0 && B == 0 && C == 1)) {
			cout << "Case #" << t << ": IMPOSSIBLE"  << endl;
		} else {
			cout << "Case #" << t << ": ";
			for (int i = 0; i < A; ++i) cout << N - 1 << " ";
			if (C > 1) {
				for (int i = 0; i < (C + 1) / 2; ++i) cout << N << " ";
				for (int i = 0; i < N - U; ++i) cout << 1 << " ";
				for (int i = 0; i < (C) / 2; ++i) cout << N << " ";
			} else {
				if (A) for (int i = 0; i < N - U; ++i) cout << 1 << " ";
				cout << N << " "; // C == 1
				if (!A) for (int i = 0; i < N - U; ++i) cout << 1 << " ";
			}
			for (int i = 0; i < B; ++i) cout << N - 1 << " ";
			cout << endl;
		}
	}
	return 0;
}
