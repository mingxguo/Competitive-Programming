#include <iostream>
#include <unordered_map>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

int main(){


//	ifstream in("datos.txt"); auto cinbuf = std::cin.rdbuf(in.rdbuf());
//	ofstream out("sol.txt"); auto coutbuf = std::cout.rdbuf(out.rdbuf());

	int n;
	bool first = true;
	while (cin >> n){
		if (!first) cout << '\n';
		vector<string> group(n);
		unordered_map<string, int> gift;
		for (int i = 0; i < n; ++i)
			cin >> group[i];

		string giver;
		int money, m;
		for (int i = 0; i < n; ++i){
			cin >> giver;
			cin >> money >> m;
			int g = 0;
			if (m != 0)
				g = money / m;
			string receiver;
			for (int j = 0; j < m; ++j){
				cin >> receiver;
				gift[receiver] += g;
			}
			gift[giver] -= m * g;
		}
		for (int i = 0; i < n; ++i)
			cout << group[i] << ' ' << gift[group[i]] << '\n';

		first = false;
	}
//	std::cin.rdbuf(cinbuf);
//	std::cout.rdbuf(coutbuf);
	return 0;
}