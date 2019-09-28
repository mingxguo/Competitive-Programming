#include <iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int num;
	cin >> num;
	while (num != 0){
		for (int i = 0; i < num; ++i)cout << '1';
		cout << '\n';
		cin >> num;
	}
	return 0;
}