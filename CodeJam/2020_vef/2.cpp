#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T, t, count;
	cin >> T;
	string s;
	for (t = 1; t <= T; ++t) {
		cout << "case #" << t << ": ";
		cin >> s;
		count = 0;
		for (int i = 0; i < s.size(); ++i) {
			int num = s[i] - 48;
			if (count < num) {
				for (int j = 0; j < num - count; ++j) cout << "(";
			} else if (count > num) {
				for (int j = 0; j < count - num; ++j) cout << ")";
			}
			cout << num;
			count = num;
		}
		for (int j = 0; j < count; ++j) cout << ")";
		cout << endl;
		s.clear();
	}
	return 0;
}
