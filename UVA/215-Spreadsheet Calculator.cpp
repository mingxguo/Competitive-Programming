#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <queue>
#include <cctype>
#include <map>
#include <algorithm>

using namespace std;

int sheet[20][10];
string exprs[20][10];
bool vis[20][10];
int r, c;

bool isExpr(string expr) {
	int i = 0;
	while (i < expr.size() && isdigit(expr[i]))++i;
	if (i == expr.size())return false;
	else return true;
}

int toInt(string expr, int i, int end) {
	int res = 0;
	while (i < end) {
		res = res * 10 + (expr[i]-'0');
		++i;
	}
	return res;
}

//return a value or not
bool dfs(string expr, int rr, int cc) {
	if (!vis[rr][cc]) {
		vis[rr][cc] = true;
		queue<int> operands;
		queue<char> ops;
		int i = 0;
		while (i < expr.size()) {
			//number
			if (isdigit(expr[i])) {
				int ini = i;
				while (i < expr.size() && isdigit(expr[i]))++i;
				int oper = toInt(expr, ini, i);
				operands.push(oper);
			}
			//expr
			else if (isalpha(expr[i])) {
				int row = expr[i] - 'A';
				int col = expr[i + 1] - '0';
				i = i + 2;
				int oper;
				if (sheet[row][col] != -1) {
					oper = sheet[row][col];
					operands.push(oper);
				}
				else if (dfs(exprs[row][col], row, col)) {
					oper = sheet[row][col];
					operands.push(oper);
				}
				else return false;
			}
			//operator
			else { 
				ops.push(expr[i]);
				++i;
			}
		}
		if (operands.empty())return false;
		//calculate result
		int res = operands.front();
		operands.pop();
		int oper;
		while (!operands.empty()) {
			oper = operands.front();
			operands.pop();
			char op = ops.front();
			ops.pop();
			if (op == '+')res += oper;
			else res -= oper;
		}
		sheet[rr][cc] = res;
		return true;
	}
	return false;
}

int main() {
	/*fstream in, out;
	in.open("in.txt", ios::in);
	out.open("out.txt", ios::out);
	cin.rdbuf(in.rdbuf());
	cout.rdbuf(out.rdbuf());*/
	string s;
	while (cin >> r >> c, r + c) {
		memset(sheet, -1, sizeof(sheet));
		memset(vis, false, sizeof(vis));
		//input
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				cin >> s;
				if (isExpr(s))exprs[i][j] = s;
				else sheet[i][j] = toInt(s, 0, s.size());
			}
		}
		//solve
		bool ok = true;
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				if (sheet[i][j] == -1 && !vis[i][j]) {
					ok = dfs(exprs[i][j], i, j) && ok;
				}
			}
		}
		//output
		if (ok) {
			//output table
			cout << ' ';
			for (int i = 0; i < c; ++i)printf("%6d", i);
			cout << '\n';
			for (int i = 0; i < r; ++i) {
				cout << char('A' + i);
				for (int j = 0; j < c; ++j)printf("%6d", sheet[i][j]);
				cout << '\n';
			}
		}
		else{
			//output list
			for (int i = 0; i < r; ++i) {
				for (int j = 0; j < c; ++j) {
					if (sheet[i][j] == -1) {
						char c = 'A' + i;
						cout << c << j << ": " << exprs[i][j] << '\n';
					}
				}
			}
		}
		cout << '\n';
	}

	return 0;
}