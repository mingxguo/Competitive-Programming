#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

int s;
float r;
bool vis[6];
int w[6];
float best;

//return the width of the rod
float solve(int & weight, float & leftlen, float& rightlen, float& len, int count) {
	//base case: only one stone left
	if (count == 1) {
		for (int i = 0; i < s; ++i) {
			if (!vis[i]) {
				weight = w[i];
				leftlen = 0;
				rightlen = 0;
				return;
			}
		}
	}
	//more than one stone left
	//try left stone
	for (int i = 0; i < s; ++i) {
		if (!vis[i]) {

		}
	}
}

int main() {
	int kase;
	cin >> kase;
	while (kase--) {
		cin >> r >> s;
		for (int i = 0; i < s; ++i)cin >> w[i];
		memset(vis, 0, sizeof(vis));
		best = 0;

	}
	return 0;
}