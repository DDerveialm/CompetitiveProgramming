#include <iostream>
#include <array>

using namespace std;

void solve() {
	/*c[0].dir = { 1,  1};
	c[1].dir = { 0,  1};
	c[2].dir = {-1,  0};
	c[3].dir = {-1, -1};
	c[4].dir = { 0, -1};
	c[5].dir = { 1,  0};*/
	long long x, y;
	cin >> x >> y;
	array<long long, 6> c{};
	for (auto& d : c) cin >> d;

	c[0] = min(c[0], c[5] + c[1]); // d0 = d5 + d1
	c[1] = min(c[1], c[0] + c[2]); // d1 = d0 + d2
	c[2] = min(c[2], c[1] + c[3]); // d2 = d1 + d3
	c[3] = min(c[3], c[2] + c[4]); // d3 = d2 + d4
	c[4] = min(c[4], c[3] + c[5]); // d4 = d3 + d5
	c[5] = min(c[5], c[4] + c[0]); // d5 = d4 + d0

	if (x >= 0 && y >= 0) { // (+, +) 
		auto dia{min(x, y)};
		x -= dia, y -= dia;
		cout << dia * c[0] + x * c[5] + y * c[1];
	} else if (x <= 0 && y <= 0) { // (-, -)
		x *= -1, y *= -1;
		auto dia{min(x, y)};
		x -= dia, y -= dia;
		cout << dia * c[3] + x * c[2] + y * c[4];
	} else if (x >= 0 && y <= 0) // (+, -)
		y *= -1, cout << x * c[5] + y * c[4];
	else // (-, +)
		x *= -1, cout << x * c[2] + y * c[1];
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}
