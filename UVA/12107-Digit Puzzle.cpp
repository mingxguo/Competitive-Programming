#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

//
int mat[510][510];
int row[4] = {0,-1,0,1};
int col[4] = { 1,0,-1,0 };
int maxlen, n;
string dirs[4] = { "e","n","w","s" };
vector<string> sol;

const int OFFSET = 251;

bool ok(string s, pair<int, int> start, int dir, int len) {
	int lastr = start.first, lastc = start.second;
	//check blocks
	for (int i = 0; i < len; ++i) {
		lastr += row[dir];
		lastc += col[dir];
		if (mat[lastr][lastc] == 1) {
			return false;
		}
	}
	//seen before
	if (mat[lastr][lastc] == 2) return false;
	else return true;
}
//dir = 0 right, 1 up 2 left 3 down
//nextdir = 1 vertical 0 horizontal
void dfs(pair<int, int> end, string acc, int len, int nextdir) {
	//laststep
	if (len > maxlen) {
		//returned to origin
		if (end.first == OFFSET && end.second == OFFSET) sol.push_back(acc);
	}
	//prune
	if (abs(end.first - OFFSET) + abs(end.second - OFFSET) > (maxlen - len + 1)*(maxlen + len) / 2) return;
	for (int i = 0; i < 4; ++i) {
		if (i % 2 == nextdir) {
			if (ok(acc, end, i, len)) {
				int newr = end.first + row[i] * len;
				int newc = end.second + col[i] * len;
				mat[newr][newc] = 2;
				acc.append(dirs[i]);
				dfs({ newr,newc }, acc, len + 1, (nextdir + 1) % 2);
				mat[newr][newc] = 0;
				acc.pop_back();
			}
		}
	}
}

int main() {
	int kase;
	cin >> kase;
	while (kase--) {
		//input
		cin >> maxlen >> n;
		sol.clear();
		memset(mat, 0, sizeof(mat));
		pair<int, int> block;
		for (int i = 0; i < n; ++i) {
			cin >> block.first >> block.second;
			mat[OFFSET - block.second][block.first + OFFSET] = 1;
		}
		dfs({ OFFSET,OFFSET }, "", 1, 0);
		dfs({ OFFSET,OFFSET }, "", 1, 1);
		sort(sol.begin(), sol.end());
		for (int i = 0; i < sol.size(); ++i)cout << sol[i] << '\n';
		if (sol.empty()) {
			cout << '\n';
		}
		cout << "Found " << sol.size() << " golygon(s).\n";
	}
	return 0;
}