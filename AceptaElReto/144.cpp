#include <iostream>
#include <list>
#include <string>

using namespace std;

bool resolve(){
	string mensaje;
	if (!getline(cin, mensaje))
		return false;

	list<char> resul;
	list<char>::iterator it = resul.begin();
	for (int i = 0; i < mensaje.size(); ++i){
		switch (mensaje[i])
		{
		case '-': it = resul.begin(); break;
		case '+': it = resul.end(); break;
		case '*': 
			if (it != resul.end())
				++it;
			break;
		case '3': 
			if (it != resul.end())
				resul.erase(it++);
			break;
		default:
			resul.insert(it, mensaje[i]);
			break;
		}
	}
	for (auto i : resul) 
		cout << i;
	cout << '\n';
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	while (resolve());
	return 0;
}
