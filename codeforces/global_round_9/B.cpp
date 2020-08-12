#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, m, ans = 1;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m));
		for(int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) {
				int num = 4;
				if (i == 0 || i == n - 1) --num;
				if (j == 0 || j == m - 1) --num;
				cin >> matrix[i][j];
				if (matrix[i][j] > num) ans = 0;
				matrix[i][j] = num;
			}
		if (ans) {
			cout << "YES" << endl;
			for(int i = 0; i < n; ++i) {
				for (int j = 0; j < m; ++j)
					cout << matrix[i][j] << " ";
				cout << endl;
			}
		} else cout << "NO" << endl;
	}
	return 0;
}
