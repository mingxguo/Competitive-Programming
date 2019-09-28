#include <iostream>
#include <queue>
#include <stack>

using namespace std;

bool resolve(){
	queue<int> tortitas;
	stack<int> vuelta;
	int tam;
	//leer tortitas
	cin >> tam;
	while (tam != -1){
		vuelta.push(tam);
		cin >> tam;
	}
	while (!vuelta.empty()){
		tortitas.push(vuelta.top());
		vuelta.pop();
	}
	//leer numero de movimientos
	int numVueltas;
	cin >> numVueltas;
	if (tortitas.empty())
		return false;

	//simular el proceso de volteo para cada movimiento
	while (numVueltas--){
		int numTortitas;
		cin >> numTortitas;
		for (int i = 0; i < numTortitas;++i){
			vuelta.push(tortitas.front());
			tortitas.pop();
		}for (int i = 0; i < numTortitas; ++i){
			tortitas.push(vuelta.top());
			vuelta.pop();
		}
		for (int i = 0; i < tortitas.size()-numTortitas; ++i){
			tortitas.push(tortitas.front());
			tortitas.pop();
		}
	}
	cout << tortitas.front() << '\n';
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	while (resolve());
	return 0;
}