#include <iostream>
#include <deque>

using namespace std;

bool resolve(){
	int num;
	cin >> num;
	if (!num)
		return false;
	//generar la lista
	deque<int> dq;
	for (int i = 0; i < num; ++i) dq.push_back(i + 1);
	int salto = 2, tam = dq.size();
	while (salto <= tam){
		for (int i = 0; i < tam; ++i){
			if (i%salto != 0)
				dq.push_back(dq.front());
			dq.pop_front();
		}
		++salto;
		tam = dq.size();
	}
	cout << num << ':';
	while (!dq.empty()){
		cout << ' ' << dq.back();
		dq.pop_back();
	}
	cout << '\n';
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	while (resolve());
	return 0;
}