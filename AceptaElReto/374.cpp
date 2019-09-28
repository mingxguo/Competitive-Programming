#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	long long int numcas;
	cin >> numcas;
	for (long long int i = 0; i < numcas;++i){
		long long int num;
		cin >> num;
		long long int min = num, max = num, numMin = 1, numMax = 1;
		cin >> num;
		while (num != 0){
			if (num < min){
				min = num;
				numMin = 1;
			}
			
			else if (num>max){
				max = num;
				numMax = 1;
			}
			else{
				if (num == min) ++numMin;
				if (num == max) ++numMax;
			}

			cin >> num;
		}
		
		cout << min << ' ' <<numMin <<' '<< max << ' ' <<numMax << '\n';
	}
	return 0;
}