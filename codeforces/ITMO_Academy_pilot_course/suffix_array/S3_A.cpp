#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <limits>

using namespace std;

void Counting_sort(vector<int>& p, const vector<int>& c, int r) { // range is [0:r)
	vector<int> cnt(r, 0);
	vector<int> p2(p.size());
	for (auto& x : p) ++cnt[c[x]];
	--cnt[0];
	for (int i{1}; i < r; ++i) cnt[i] += cnt[i - 1];
	for (auto it = p.rbegin(); it != p.rend(); ++it) {
		p2[cnt[c[*it]]] = *it;
		--cnt[c[*it]];
	}
	p = move(p2);
}

vector<int> suffix(string& s) {
	s += '$';
	const auto& n{s.size()};
	int label;
	vector<int> p(n);
	vector<int> c(n);
	{ // init
		// k == 0
		for (int i{0}; i < n; ++i) p[i] = i;
		for (int i{0}; i < n; ++i) c[i] = int(s[i]);
		Counting_sort(p, c, int(numeric_limits<char>::max()) + 1);

		vector<int> c_next(n);
		label = 0;
		c_next[p[0]] = label;
		for (int i{1}; i < n; ++i) {
			if (c[p[i]] == c[p[i - 1]]) c_next[p[i]] = label;
			else c_next[p[i]] = ++label;
		}
		c = move(c_next);
	}

	int len{1};
	while (len < n) {
		// k -> k + 1
		for (int i{0}; i < n; ++i) p[i] = (p[i] - len + n) % n;
		Counting_sort(p, c, label + 1);

		vector<int> c_next(n);
		label = 0;
		c_next[p[0]] = label;
		for (int i{1}; i < n; ++i) {
			pair<int, int> prev{c[p[i - 1]], c[(p[i - 1] + len) % n]};
			pair<int, int> cur{c[p[i]], c[(p[i] + len) % n]};
			if (cur == prev) c_next[p[i]] = label;
			else c_next[p[i]] = ++label;
		}
		c = move(c_next);

		len *= 2;		
	}

	s.pop_back(); // $
	return p;
}

void print(const char* s) {
	for (int i{0}; s[i]; ++i) cout << s[i];
	cout << endl;
}

int cmp(const string& s, int p, const string& sub) {
	for (int i{0}; i < sub.size(); ++i) {
		if (p + i >= s.size()) return -1;

		if (s[p + i] < sub[i]) return -1;
		else if (s[p + i] > sub[i]) return 1;
	}
	return 0;
}

bool check(const string& s, const vector<int>& suffix, const string& sub) {
	int l{0}, r{int(suffix.size())};
	while (l < r) {
		int m = (l + r) / 2;
		auto c = cmp(s, suffix[m], sub);
		if (c == 0) return true;
		else if (c < 0) l = m + 1;
		else r = m;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string s;
	cin >> s;
	auto suf = suffix(s);
	int q;
	cin >> q;
	while (q--) {
		string sub;
		cin >> sub;
		if (check(s, suf, sub)) cout << "Yes\n";
		else cout << "No\n";
	}
	
	return 0;
}
