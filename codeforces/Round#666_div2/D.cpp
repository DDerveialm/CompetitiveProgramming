#include <iostream>
#include <vector>
#include <queue>
#include <valarray>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> vec(n);
	for (auto& e : vec) cin >> e;
	priority_queue<int> pq(vec.begin(), vec.end());
	int T{}, HL{};
	bool turn{true};
	while (!pq.empty()) {
		if (turn) {
			if (T < pq.top()) {
				if (T) pq.push(T);
			   	T = pq.top(), pq.pop();
			}
			--T;
		} else {
			if (HL < pq.top()) {
				if (HL) pq.push(HL);
				HL = pq.top(), pq.pop();
			}
			--HL;
		}
		turn = !turn;
	}
	if (!turn) --HL;
	if (T > HL) cout << "T" << endl;
	else cout << "HL" << endl;
}

void solve2() {
	int n;
	cin >> n;
	valarray<int> arr(n);
	for (auto& e : arr) cin >> e; 
	if (arr.sum() % 2 || arr.max() > arr.sum() / 2) cout << "T" << endl;
	else cout << "HL" << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t;
	cin >> t;
	while (t--) solve2();

	return 0;
}
