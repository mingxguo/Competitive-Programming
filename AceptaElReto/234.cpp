#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int main(){

	//#ifndef DOMJUDGE
	//	ifstream in("datos.txt");
	//	auto cinbuf = cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
	//#endif 

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int numcas; 
	cin >> numcas;
	for (int i = 0; i < numcas; ++i){
		int numPilas, voltaje;
		cin >> numPilas >> voltaje;

		vector<int> pilas(numPilas);
		for (int &j : pilas)cin >> j;
		sort(pilas.begin(), pilas.end());

		int numCoches = 0;
		int j = 0, k = numPilas - 1;
		while (k>j){
			while (j < k && pilas[j] + pilas[k] < voltaje)++j;
			if (j < k){
				++numCoches;
				++j;
			}
			--k;
		}
		cout << numCoches << '\n';
	}

	//#ifndef domjudge 
	//	cin.rdbuf(cinbuf);
	//	//system("pause");
	//#endif
	return 0;
}