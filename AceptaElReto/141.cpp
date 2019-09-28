#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool resuelve(){
	string str;
	//fin de entrada
	if(!getline(cin, str))
		return false;

	bool balanceado = true;
	stack<char> p;
	for (int i = 0; i < str.length() && balanceado; ++i){
		switch (str[i]){
		case '(':
		case '{':
		case '[': p.push(str[i]); break;
		case ')':
			if (p.empty() || p.top() != '(')
				balanceado = false;
			else if(!p.empty())
				p.pop(); break;
		case '}':
			if (p.empty() || p.top() != '{')
				balanceado = false;
			else if (!p.empty())
				p.pop(); break;
		case ']':
			if (p.empty() || p.top() != '[')
				balanceado = false;
			else if (!p.empty())
				p.pop(); break;
		default: break;
		}
	}
	if (balanceado && p.empty())
		cout << "YES\n";
	else cout << "NO\n";

	return true;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (resuelve());
	return 0;
}