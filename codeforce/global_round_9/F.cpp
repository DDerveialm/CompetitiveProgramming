#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main() {
	unsigned long long arr[3];
	int new_to_old[3] = {0, 1, 2};
	for (int i = 0; i < 3; ++i)
		cin >> arr[i];

	if (arr[0] > arr[1]) {
		swap(arr[0], arr[1]);
		swap(new_to_old[0], new_to_old[1]);
	}
	if (arr[1] > arr[2]) {
		swap(arr[1], arr[2]);
		swap(new_to_old[1], new_to_old[2]);
	}
	if (arr[0] > arr[1]) {
		swap(arr[0], arr[1]);
		swap(new_to_old[0], new_to_old[1]);
	}
	int old_to_new[3];
	for (int i = 0; i < 3; ++i)
		old_to_new[new_to_old[i]] = i;

	cout << "First" << endl; // to be first player
	unsigned long long y = 0;
	int index = 2; // in order to get into case 3 first time
	while(true) {
		if (index == 0) { // case 1
			arr[0] += y;
			y = arr[2] - arr[1];
			cout << y << endl;
		} else if (index == 1) { // case 2
			arr[1] += y;
			y = arr[2] - arr[0];
			cout << y << endl;
		} else if (index == 2) { // case 3
			arr[2] += y;
			y = 2 * arr[2] - arr[0] - arr[1];
			cout << y << endl;
		}

		cin >> index;
		if (index == 0) break; // win
		index = old_to_new[index - 1];
	}

	return 0;
}
