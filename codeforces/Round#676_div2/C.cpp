#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void op1(string& s, int i) {
	if (i == 0 || i == s.size() - 1) {
		cout << "Err!" << endl;
		return ;
	}
	cout << "L " << i + 1 << '\n';
	auto t{s.substr(1, i)};
	reverse(t.begin(), t.end());
	s = t + s;
}

void op2(string& s, int i) {
	if (i == 0 || i == s.size() - 1) {
		cout << "Err!" << endl;
		return ;
	}
	cout << "R " << i + 1 << '\n';
	auto t{s.substr(i, s.size() - 1 - i)};
	reverse(t.begin(), t.end());
	s = s + t;
}

void solve() {
	string s;
	cin >> s;
	cout << "3\n";
	op2(s, s.size() - 2);
	op1(s, s.size() - 2);
	op1(s, 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();

	return 0;
}
