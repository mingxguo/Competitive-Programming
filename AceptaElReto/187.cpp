#include <iostream>
#include <stack>
#include <utility>

using namespace std;

using carta = pair<int, char>;

//funcion que intenta colocar la carta dada
bool colocar(carta const& c, int & oro, int & copa, int & espada, int & basto){
	switch (c.second)
	{
	case 'O':
		if (oro == 7 && c.first == 10){
			oro = 10;
			return true;
		}
		else if (c.first - oro == 1){
			++oro;
			return true;
		}
		else return false;
		break;
	case 'C':
		if (copa == 7 && c.first == 10){
			copa = 10;
			return true;
		}
		else if (c.first - copa == 1){
			++copa;
			return true;
		}
		else return false;
		break;
	case 'E':
		if (espada == 7 && c.first == 10){
			espada = 10;
			return true;
		}
		else if (c.first - espada == 1){
			++espada;
			return true;
		}
		else return false;
		break;
	case 'B':
		if (basto == 7 && c.first == 10){
			basto = 10;
			return true;
		}
		else if (c.first - basto == 1){
			++basto;
			return true;
		}
		else return false;
		break;
	default:
		break;
	}
}

//funcion que comprueba si se puede ganar el solitario
bool solitario(stack<carta> & mazo, stack<carta> & descubiertas){
	bool perder = false;
	int oro = 0, copa = 0, espada = 0, basto = 0;
	//mientras la partida no ha terminado
	while (!mazo.empty() && !perder){
		bool colocado = false;
		//descubrir todas las cartas del mazo
		while (!mazo.empty()){
			//descubrir 2 cartas 
			descubiertas.push(mazo.top());
			mazo.pop();
			if (!mazo.empty()){
				descubiertas.push(mazo.top());
				mazo.pop();
			}
			//intentar colocar las cartas descubiertas
			if (colocar(descubiertas.top(), oro, copa, espada, basto)){
				descubiertas.pop();
				colocado = true;
			}
			while (!descubiertas.empty() && colocar(descubiertas.top(), oro, copa, espada, basto))
				descubiertas.pop();
		}
		//da la vuelta a las cartas descubiertas para volver a jugar
		while (!descubiertas.empty()){
			mazo.push(descubiertas.top());
			descubiertas.pop();
		}
		//ha perdido si no ha podido colocar ninguna carta durante la jugada
		perder = !colocado;
	}
	if (perder)
		return false;
	else return true;
}

bool resuelve(){
	int n;
	cin >> n;
	//centinela
	if (n == 0)
		return false;

	stack<carta> descubiertas, mazo;
	carta c;
	//leer entradas
	for (int i = 0; i < 10 * n; ++i){
		cin >> c.first >> c.second;
		descubiertas.push(c);
	}
	while (!descubiertas.empty()){
		mazo.push(descubiertas.top());
		descubiertas.pop();
	}

	if (solitario(mazo, descubiertas))
		cout << "GANA\n";
	else cout << "PIERDE\n";

	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	while (resuelve());
	return 0;
}