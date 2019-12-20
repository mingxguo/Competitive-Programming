#include <iostream>
#include <map>
#include <fstream>
#include <set>
#include <string>

using namespace std;

int main(){
	/*ifstream in("datos.txt"); auto cinbuf = std::cin.rdbuf(in.rdbuf());
	ofstream out("sol.txt"); auto coutbuf = std::cout.rdbuf(out.rdbuf());*/
	int t;
	cin >> t;
	string aux;
	getline(cin, aux); getline(cin, aux);
	bool first = true;
	while (t--){
		if (!first) cout << '\n';
		map<int,set<string>> fragments;
		while (getline(cin, aux), aux != ""){
			fragments[aux.size()].insert(aux);
		}
		auto ini = fragments.begin();
		auto fin = fragments.rbegin();
		int l = ini->first + fin->first;
		bool enc = false;
		string sol;
		for (string i : ini->second){
			if (enc) break;
			for (string f : fin->second){
				if (enc) break;
				string s = i + f;
				bool match = true;
				//recorrer el mapa de fragmentos
				for (auto k : fragments){
					int lk = k.first;
					string a1 = s.substr(0, lk);
					string a2 = s.substr(l - lk, lk);
					//recorrer los fragmentos de cada longitud
					for (string str : k.second){
						if (a1!=str && a2!=str){
							match = false;
							break;
						}
					}
					if (!match)break;
				}
				if (match){
					enc = true;
					sol = s;
				}
				if (enc) break;
				s = f+i;
				match = true;
				//recorrer el mapa de fragmentos
				for (auto k : fragments){
					int lk = k.first;
					string a1 = s.substr(0, lk);
					string a2 = s.substr(l - lk, lk);
					//recorrer los fragmentos de cada longitud
					for (string str : k.second){
						if (a1 != str && a2 != str){
							match = false;
							break;
						}
					}
					if (!match)break;
				}
				if (match){
					enc = true;
					sol = s;
				}
			}
		}
		first = false;
		cout << sol << "\n";
	}
	/*std::cin.rdbuf(cinbuf);
	std::cout.rdbuf(coutbuf);*/
	return 0;
}