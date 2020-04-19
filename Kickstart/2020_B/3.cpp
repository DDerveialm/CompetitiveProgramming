#include <iostream>
#include <stack>
#include <cmath>

constexpr long long num = pow(10, 9);

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		long long N = 0, S = 0, E = 0, W = 0, k = 1;
		stack<long long> my_stack;
		my_stack.push(1);
		string s;
		cin >> s;
		for (const auto & c : s) {
			if (c >= '2' && c <= '9') {
				k *= (c - '0');
				k %= num;
				my_stack.push(k);
			} else if (c == ')') {
				my_stack.pop();
				k = my_stack.top();
			} else {
				switch(c) {
					case 'N':
						N += k;
						break;
					case 'S':
						S += k;
						break;
					case 'E':
						E += k;
						break;
					case 'W':
						W += k;
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
