#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool resuelve() {
	int num;
	//leer entrada
	cin >> num;
	//centinela
	if (num == 0)
		return false;

	set<string> gusta;
	set<string> noGusta;
	for (int i = 0; i < num; ++i){
		string pal;
		cin >> pal;
		if (pal == "SI:"){
			cin >> pal;
			while (pal != "FIN"){
				gusta.insert(pal);
				cin >> pal;
			}
		}
		else{
			cin >> pal;
			while (pal != "FIN"){
				noGusta.insert(pal);
				cin >> pal;
			}
		}
	}
	//vector de soluciones
	vector<string> sol;
	set<string>::iterator it;
	for (it = noGusta.begin(); it != noGusta.end(); ++it){
		if (gusta.count(*it) == 0)sol.push_back(*it);
	}
	//ordenar palabras
	sort(sol.begin(), sol.end());

	//escribir solucion
	if (!sol.empty()){
		cout << sol[0];
		for (int i = 1; i < sol.size(); ++i){
			cout << ' ' << sol[i];
		}		
	}
	cout << '\n';
	return true;
}

int main(){
	while (resuelve());
	return 0;
}