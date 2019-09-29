#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
	char aux;
	int t;
	fstream in, out;
	in.open("in.txt", ios::in);
	out.open("out.txt", ios::out);
	cin.rdbuf(in.rdbuf());
	cout.rdbuf(out.rdbuf());
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int n = s.size();
		int i;
		for (i = 2; i <= n / 2; ++i) {
			if (n%i == 0) {
				bool ok = true;
				int j = i;
				while (ok && j < n) {
					if (s[j%i] != s[j]) ok = false;
					++j;
				}
				if (j >= n) break;
			}
		}
		if (i <= n / 2) cout << i << "\n";
		else cout << n << "\n";
		if (t > 0)cout << '\n';
	}
}