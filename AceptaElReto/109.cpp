#include <unordered_map>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

struct classComp{
	bool operator()(pair<string, int> const& p1, pair<string, int> const& p2){
		return p1.second > p2.second;
	}
};

bool resolve(){
	string categoria;
	getline(cin, categoria);
	if (categoria == "FIN")
		return false;

	string eq1, eq2;
	int p1, p2,cont=0;
	unordered_map<string, int> torneo;
	cin >> eq1;
	while (eq1 != "FIN"){
		//leer datos
		cin >> p1 >> eq2 >> p2;
		//calcular puntuacion
		if (p1 > p2){
			torneo[eq1] += 2;
			torneo[eq2]++;
		}
		else {
			torneo[eq2] += 2;
			torneo[eq1]++;
		}
		++cont;
		cin >> eq1;
	}
	char aux;
	cin.get(aux);
	multiset<pair<string, int>,classComp> torneoSet(torneo.begin(), torneo.end());
	if (torneoSet.size() > 1 && torneoSet.begin()->second == next(torneoSet.begin())->second)
		cout << "EMPATE";
	else
		cout << torneoSet.begin()->first;
	cout << ' ' << torneoSet.size()*(torneoSet.size() - 1) - cont << '\n';
	return true;
}

int main(){
	while (resolve());
	return 0;
}