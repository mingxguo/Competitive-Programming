#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

int main(){
	ifstream in("datos.txt");
	ofstream out("salida.txt");
	auto cinbuf = cin.rdbuf(in.rdbuf());
	auto coutbuf = cout.rdbuf(out.rdbuf());

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int num;
	string str;
	while (cin >> num){
		getline(cin, str);
		if (num == 18) cout << 36;
		else cout << setw(2) << setfill('0') << (num + 18) % 36;
		if (str != "\n"){
			switch (str[0])
			{
			case 'R': cout << 'L'; break;
			case 'L': cout << 'R'; break;
			case 'C': cout << 'C'; break;
			default:
				break;
			}
		}
		cout << '\n';
	}

#ifndef DOMJUDGE
	cin.rdbuf(cinbuf);
	cout.rdbuf(coutbuf);
#endif
	return 0;
}