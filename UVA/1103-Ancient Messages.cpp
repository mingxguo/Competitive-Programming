#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <stack>

using namespace std;

int h,w;
int image[201][201];

int row[4] = { -1,0,1,0 };
int col[4] = { 0,1,0,-1 };

void floodfill(int r, int c, int oldcolor, int newcolor, bool & border) {
	border = false;
	stack<pair<int, int> > stk;
	stk.push({ r,c });
	while (!stk.empty()) {
		pair<int, int> elem = stk.top();
		stk.pop();
		if (elem.first >= 0 && elem.first < h && elem.second >= 0 && elem.second < w * 4 && image[elem.first][elem.second] == oldcolor) {
			image[elem.first][elem.second] = newcolor;
			if (!border && (elem.first == 0 || elem.second == 0 || elem.first == h - 1 || elem.second == w * 4 - 1))border = true;
			for (int dir = 0; dir < 4; ++dir) {
				stk.push({ elem.first + row[dir],elem.second + col[dir] });
			}
		}
	}
}

void hexToInt(char hex, int r, int c) {
	switch (hex)
	{
	case '0':image[r][c] = -1; image[r][c + 1] = -1; image[r][c + 2] = -1; image[r][c + 3] = -1; break;
	case '1':image[r][c] = -1; image[r][c + 1] = -1; image[r][c + 2] = -1; image[r][c + 3] = 1; break;
	case '2':image[r][c] = -1; image[r][c + 1] = -1; image[r][c + 2] = 1; image[r][c + 3] = -1; break;
	case '3':image[r][c] = -1; image[r][c + 1] = -1; image[r][c + 2] = 1; image[r][c + 3] = 1; break;
	case '4':image[r][c] = -1; image[r][c + 1] = 1; image[r][c + 2] = -1; image[r][c + 3] = -1; break;
	case '5':image[r][c] = -1; image[r][c + 1] = 1; image[r][c + 2] = -1; image[r][c + 3] = 1; break;
	case '6':image[r][c] = -1; image[r][c + 1] = 1; image[r][c + 2] = 1; image[r][c + 3] = -1; break;
	case '7':image[r][c] = -1; image[r][c + 1] = 1; image[r][c + 2] = 1; image[r][c + 3] = 1; break;
	case '8':image[r][c] = 1; image[r][c + 1] = -1; image[r][c + 2] = -1; image[r][c + 3] = -1; break;
	case '9':image[r][c] = 1; image[r][c + 1] = -1; image[r][c + 2] = -1; image[r][c + 3] = 1; break;
	case 'a':image[r][c] = 1; image[r][c + 1] = -1; image[r][c + 2] = 1; image[r][c + 3] = -1; break;
	case 'b':image[r][c] = 1; image[r][c + 1] = -1; image[r][c + 2] = 1; image[r][c + 3] = 1; break;
	case 'c':image[r][c] = 1; image[r][c + 1] = 1; image[r][c + 2] = -1; image[r][c + 3] = -1; break;
	case 'd':image[r][c] = 1; image[r][c + 1] = 1; image[r][c + 2] = -1; image[r][c + 3] = 1; break;
	case 'e':image[r][c] = 1; image[r][c + 1] = 1; image[r][c + 2] = 1; image[r][c + 3] = -1; break;
	case 'f':image[r][c] = 1; image[r][c + 1] = 1; image[r][c + 2] = 1; image[r][c + 3] = 1; break;
	}
}

int main() {
	int kase = 1;
	cin >> h >> w;
	while (h + w) {
		cout << "Case " << kase << ": ";
		int r = 0, c = 0;
		char aux;
		while(r<h) {
			for (int j = 0; j < w; ++j) {
				cin >> aux;
				hexToInt(aux, r, c);
				c += 4;
			}
			c = 0;
			++r;
		}
		//fill outside
		bool unused;
		floodfill(0, 0, -1, 0, unused);
		//fill black
		int cnt = 2;
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < 4 * w; ++j) {
				if (image[i][j] == 1) {
					floodfill(i, j, 1, cnt, unused);
					++cnt;
				}
			}
		}
		vector<char> sol;
		for (int k = 2; k < cnt; ++k) {
			int cnt2 = 0;
			//count holes
			for (int i = 0; i < h; ++i) {
				for (int j = 0; j < 4 * w - 1; ++j) {
					if (image[i][j] == k && image[i][j+1] == -1) {
						bool border;
						floodfill(i, j+1, -1, -2, border);
						if(!border)++cnt2;
					}
				}
			}
			//identify
			if (cnt2 == 0) sol.push_back('W');
			else if (cnt2 == 1) sol.push_back('A');
			else if (cnt2 == 2) sol.push_back('K');
			else if (cnt2 == 3) sol.push_back('J');
			else if (cnt2 == 4) sol.push_back('S');
			else if (cnt2 == 5) sol.push_back('D');
		}
		sort(sol.begin(), sol.end());
		for (int i = 0; i < sol.size(); ++i)cout << sol[i];
		cout << "\n";
		++kase;
		cin >> h >> w;
	}
}