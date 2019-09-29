#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int n, m;
int vars[8];
string stree;
int pot[8] = { 1, 2, 4, 8, 16, 32, 64, 128};


void solve(string const& vva) {
	int sol = 0;
	for (int i = n-1; i >=0; --i) {
		int idx = vars[n-i-1] - 1;
		if (vva[idx] == '1') sol += pot[i];
	}
	cout << stree[sol];
}

int main() {
	/*fstream in, out;
	in.open("in.txt", ios::in);
	out.open("out.txt", ios::out);
	cin.rdbuf(in.rdbuf());
	cout.rdbuf(out.rdbuf());*/
	cin >> n;
	int kase = 1;
	while (n) {
		cout << "S-Tree #" << kase << ":\n";
		string x;
		for (int i = 0; i < n; ++i) {
			cin >> x;
			vars[i] = x.back() - '0';
		}
		cin >> stree;
		cin >> m;
		string vva;
		for (int i = 0; i < m; ++i) {
			cin >> vva;
			solve(vva);
		}
		cout << "\n\n";
		cin >> n;
		++kase;
	}

	return 0;
}