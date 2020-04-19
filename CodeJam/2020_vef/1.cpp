#include <iostream>
#include <cstring>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t, T, N, matrix[101][101], k, r, c;
       	bool check[101];
	cin >> T;
	for (t = 1; t <= T; ++t) {
		k = r = c = 0;
		cin >> N;
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j) {
				cin >> matrix[i][j];
				if (i == j) k += matrix[i][i];
			}
		for (int i = 0; i < N; ++i) {
			memset(check, 0, sizeof(check));
			for (int j = 0; j < N; ++j) {
				if (check[matrix[i][j]]) {
					r++;
					break;
				}
				check[matrix[i][j]] = true;
			}
		}
		for (int j = 0; j < N; ++j) {
			memset(check, 0, sizeof(check));
			for (int i = 0; i < N; ++i) {
				if (check[matrix[i][j]]) {
					c++;
					break;
				}
				check[matrix[i][j]] = true;
			}
		}
		cout << "case #" << t << ": " << k << " " << r << " " << c << endl;
	}

	return 0;
}
