#include <iostream>
#include <queue> 
#include <utility>
#include <functional>
#include <algorithm>

using namespace std;

using ii = pair<int, int>;

bool comprobar(queue<ii> cola, int numMicro, int const& T){
	priority_queue<int, vector<int>, greater<int>> pq;

	if (cola.size() <= numMicro)
		return true;
	else{
		//primera ronda
		for (int i = 0; i < numMicro; ++i){
			ii p = cola.front();
			cola.pop();
			pq.push(p.first + p.second);
		}

		while (!cola.empty()){
			ii persona = cola.front(); cola.pop();
			int tiempo = pq.top(); pq.pop();
			//puede acceder a una microonda
			if (persona.first + T >= tiempo)
				//actualizar microondas
				pq.push(max(tiempo, persona.first) + persona.second);
			else return false;
		}
		return true;
	}
}

int main(){
	int n, T;
	cin >> n >> T;
	while (n != 0 || T != 0){
		//un caso
		queue<ii> cola;
		ii p;
		//leer cola de personas
		for (int i = 0; i < n; ++i){
			cin >> p.first >> p.second;
			cola.push(p);
		}
		//solucion = num de microondas
		int sol = 0;
		//si hay persona
		if (n != 0){
			//busqueda binaria
			int ini = 1, fin = n;
			while (ini < fin){
				int mitad = (ini + fin) / 2;
				if (comprobar(cola, mitad, T))
					fin = mitad;
				else ini = mitad + 1;
			}
			sol = ini;
		}
		//escribir solucion
		cout << sol << '\n';
		cin >> n >> T;
	}
	return 0;
}