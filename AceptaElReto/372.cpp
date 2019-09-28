#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int numcas;
	cin >> numcas;
	for (int i = 0; i < numcas;++i){
		int num;
		cin >> num;
		cout << num*num*2 + (num-1)*4*(num-2)<< '\n';
	}
	return 0;
}