#include <iostream>
#include <fstream>
#include <algorithm>
#include <string.h>

using namespace std;

int cost[1000][1000];
int cuts[50];
int n, INF = 50000;

int cut(int ini, int fin){
	if (cost[ini][fin] != -1) return cost[ini][fin];
	int c = INF;
	for (int i = 0; i < n; ++i){
		if (cuts[i]>ini&&cuts[i] < fin){
			c = min(c, fin - ini + cut(ini, cuts[i]) + cut(cuts[i], fin));
		}
	}
	if (c == INF) c = 0;
	return cost[ini][fin] = c;
}

int main(){

	/*ifstream in("datos.txt"); auto cinbuf = std::cin.rdbuf(in.rdbuf());
	ofstream out("sol.txt"); auto coutbuf = std::cout.rdbuf(out.rdbuf());*/
	int l;
	while (cin >> l, l != 0){
		cin >> n;
		memset(cost, -1, sizeof(cost));
		for (int i = 0; i < n; ++i)
			cin >> cuts[i];
		cout << "The minimum cutting is " << cut(0, l) << ".\n";
	}

	/*std::cin.rdbuf(cinbuf);
	std::cout.rdbuf(coutbuf);*/
	return 0;
}