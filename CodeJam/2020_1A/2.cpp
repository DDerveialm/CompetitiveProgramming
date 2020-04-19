#include <iostream>
#include <stack>
#include <cstring>
#include <algorithm>

#define Max 1000000000

using namespace std;

bool visited[500][500];
unsigned int table[500][500];
stack<pair<int, int>> mystack;

int N;
bool DFS(int i, int j, int count = 0) {
	count += table[i][j];
	if (count > N) return false;
	if (count == N) return true; //find solution
	pair<unsigned int, pair<int, int>> arr[6];
	arr[0] = make_pair(table[i-1][j-1], make_pair(i-1,j-1));
	arr[1] = make_pair(table[i-1][j  ], make_pair(i-1,j  ));
	arr[2] = make_pair(table[i  ][j-1], make_pair(i  ,j-1));
	arr[3] = make_pair(table[i  ][j+1], make_pair(i  ,j+1));
	arr[4] = make_pair(table[i+1][j  ], make_pair(i+1,j  ));
	arr[5] = make_pair(table[i+1][j+1], make_pair(i+1,j+1));
	sort(arr, arr+6);
	int I[6], J[6];
	for (int d = 0; d < 6; ++d) {
		I[5-d] = arr[d].second.first;
		J[5-d] = arr[d].second.second;
	}

	for (int d = 0; d < 6; ++d) {
		if (!visited[ I[d] ][ J[d] ] && table[ I[d] ][ J[d] ]) {
			visited[ I[d] ][ J[d] ] = true;
			mystack.emplace( I[d] ,  J[d] );
			if (DFS( I[d] ,  J[d] , count)) return true;
			visited[ I[d] ][ J[d] ] = false;
			mystack.pop();
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	memset(table, 0, sizeof(table));
	table[1][1] = 1;
	for (int i = 2; i < 500; ++i)
		for (int j = 1; j <= i; ++j) {
			table[i][j] = table[i-1][j-1];
			table[i][j] += table[i-1][j];
			if (table[i][j] > Max) table[i][j] = 0;
			if (j != 1 && !table[i-1][j-1]) table[i][j] = 0;
			if (j != i && !table[i-1][j]) table[i][j] = 0;
		}
	int T;
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		memset(visited, 0, sizeof(visited));
		cin >> N;

		visited[1][1] = true;
		mystack.emplace(1, 1);
		DFS(1, 1);
		stack<pair<int, int>> ans;
		while (!mystack.empty()) {
			ans.push(mystack.top());
			mystack.pop();
		}
		cout << "Case #" << i << ":\n";
		while(!ans.empty()) {
			cout << ans.top().first << " " << ans.top().second  << endl;
			ans.pop();
		}
	}
	return 0;
}
