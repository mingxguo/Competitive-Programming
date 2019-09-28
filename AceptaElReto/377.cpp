#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	string str;
	while (getline(cin, str)){
		if (str.size() > 4) str = str.substr(str.size() - 4, str.size());
		int dec = 0;
		for (int i = 0; i<str.size(); ++i){
			dec += (str[str.size() - i - 1] -'0')  * pow(10,i);
		}
		int resto = dec % 16;
		if (resto == 0 || resto == 1 || resto == 4 || resto == 9) cout << "NO SE\n";
		else cout << "IMPERFECTO\n";
	}
	return 0;
}