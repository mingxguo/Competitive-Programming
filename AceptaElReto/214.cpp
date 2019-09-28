#include <iostream>
#include <unordered_map>
#include <string>
#include <set>
#include <sstream>

using namespace std;

bool resolve(){
	int numReyes, numSucs;
	cin >> numReyes;
	if (!numReyes)
		return false;

	//preparar el mapa de reyes y contar cuantos hay con el mismo nombre
	unordered_map<string, int> reyes;
	string rey;
	while (numReyes--){
		cin >> rey;
		reyes[rey]++;
	}
	//tratar los sucesores y sacar resultado por pantalla
	cin >> numSucs;
	while (numSucs--){
		cin >> rey;
		reyes[rey]++;
		cout << reyes[rey]<<'\n';
	}
	cout << '\n';
	return true;

}

int main(){
	while (resolve());
	return 0;
}