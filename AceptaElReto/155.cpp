#include <iostream>

using namespace std;

int main(){
	long long int x, y;
	cin >> x >> y;
	while (x >= 0 && y >= 0){
		cout << (x + y) * 2 << '\n';
		cin >> x >> y;
	}
}