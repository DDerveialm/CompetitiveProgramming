#include <iostream>
#include <vector>
#include <string>
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

long long num_of_substr(string& s) {
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
	
	vector<int> lcp(n - 1);
	int k{0};
	for (int i{0}; i < n - 1; ++i) { // suffix start with i
		int j{p[c[i] - 1]}; // suffix start with j
		while (s[i + k] == s[j + k]) ++k;
		lcp[c[i] - 1] = k; // lcp(suffix[j], suffix[i])
		k = max(k - 1, 0);
	}

	long long sum{int(n) - 1 - p[0]};
	for (int i{1}; i < n; ++i)
		sum += (n - 1 - p[i]) - lcp[i - 1];

	s.pop_back();
	return sum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string s;
	cin >> s;
	cout << num_of_substr(s) << endl;

	return 0;
}
