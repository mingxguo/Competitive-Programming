#include<iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int r, c, inir, inic;
int maze[10][10];

int row[4] = { 0,1,0,-1 };
int col[4] = { 1,0,-1,0 };

int oppo(int dice) {
	switch (dice) {
	case 1:return 6;
	case 2: return 5;
	case 3: return 4;
	case 4:return 3;
	case 5: return 2;
	case 6: return 1;
	}
}

//dir = 0:right, dir = 1:down, dir = 2:left, dir = 3:up
void calculate(int oldtop, int oldface, int dir, int & newtop, int & newface) {
	int right;
	if (oldtop == 1 && oldface == 2) right = 3;
	else if (oldtop == 1 && oldface == 3) right = 5;
	else if (oldtop == 1 && oldface == 5) right = 4;
	else if (oldtop == 1 && oldface == 4) right = 2;
	else if (oldtop == 2 && oldface == 1) right = 4;
	else if (oldtop == 2 && oldface == 3) right = 1;
	else if (oldtop == 2 && oldface == 4) right = 6;
	else if (oldtop == 2 && oldface == 6) right = 3;
	else if (oldtop == 3 && oldface == 6) right = 5;
	else if (oldtop == 3 && oldface == 5) right = 1;
	else if (oldtop == 3 && oldface == 1) right = 2;
	else if (oldtop == 3 && oldface == 2) right = 6;
	else if (oldtop == 4 && oldface == 1) right = 5;
	else if (oldtop == 4 && oldface == 5) right = 6;
	else if (oldtop == 4 && oldface == 6) right = 2;
	else if (oldtop == 4 && oldface == 2) right = 1;
	else if (oldtop == 5 && oldface == 6) right = 4;
	else if (oldtop == 5 && oldface == 4) right = 1;
	else if (oldtop == 5 && oldface == 1) right = 3;
	else if (oldtop == 5 && oldface == 3) right = 6;
	else if (oldtop == 6 && oldface == 4) right = 5;
	else if (oldtop == 6 && oldface == 5) right = 3;
	else if (oldtop == 6 && oldface == 3) right = 2;
	else if (oldtop == 6 && oldface == 2) right = 4;
	switch (dir) {
	case 0: newtop = oppo(right); newface = oldface; break;
	case 1:newtop = oppo(oldface); newface = oldtop; break;
	case 2:newtop = right; newface = oldface; break;
	case 3:newtop = oldface; newface = oppo(oldtop); break;
	}
}

bool possible(int posi, int posj, int top) {
	return posi >= 0 && posj >= 0 && posi < r&&posj < c && (maze[posi][posj] == -1 || maze[posi][posj] == top);
}

bool explore(int posi, int posj, int dir, int top, int face, vector<pair<int,int>> & sol) {
	if (posi == inir && posj == inic) return true;
	for (int i = 0; i < 4; ++i) {
		int newi = posi + row[i], newj = posj + col[i];
		if (possible(newi, newj, top) && abs(dir-i)!=2) {
			sol.push_back({ newi, newj });
			int newtop, newface;
			calculate(top, face, i, newtop, newface);
			if (explore(newi, newj, i, newtop, newface, sol)) return true;
			sol.pop_back();
		}
	}
	return false;
}

int main() {
	string name;
	vector<pair<int, int>> sol, aux;
	int top, face;
	while (cin >> name && name != "END") {
		sol.clear();
		cin >> r >> c >> inir >> inic >> top >> face;
		--inir;
		--inic;
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				cin >> maze[i][j];
			}
		}
		bool ok = false;
		for (int i = 0; i < 4; ++i) {
			int newi = inir + row[i], newj = inic + col[i];
			if (possible(newi, newj, top)) {
				aux.clear();
				aux.push_back({ inir, inic });
				aux.push_back({ newi,newj });
				int newtop, newface;
				calculate(top, face, i, newtop, newface);
				if (explore(newi, newj, i, newtop, newface, aux)) {
					ok = true;
					sol = aux;
				}
			}
		}
		//output
		cout << name << '\n';
		if (!ok) cout << "  No Solution Possible\n";
		else {
			int i = 0;
			while (i < sol.size()) {
				if (i==0)cout << "  ";
				else if (i % 9 == 0)cout << "\n  ";
				cout << '(' << sol[i].first + 1 << ',' << sol[i].second + 1 << ')';
				if (i != sol.size() - 1)cout << ',';
				++i;
			}
		}
	}
	return 0;
}