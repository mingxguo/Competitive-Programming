#include <iostream>
#include <unordered_map>
#include <vector>
#include <fstream>
#include <cmath>
#include <string>

using namespace std;

int main(){


//		ifstream in("datos.txt"); auto cinbuf = std::cin.rdbuf(in.rdbuf());
//		ofstream out("sol.txt"); auto coutbuf = std::cout.rdbuf(out.rdbuf());

		int t;
		cin >> t;
		while (t--){
			int n, m;
			cin >> n >> m;

			vector<vector<bool> > mat;
			int tam = pow(2, n);
			for (int i = 0; i < n; ++i){
				vector<bool> v(tam, true);
				mat.push_back(v);
				tam /= 2;
			}
			mat.push_back(vector<bool>(1, true));

			int num;
			while (m--){
				cin >> num;
				mat[0][num - 1] = false;
			}

			int cont = 0;
			for (int i = 0; i < mat.size() - 1; ++i){
				for (int j = 0; j < mat[i].size(); j += 2){
					if (mat[i][j] == mat[i][j + 1] && mat[i][j] == false)
						mat[i + 1][j / 2] = false;
					else if (mat[i][j] != mat[i][j + 1])
						++cont;
				}
			}
			cout << cont << '\n';
		}
//		std::cin.rdbuf(cinbuf);
//		std::cout.rdbuf(coutbuf);
	return 0;
}