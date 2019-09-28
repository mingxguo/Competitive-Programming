#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <utility>
#include <cctype>

using namespace std;

using ii = pair<int, int>;

int fmov[4] = { 1, 0, -1, 0 };
int cmov[4] = { 0, -1, 0, 1 };
int n, m;

bool enRango(int f, int c){
	return f >= 0 && c >= 0 && f < n && c < m;
}

void bfs(vector<vector<bool>> & marked, int f, int c){
	queue<ii> cola;
	cola.push({ f, c });
	marked[f][c] = true;
	while (!cola.empty()){
		ii u = cola.front();
		cola.pop();
		for (int dir = 0; dir < 4; ++dir){
			int nextf = u.first + fmov[dir];
			int	nextc = u.second + cmov[dir];
			if (enRango(nextf, nextc) && !marked[nextf][nextc]){
				cola.push({ nextf, nextc });
				marked[nextf][nextc] = true;
			}
		}
	}
}

int main(){
	/*ifstream in("datos.txt"); auto cinbuf = std::cin.rdbuf(in.rdbuf());
	ofstream out("sol.txt"); auto coutbuf = std::cout.rdbuf(out.rdbuf());*/
	while (cin >> m >> n){
		vector<vector<bool>> marked(n, vector<bool>(m, false));
		//lectura de la foto
		char c;
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < m; ++j){
				cin >> c;
				if (c == 'X') marked[i][j] = true;
			}
		}
		int cont = 0;
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < m; ++j){
				if (!marked[i][j]){
					bfs(marked, i, j);
					++cont;
				}
			}
		}
		if (cont>1) cout << "SI\n";
		else cout << "NO\n";
	}
	/*std::cin.rdbuf(cinbuf);
	std::cout.rdbuf(coutbuf);*/
	return 0;
}