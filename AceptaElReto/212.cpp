#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main(){

//#ifndef DOMJUDGE
//	ifstream in("datos.txt");
//	auto cinbuf = cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
//#endif 

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int numAris;
	cin >> numAris;

	while (numAris != 0){
		int numVert, a, b;
		cin >> numVert;
		vector<int> v(numVert);
		for (int i = 0; i < numAris; ++i){
			cin >> a >> b;
			++v[a - 1];
			++v[b - 1];
		}

		int cont = 0;
		for (int i = 0; i < numVert; ++i){
			if (v[i] % 2 == 1) ++cont;
		}

		if (cont <= 2) cout << "SI\n";
		else cout << "NO\n";

		cin >> numAris;
	}

//#ifndef DOMJUDGE 
//	cin.rdbuf(cinbuf);
//	//system("PAUSE");
//#endif

	return 0;
}
