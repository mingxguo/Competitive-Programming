#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <queue>
#include <cctype>
#include <deque>
#include <algorithm>
#include <set>

using namespace std;

vector<deque<int> > piles;
bool finished[7];
set<vector<deque<int>>> vis;

bool pick(int i) {
	if (piles[i].size() >= 3) {
		//1
		int c1 = piles[i][0], c2 = piles[i][1], c3 = piles[i].back();
		int sum = c1 + c2 + c3;
		if (sum == 10 || sum == 20 || sum == 30) {
			piles[i].pop_front(); piles[i].pop_front(); piles[i].pop_back();
			piles[7].push_back(c1); piles[7].push_back(c2); piles[7].push_back(c3);
			if (piles[i].size() == 0)finished[i] = true;
			return true;
		}
		//2
		c2 = piles[i][piles[i].size() - 1];
		sum = c1 + c2 + c3;
		if (sum == 10 || sum == 20 || sum == 30) {
			piles[i].pop_front(); piles[i].pop_back(); piles[i].pop_back();
			piles[7].push_back(c1); piles[7].push_back(c2); piles[7].push_back(c3);
			if (piles[i].size() == 0)finished[i] = true;
			return true;
		}
		//3
		c1= piles[i][piles[i].size() - 2]; sum = c1 + c2 + c3;
		if (sum == 10 || sum == 20 || sum == 30) {
			piles[i].pop_back(); piles[i].pop_back(); piles[i].pop_back();
			piles[7].push_back(c1); piles[7].push_back(c2); piles[7].push_back(c3);
			if (piles[i].size() == 0)finished[i] = true;
			return true;
		}
		return false;
	}
	else return false;
}

int main() {
	/*fstream in, out;
	in.open("in.txt", ios::in);
	out.open("out.txt", ios::out);
	cin.rdbuf(in.rdbuf());
	cout.rdbuf(out.rdbuf());*/
	int num;
	piles.resize(8);
	while (cin >> num, num) {
		for (int i = 0; i < 8; ++i)piles[i].clear();
		memset(finished, false, sizeof(finished));
		vis.clear();
		piles[7].push_back(num);
		int draws = 0;
		//input
		for (int i = 0; i < 51; ++i) {
			cin >> num;
			piles[7].push_back(num);
		}
		//solve
		int i = 1;
		//first play
		++draws;
		int card = piles[7].front();
		piles[7].pop_front();
		piles[0].push_back(card);
		while (0 < piles[7].size() && piles[7].size()<52) {
			if (i >= 7)i = 0;
			if (!finished[i]) { 
				//play card
				++draws;
				card = piles[7].front();
				piles[7].pop_front();
				piles[i].push_back(card);
				while (pick(i));
				if (vis.count(piles)) break;
				vis.insert(piles);
			}
			++i;
		}
		if(piles[7].size()==52) cout << "Win: ";
		else if (!piles[7].empty()) cout << "Draw: ";
		else cout << "Loss: ";
		
		cout << draws << '\n';
	}
	return 0;
}