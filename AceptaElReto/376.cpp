#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int num;
	cin >> num;

	while (num != 0){
		vector<int> v(num);
		for (int i = 0; i < num; ++i) cin >> v[i];

		int numPicos = 0;
		if (num == 2){
			if (v[0] != v[1]) numPicos = 1;
		}
		else{
			for (int i = 1; i <= num - 2; ++i){
				if (v[i]>v[i - 1] && v[i]>v[i + 1]) ++numPicos;
			}
			if (v[0] > v[num - 1] && v[0] > v[1]) ++numPicos;
			if (v[num - 1] > v[0] && v[num - 1] > v[num - 2]) ++numPicos;
		}

		cout << numPicos << '\n';

		cin >> num;
	}
	return 0;
}