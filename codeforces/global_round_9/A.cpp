#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> vec(n);
		bool flag = true;
		for (auto& i : vec) {
			cin >> i;
			if (flag && i < 0) i *= -1;
			else if (!flag && i > 0) i *= -1;
			flag = flag ? false : true;
		}
		for (const auto& i : vec) cout << i << " ";
		cout << endl;
	}
	return 0;
}
