#include <iostream>
#include <stack>
#include <cmath>

constexpr long long num = pow(10, 9);

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		long long N = 0, S = 0, E = 0, W = 0;
		stack<long long> my_stack;
		my_stack.push(1);
		string s;
		cin >> s;
		for (const auto & c : s) {
			if (c >= '2' && c <= '9') {
				my_stack.push((my_stack.top() * (c - '0')) % num);
			} else if (c == ')') {
				my_stack.pop();
			} else {
				switch(c) {
					case 'N':
						N += my_stack.top();
						break;
					case 'S':
						S += my_stack.top();
						break;
					case 'E':
						E += my_stack.top();
						break;
					case 'W':
						W += my_stack.top();
						break;
				}
			}
		}
		long long x = (E - W) % num + 1;
		while(x <= 0) x += num;
		long long y = (S - N) % num + 1;
		while(y <= 0) y += num;
		cout << "Case #" << t << ": " << x << " " << y << endl;
	}
	return 0;
}
