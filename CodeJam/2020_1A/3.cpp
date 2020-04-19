#include <iostream>

using namespace std;

class node {
	public:
	node(int s = 0) {
		up = down = right = left = NULL;
		skill = s;
		eliminated = false;
	}
	int skill;
	bool eliminated;
	node *up, *down, *right, *left;
} ;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T, R, C;
	cin >> T;
	long long ans, total_skill;
	node *row[100000], *col[100000];
	for (int i = 0; i < 100000; ++i) {
		row[i] = new node();
		col[i] = new node();
	}
	for (int t = 1; t <= T; ++t) {
		ans = 0;
		cin >> R >> C;
		int s;
		node *rowptr, *colptr[C]; //construct
		for (int j = 0; j < C; ++j) colptr[j] = col[j];
		for (int i = 0; i < R; ++i) {
			rowptr = row[i];
			for (int j = 0; j < C; ++j) {
				cin >> s;
				node *ptr = new node(s);
				ptr -> right = NULL; //update row
				ptr -> left = rowptr;
				rowptr -> right = ptr;
				rowptr = ptr;
				ptr -> down = NULL; //update column
				ptr -> up = colptr[j];
				colptr[j] -> down = ptr;
				colptr[j] = ptr;
			}
		}
		bool flag = true;
		while(flag) {
			/*cout << "\n\n";
			for (int i = 0; i < R; ++i) {
				for (node *ptr = row[i] -> right; ptr; ptr = ptr -> right) cout << ptr -> skill << " ";
				cout << endl;
			}*/
			flag = false;
			int total, counter;
			for (int i = 0; i < R; ++i) {
				for (node *ptr = row[i] -> right; ptr; ptr = ptr -> right) {
					total = counter = 0;
					if (ptr -> up && ptr -> up -> skill) {
						total = ptr -> up -> skill;
						counter = 1;
					}
					if (ptr -> down) {
						total += ptr -> down -> skill;
						counter += 1;
					}
					if (ptr -> left && ptr -> left -> skill) {
						total += ptr -> left -> skill;
						counter += 1;
					}
					if (ptr -> right) {
						total += ptr -> right -> skill;
						counter += 1;
					}
					if (!counter) continue;
					int avg = (total-1) / counter;
					if (ptr -> skill <= avg) ptr -> eliminated = true;
				}
			}	
			for (int i = 0; i < R; ++i) {
				for (node *ptr = row[i] -> right; ptr;) {
					ans += ptr -> skill;
					if (ptr -> eliminated) {
						ptr -> left -> right = ptr -> right;
						if (ptr -> right) ptr -> right -> left = ptr -> left;
						ptr -> up -> down = ptr -> down;
						if (ptr -> down) ptr -> down -> up = ptr -> up;
						node *d = ptr;
						ptr = ptr -> right;
						delete(d);
						flag = true;
					} else ptr = ptr -> right;
				}
			}

		}
		for (int i = 0; i < R; ++i) { //free
			for (node **ptr = &(row[i] -> right); *ptr;) {
				node *d = *ptr;
				*ptr = (*ptr) -> right;
				delete(d);
			}
		}
		cout << "Case #" << t << ": " << ans << endl;
	}
	return 0;
}
