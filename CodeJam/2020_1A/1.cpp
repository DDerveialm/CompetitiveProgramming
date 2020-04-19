#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T, N;
	cin >> T;
	for (int i = 1; i < T; ++i) {
		cin >> N;
		string P[N];
		int max = 0, pos;
		for (int j = 0; j < N; ++j) {
			cin >> P[j];
			if (max < P[j].length()) {
				max = P[j].length();
				pos = j;
			}
		}
		for (int j = 0; j < N; ++j) {
			
		}
		cout << "#case " << i << ": ";
	}
	return 0;
}
