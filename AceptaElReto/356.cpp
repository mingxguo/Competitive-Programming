#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	long long int numcas;
	cin >> numcas;
	for (int i = 0; i < numcas; ++i){
		vector<long long int> v(3);
		for (long long int &j : v)cin >> j;
		sort(v.begin(), v.end());
		cout << v[0] << ' ' << v[1] << ' ' << v[2] << '\n';
	}
	return 0;
}