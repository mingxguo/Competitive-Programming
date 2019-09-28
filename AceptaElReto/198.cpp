#include <iostream>
#include <queue>
#include <stack>
#include <string>

using namespace std;

bool evaluar(char op, stack<int> & pila){
	int op1, op2;
	op2 = pila.top();
	pila.pop();
	op1 = pila.top();
	pila.pop();
	switch (op)
	{
	case '*': pila.push(op1 * op2); return true;
	case '+': pila.push(op1 + op2); return true;
	case '-': pila.push(op1 - op2); return true;
	case '/': if (op2 == 0) return false;
		pila.push(op1 / op2); return true;
	default:
		break;
	}
}

bool evaluar(char op, queue<int> & cola){
	int op1, op2;
	op2 = cola.front();
	cola.pop();
	op1 = cola.front();
	cola.pop();
	switch (op)
	{
	case '*': cola.push(op1 * op2); return true;
	case '+': cola.push(op1 + op2); return true;
	case '-': cola.push(op1 - op2); return true;
	case '/': if (op2 == 0) return false;
		cola.push(op1 / op2); return true;
	default:
		break;
	}
}

bool resolve(){
	string expresion;
	if(!getline(cin, expresion))
		return false;
	queue<int> cola;
	stack<int> pila;
	bool errorPila = false;
	//pila
	for (int i = 0; i < expresion.size() && !errorPila; ++i){
		if (isdigit(expresion[i]))
			pila.push(int(expresion[i]) - int('0'));
		else
			errorPila = !evaluar(expresion[i], pila);
	}
	//cola
	bool errorCola = false;
	for (int i = 0; i < expresion.size() && !errorCola; ++i){
		if (isdigit(expresion[i]))
			cola.push(int(expresion[i]) - int('0'));
		else
			errorCola = !evaluar(expresion[i], cola);
	}
	//imprimir resultado
	if (errorPila && errorCola)
		cout << "ERROR = ERROR\n";
	else if (errorPila)
		cout << "ERROR != " << cola.front() << '\n';
	else if (errorCola)
		cout << pila.top() << " != ERROR\n";
	else if (cola.front() == pila.top())
		cout << pila.top() << " = " << cola.front() << '\n';
	else cout << pila.top() << " != " << cola.front() << '\n';

	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	while (resolve());
	return 0;
}