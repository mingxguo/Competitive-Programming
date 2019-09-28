#include <iostream>
#include <string>
#include <queue>
#include <stack>

using namespace std;

bool isVowel(char c){
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
		c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

bool resolve(){
	string mensaje;
	if (!getline(cin, mensaje))
		return false;

	queue<char> q;
	//decodificar 2 fase
	int i = 0;
	while (i < mensaje.size()){
		q.push(mensaje[i]);
		i += 2;
	}
	if (i == mensaje.size())
		i -= 1;
	else i -= 3;
	while (i>0){
		q.push(mensaje[i]);
		i -= 2;
	}
	//decodificar 1 fase
	string decodificado;
	stack<char> pila;
	while (!q.empty()){
		if (isVowel(q.front())){
			while (!pila.empty()){
				decodificado.push_back(pila.top());
				pila.pop();
			}
			decodificado.push_back(q.front());
		}
		else pila.push(q.front());
		q.pop();
	}
	while (!pila.empty()){
		decodificado.push_back(pila.top());
		pila.pop();
	}
	cout << mensaje << " => " << decodificado << '\n';
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	while (resolve());
	return 0;
}