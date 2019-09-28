#include <iostream>
#include <deque>
#include <queue>

using namespace std;

bool resolve(){
	int n, k;
	cin >> n >> k;
	if (n == 0 && k == 0)
		return false;

	queue<int> q;
	int num;
	deque<int> maximos;

	//leer los primeros k numeros
	for (int i = 0; i<k;++i){
		//anyadir numero a la cola
		cin >> num;
		q.push(num);
		//modificar los maximos
		if (!maximos.empty()){
			if (num > maximos.front())
				maximos.clear();
			else{
				while (num > maximos.back())
					maximos.pop_back();
			}
		}
		maximos.push_back(num);
	}
	//imprimir el primer maximo
	cout << maximos.front();

	for (int i = k; i<n; ++i){
		if (q.front() == maximos.front())
			maximos.pop_front();
		//eliminar primer numero
		q.pop();

		//anyadir siguiente numero a la cola
		cin >> num;
		q.push(num);
		//modificar los maximos
		if (!maximos.empty()){
			if (num > maximos.front())
				maximos.clear();
			else{
				while (num > maximos.back())
					maximos.pop_back();
			}
		}
		maximos.push_back(num);

		cout << ' ' << maximos.front();

	}
	cout << '\n';
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	while (resolve());
	return 0;
}