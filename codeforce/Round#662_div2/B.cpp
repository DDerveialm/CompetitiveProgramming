#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

pair<int, int> func(int n) {
	return {n / 4, n / 2};
}

pair<int, int>& operator+= (pair<int, int>& a, const pair<int, int>& b) {
	a.first += b.first;
	a.second += b.second;
	return a;
}

pair<int, int>& operator-= (pair<int, int>& a, const pair<int, int>& b) {
	a.first -= b.first;
	a.second -= b.second;
	return a;
}

int main() {
	int n;
	cin >> n;
	vector<int> vec(10e5 + 1, 0);
	pair<int, int> count;
	for (int i = 0; i < n; ++i) {
		int len;
		cin >> len;
		count -= func(vec[len]);
		++vec[len];
		count += func(vec[len]);
	}
	cin >> n;
	for (int i = 0; i < n; ++i) {
		char op;
		int len;
		cin >> op >> len;

		count -= func(vec[len]);
		if (op == '+') ++vec[len];
		else --vec[len];
		count += func(vec[len]);

		if (count.first >= 1 && count.second >= 4) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
