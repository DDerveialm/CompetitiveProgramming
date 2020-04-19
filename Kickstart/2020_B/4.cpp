#include <iostream>

using namespace std;

int W, H, L, U, R, D;

bool in(int x, int y) {
	if (x < L || x > R) return false;
	if (y < U || y > D) return false;
	return true;
}

double total;

void DFS(int x, int y, double p) {
	if ((x > R && y > D) || (x == W && y == H)) {
		total += p;
		return ;
	}

	if (x < W && y < H) {
		if (!in(x+1, y)) DFS(x+1, y, p/2);
		if (!in(x, y+1)) DFS(x, y+1, p/2);
	}
	else if (x < W) {
		if (!in(x+1, y)) DFS(x+1, y, p);
	} else if (y < H) {
		if (!in(x, y+1)) DFS(x, y+1, p);
	}
}

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cin >> W >> H >> L >> U >> R >> D;
		total = 0;
		DFS(1, 1, 1);
		printf("Case #%i: %lf\n", t, total);
	}

	return 0;
}
