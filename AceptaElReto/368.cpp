#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int numcas;
	cin >> numcas;
	for (int i = 0; i < numcas;++i){
		int n1, n2;
		char aux;
		cin >> n1 >> aux >> n2;
		if (abs(n1 - n2) == 1 && min(n1, n2) % 2 == 0) cout << "SI\n";
		else cout << "NO\n";
	}
	return 0;
}