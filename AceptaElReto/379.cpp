#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int num;
	cin >> num;

	while (num != 0){
		vector<int> v(num);
		for (int &i : v)cin >> i;

		bool modificar = false;
		for (int i = num - 1; i >= 1 && !modificar; --i){
			if (v[i] - v[i - 1] == 0){
				++v[i];
				modificar = true;
			}
		}
		if (!modificar){
			++v[0];
			for (int i = 1; i < v.size(); ++i) v[i] = v[0];
		}

		cout << v[0];
		for (int i = 1; i < num; ++i) cout << ' ' << v[i];
		cout << '\n';

		cin >> num;
	}
	return 0;
}