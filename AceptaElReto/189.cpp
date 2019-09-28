#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){

	//#ifndef DOMJUDGE
	//	ifstream in("datos.txt");
	//	auto cinbuf = cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
	//#endif 

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	long int n;
	cin >> n;
	while (n != 0){
		vector<long int> v(n);
		for (long int & i : v)cin >> i;
		long int numAc;
		cin >> numAc;
		for (long int i = 0; i < numAc; ++i){
			string accion; long int param;
			cin >> accion >> param;
			if (accion == "EMBARQUE"){
				long int cont = 0, j = 0;
				while(j<v.size()){
					if (v[j] == param){
						++cont;
						v.erase(v.begin() + j);
					}
					++j;
				}
				cout << n - cont << '\n';
			}
			else if (accion == "CONSULTA"){
				cout << v[param - 1] << '\n';
			}
		}
		cout << "*\n";

		cin >> n;
	}
	//#ifndef domjudge 
	//	cin.rdbuf(cinbuf);
	//	//system("pause");
	//#endif
	return 0;
}
