#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int numcas;
	char aux;
	cin >> numcas;
	cin.get(aux);
	for (int i = 0; i < numcas;++i){
		string str,str2="";
		getline(cin,str);
		for (int j = str.size() - 1; j >= 0; --j){
			str2.push_back(str[j]);
		}
		for (int j = 0; j < str.size(); ++j) {
			if (isupper(str[j])) str2[j] = toupper(str2[j]);
			else str2[j] = tolower(str2[j]);
		}
		cout << str2 << '\n';
	}
	return 0;
}