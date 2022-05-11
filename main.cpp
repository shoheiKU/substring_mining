#include <iostream>
#include <vector>
#include <string>


using namespace std;

void mine(vector<string> s, int d, int xi);
vector<string> getAllSuffix(string s);

int main() {
	string s = "sakurasaku";
	vector<string> suffix = getAllSuffix(s);
	mine(suffix, 0, 2);
	return 0;
}

// getAllSuffix returns all suffix in a given string.
vector<string> getAllSuffix(string s) {
	vector<string> strvector;
	for (int i = 0; i < s.size(); i++) {
		strvector.push_back(s.substr(i, s.size()));
	}
	return strvector;
}

// mine prints all substrings which appear xi times or more.
void mine(vector<string> s, int d, int xi) {
	if (s.size() < xi) {
		return;
	}
	vector<string> smore, sless, seq;
	char v = '\0';
	for (string str : s) {
		if (str.size()>d) {
			v = str[d];
			break;
		}
	}
	for (string substr : s) {
		if (substr.size() == d) continue;
		if (substr[d] > v) {
			smore.push_back(substr);
		}
		if (substr[d] == v) {
			seq.push_back(substr);
		}
		if (substr[d] < v) {
			sless.push_back(substr);
		}
	}
	mine(smore, d, xi);
	mine(sless, d, xi);
	if (seq.size() >= xi) {
		cout << seq.front().substr(0,d+1) << endl;
		mine(seq, d+1, xi);
	}
}
