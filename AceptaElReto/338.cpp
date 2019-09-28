#include <iostream>
#include <map>
#include <string>
#include <set>
#include <queue>

using namespace std;

bool resolve(){
	int numTotal, numMemoria;
	cin >> numTotal >> numMemoria;
	if (!cin)
		return false;

	map<int, int> total, memoria;
	queue<int> q;
	int examen, copiados = 0, detectados = 0;
	for (int i = 0; i < numTotal; ++i){
		cin >> examen;
		
		//si es un examen copiado en general
		if (total.count(examen) > 0){
			++copiados;
			//si es un examen copiado detectado
			if (memoria.count(examen) > 0)
				++detectados;
		}
		//acordarse del nuevo examen
		memoria[examen]++;
		total[examen]++;
		q.push(examen);
		//olvidarse de examenes anteriores
		if (q.size() > numMemoria){
			memoria[q.front()]--;
			if (memoria[q.front()] == 0)
				memoria.erase(q.front());
			q.pop();
		}
	}

	//escribir resultado
	cout << copiados << ' ' << detectados << '\n';
	return true;
}


int main(){
	while (resolve());
	return 0;
}