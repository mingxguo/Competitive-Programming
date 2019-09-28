#include <iostream>
#include <map>
#include <string>
#include <set>
#include <sstream>

using namespace std;

bool resolve(){
	int num;
	cin >> num;
	if (!num)
		return false;
	
	char aux;
	cin.get(aux);

	map<string, int> ec;
	//leer los alumnos y puntuarlos
	string alumno,puntuacion;
	while (num--){
		getline(cin, alumno);
		getline(cin, puntuacion);
		if (puntuacion == "CORRECTO")
			++ec[alumno];
		else --ec[alumno];
	}
	//escribir resultado
	for (auto const& cv : ec){
		if (cv.second != 0)
			cout << cv.first << ", " << cv.second << '\n';
	}
	cout << "---\n";
	return true;
}

int main(){
	while (resolve());
	return 0;
}