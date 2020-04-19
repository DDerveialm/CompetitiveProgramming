#include <iostream>

using namespace std;

int main() { 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	char c;
	int num;
	cin >> c >> num;
	if (num % 2 == 1) cout << "1" << endl;
	else cout << "0" << endl;

	return 0;
}
