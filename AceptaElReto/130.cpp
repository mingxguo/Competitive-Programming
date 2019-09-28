#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	long long int n;
	cin >> n;
	while (n != 0){
		long long int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		
		if (x1==x2 && y1==y2) cout << "0\n";
		else{
			int num1 = abs(x2 - x1), num2 = abs(y2 - y1);
			if (num1 == num2) cout << "1\n";
			else if (num1 % 2 == num2 % 2) cout << "2\n";
			else cout << "IMPOSIBLE\n";
		}
		cin >> n;
	}
}