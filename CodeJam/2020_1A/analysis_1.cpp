#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T, N;
	cin >> T;

	for (int i = 1; i <= T; ++i) {
		string prefix, middle, suffix;
		vector<string> prefix_vec, suffix_vec;
		cin >> N;
		cin.ignore();
		while(N-- > 0) {
			string temp;
			while(true) {
				char c;
				cin.get(c);
				if (c == '*') {
					prefix_vec.push_back(temp);
					temp.clear();
					break;
				}
				temp.append(1, c);
			}
			while(true) {
				char c;
				cin.get(c);
				if (c == '*') {
					middle.append(temp);
					temp.clear();
				}
				else if (c == '\n') {
					suffix_vec.push_back(temp);
					temp.clear();
					break;
				} else temp.append(1, c);
			}
		}
		prefix = *prefix_vec.begin();
		for (vector<string>::iterator it = prefix_vec.begin() + 1; it != prefix_vec.end(); ++it) {
			string str = *it;
			if (prefix.length() < str.length()) prefix.swap(str);
			if (prefix.compare(0, str.length(), str)) {
				cout << "Case #" << i << ": *" << endl;
				goto NextCase;
			}
		}
		suffix = *suffix_vec.begin();
		for (vector<string>::iterator it = suffix_vec.begin() + 1; it != suffix_vec.end(); ++it) {
			string str = *it;
			if (suffix.length() < str.length()) suffix.swap(str);
			if (suffix.compare(suffix.length() - str.length(), str.length(), str)) {
				cout << "Case #" << i << ": *" << endl;
				goto NextCase;
			}
		}
		cout << "Case #" << i << ": " << prefix << middle << suffix << endl;
NextCase : ;
	}
	return 0;
}
