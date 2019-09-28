#include <iostream>
#include <queue>
#include <string>

using namespace std;

void resuelve(){
	queue<string> q;
	string nombre;
	//leer entradas
	cin >> nombre;
	while (nombre != "F"){
		q.push(nombre);
		cin >> nombre;
	}
	int numCama, numPalabra;
	cin >> numCama >> numPalabra;

	if (numCama >= q.size())
		cout << "TODOS TIENEN CAMA\n";
	else if (numCama == 0)
		cout << "NADIE TIENE CAMA\n";
	else{
		int i = 0;
		while (q.size() > numCama){
			int tam = q.size();
			for (int j = 0; j<tam; ++j){
				//toca eliminar
				if (q.size()>numCama && (i + 1) % numPalabra == 0)
					q.pop();
				//se mete al final de la cola para volver a tocar
				else{
					q.push(q.front());
					q.pop();
				}
				++i;
			}
		}
		//imprimir por pantalla
		cout << q.front();
		q.pop();
		while (!q.empty()){
			cout << ' ' << q.front();
			q.pop();
		}
		cout << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int numcas;
	cin >> numcas;
	while (numcas--)
		resuelve();
	return 0;
}