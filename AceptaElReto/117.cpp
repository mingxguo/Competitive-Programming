#include <iostream>
#include <string>

using namespace std;

const string saludo = "Hola,";

int main(){
	int numcas;
	char aux;
	cin >> numcas;
	cin.get(aux);
	for (int i = 0; i < numcas; ++i){
		string str;
		getline(cin, str);
		str.replace(0, 3, saludo);
		cout << str << ".\n";
	}
	return 0;
}