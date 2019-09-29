#include<iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

string preord, inord;
int n;

void postord(int len, int prei, int ini, int inf) {
	//base case
	if (len == 0)return;

	char root = preord[prei];
	int i = ini;
	while (i < inf&&inord[i] != root) ++i;
	int nlen = i - ini;
	//left tree
	postord(nlen, prei + 1, ini, i);
	//right tree
	postord(len - nlen - 1, prei + 1 + nlen, i + 1, inf);
	cout << root;
}

int main() {
	fstream in, out;
	in.open("in.txt", ios::in);
	out.open("out.txt", ios::out);
	cin.rdbuf(in.rdbuf());
	cout.rdbuf(out.rdbuf());

	while (cin >> preord >> inord) {
		n = preord.size();
		postord(n, 0, 0, n);
		cout << '\n';
	}
	return 0;
}