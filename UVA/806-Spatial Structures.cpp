#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <fstream>

using namespace std;

int n;
char image[64][64];

int tenToFive(int number, int & length) {
	int acc = 0;
	int pot = 1;
	length = 0;
	while (number != 0) {
		acc += number % 5 * pot;
		number /= 5;
		pot *= 10;
		++length;
	}
	return acc;
}


void imageToTree(int l, int quadrant, int r, int c, int level, int acc, vector<int> & sol) {
	bool allwhite = true, allblack = true;
	for (int i = 0; i < l; ++i) {
		for (int j = 0; j < l; ++j) {
			if (image[r + i][c + j] == '0')allblack = false;
			else allwhite = false;
		}
	}
	if (allwhite) return;
	acc += pow(5, level - 1)*quadrant;
	if (allblack) {
		sol.push_back(acc);
		return;
	}
	//gray
	imageToTree(l / 2, 1, r, c, level + 1, acc, sol);
	imageToTree(l / 2, 2, r, c + l / 2, level + 1, acc, sol);
	imageToTree(l / 2, 3, r + l / 2, c, level + 1, acc, sol);
	imageToTree(l / 2, 4, r + l / 2, c + l / 2, level + 1, acc, sol);
}

void treeToImage(vector<int> const& nodes) {
	//initialize blank image
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			image[i][j] = '.';
		}
	}
	//blank image
	if (nodes.empty()) return;
	//all black
	if (nodes[0] == 0) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				image[i][j] = '*';
			}
		}
		return;
	}
	int k = 0;
	while (k<nodes.size()) {
		int node = nodes[k];
		int length = 0;
		int nodeFive = tenToFive(node, length);
		int r = 0, c = 0;
		int l = n;
		while (nodeFive != 0) {
			l /= 2;
			int quadrant = nodeFive % 10;
			if (quadrant == 2) { c += l; }
			else if (quadrant == 3) { r += l; }
			else if (quadrant == 4) { r += l; c += l; }
			nodeFive /= 10;
		}
		//fill
		for (int i = 0; i < l; ++i) {
			for (int j = 0; j < l; ++j) {
				image[r + i][c + j] = '*';
			}
		}
		++k;
	}
}

int main() {
	/*fstream in, out;
	in.open("in.txt", ios::in);
	out.open("out.txt", ios::out);
	cin.rdbuf(in.rdbuf());
	cout.rdbuf(out.rdbuf());*/
	int aux, kase = 1;
	cin >> aux;
	while (aux) {
		if (kase > 1)cout << '\n';
		cout << "Image " << kase << '\n';
		n = abs(aux);
		bool allblack = true;
		if (aux > 0) {
			//read image
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					cin >> image[i][j];
					if (image[i][j] == '0')allblack = false;
				}
			}
			//process
			vector<int> tree;
			if (allblack) cout << "0\nTotal number of black nodes = 1\n";
			else {
				imageToTree(n, 1, 0, 0, 0, 0, tree);
				sort(tree.begin(), tree.end());
				int num = tree.size();
				if (num != 0) {
					cout << tree[0];
					for (int i = 1; i < num; ++i) {
						if (i % 12 == 0) cout << '\n'<<tree[i];
						else cout << ' ' << tree[i];
					}
					cout << '\n';
				}
				cout << "Total number of black nodes = " << num << "\n";
			}
		}
		else {
			vector<int> nodes;
			int node;
			cin >> node;
			while (node != -1) {
				nodes.push_back(node);
				cin >> node;
			}
			treeToImage(nodes);
			//print image
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					cout << image[i][j];
				}
				cout << '\n';
			}
		}
		//cout << '\n';
		++kase;
		cin >> aux;
	}
	return 0;
}
