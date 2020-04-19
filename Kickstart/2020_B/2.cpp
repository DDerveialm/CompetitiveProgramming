#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int N;
		cin >> N;
		long long D, arr[N];
		cin >> D;
		for (int i = 0; i < N; ++i) cin >> arr[i];
		arr[N - 1] *= (D / arr[N-1]);
		for (int i = N - 2; i >= 0; --i) {
			arr[i] *= arr[i + 1] / arr[i];
		}
		cout << "Case #" << t << ": " << arr[0] << endl;
	}

	return 0;
}
