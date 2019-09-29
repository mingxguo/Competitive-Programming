#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <cctype>
#include <map>
#include <algorithm>

using namespace std;

using lli = long long int;

map<lli, int> equi;
lli sum;

struct Node {
	int value;
	Node* left;
	Node* right;
	Node(int v, Node* l, Node* r) :value(v), left(l), right(r) {}

};

int toint(string const& expr, int const& ini, int const& fin) {
	int res = 0;
	while (ini < fin) {
		res = res * 10 + expr[ini];
	}
	return res;
}
void create(string const& expr, int & i, Node* tree) {
	if (i >= expr.length()) return;
	//base case
	if (isdigit(expr[i])) {
		int ini = i;
		while (isdigit(expr[i]))++i;
		int weight = toint(expr, ini, i);
		tree->value = weight;
		tree->left = nullptr;
		tree->right = nullptr;
	}
	//recursive
	if (expr[i] == '[') {
		Node* left;
		Node* right;
		//[
		++i;
		create(expr, i, left);
		//,
		++i;
		create(expr, i, right);
		//]
		++i;
		tree->left = left;
		tree->right = right;
	}
}

void dfs(Node* tree, int depth) {
	//base node
	if (tree->left == nullptr && tree->right == nullptr) {
		++equi[(tree->value) << depth];
		++sum;
	}
	else {
		dfs(tree->left, depth + 1);
		dfs(tree->right, depth + 1);
	}
}

int main() {
	int t;
	while (t--) {
		equi.clear();
		sum = 0;
		//input
		string expr;
		cin >> expr;
		Node* tree;
		int i = 0;
		create(expr, i, tree);
		//solve
		dfs(tree, 0);
		int aux = 0;
		for (auto i = equi.begin(); i != equi.end(); ++i) {
			aux = max(aux, i->second);
		}
		cout << sum - aux << '\n';
	}
	return 0;
}