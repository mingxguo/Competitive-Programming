#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <map>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		vector<pair<string, string> >d1, d2;
		string s;
		cin >> s;
		stringstream ss;
		ss.str(s.substr(1, s.length() - 2));
		string key, value;
		while (getline(ss, key, ':') && getline(ss, value, ',')) {
			d1.push_back({ key,value });
		}
		cin >> s;
		ss.str(s.substr(1, s.length() - 2));
		ss.clear();
		while (getline(ss, key, ':') && getline(ss, value, ',')) {
			d2.push_back({ key,value });
		}
		sort(d1.begin(), d1.end());
		sort(d2.begin(), d2.end());
		int i = 0, j = 0;
		vector<string> add, remove, change;
		while (i < d1.size() && j < d2.size()) {
			if (d1[i].first < d2[j].first) {
				remove.push_back(d1[i].first);
				++i;
			}
			else if (d1[i].first > d2[j].first) {
				add.push_back(d2[j].first);
				++j;
			}
			else {
				if (d1[i].second != d2[j].second) change.push_back(d1[i].first);
				++i;
				++j;
			}
		}
		while(i<d1.size()){
			remove.push_back(d1[i].first);
			++i;
		}
		while(j<d2.size()){
			add.push_back(d2[j].first);
			++j;
		}
	
		if (add.empty() && remove.empty() && change.empty())cout << "No changes\n";
		else {
			if (!add.empty()) {
				cout << '+' << add[0];
				for (int i = 1; i < add.size(); ++i) cout << ',' << add[i];
				cout << '\n';
			}
			if (!remove.empty()) {
				cout << '-' << remove[0];
				for (int i = 1; i < remove.size(); ++i) cout << ',' << remove[i];
				cout << '\n';
			}
			if (!change.empty()) {
				cout << '*' << change[0];
				for (int i = 1; i < change.size(); ++i) cout << ',' << change[i];
				cout << '\n';
			}
		}
		cout << '\n';
	}
	return 0;
}