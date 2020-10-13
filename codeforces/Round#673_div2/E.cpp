#include <iostream>
#include <array>

using namespace std;

namespace E {
	class node {
	public:
		node *left{nullptr}, *right{nullptr};
		int lcount{0}, rcount{0};
	};

	node* root{new node{}};
	array<long long, 30> cnt1{}, cnt2{};

	void add(int x) {
		auto tmp{root};
		for (int i{29}; i >= 0; --i) {
			if (x & (1 << i)) {
				cnt1[i] += tmp -> lcount;

				++(tmp -> rcount);
				if (!(tmp -> right)) tmp -> right = new node{};
				tmp = tmp -> right;
			} else {
				cnt2[i] += tmp -> rcount;

				++(tmp -> lcount);
				if (!(tmp -> left)) tmp -> left = new node{};
				tmp = tmp -> left;
			}
		}
	}
	
	void solve() {
		int n;
		cin >> n;
		for (int i{0}; i < n; ++i) {
			int x;
			cin >> x;
			add(x);
		}
	
		long long ans{0};
		int x{0};
		for (int i{0}; i <= 29; ++i) {
			if (cnt1[i] < cnt2[i]) ans += cnt1[i], x |= (1 << i);
			else ans += cnt2[i];
		}
		cout << ans << " " << x << endl;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	E::solve();

	return 0;
}
