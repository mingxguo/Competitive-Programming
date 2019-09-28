#include <iostream>
#include <set>

using namespace std;

//funcion que calcula el siguiente numero
//coste lineal segun el numero de digitos del numero recibido
int siguiente(int num){
	int suma = 0;
	while (num != 0){
		int digit = num % 10;
		suma += digit*digit*digit;
		num /= 10;
	}
	return suma;
}

//funcion que comprueba si el numero es cubifinito
void cubifinito(int num){
	if (num == 1)
		cout << "1 -> cubifinito.\n";
	else{
		set<int> cjto;
		while (num != 1 && cjto.count(num) == 0){
			cout << num << " - ";
			cjto.insert(num);
			num = siguiente(num);
		}
		cout << num;
		if (num == 1)
			cout << " -> cubifinito.\n";
		else cout << " -> no cubifinito.\n";
	}
}

bool resol(){
	int num;
	//leer entrada
	cin >> num;
	//centinela
	if (num == 0)
		return false;
	//tratar numero
	cubifinito(num);
	return true;
}

int main(){
	while (resol());
	return 0;
}