#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <utility>

using namespace std;

using lli = long int;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	lli num;
	cin >> num;

	while (num != 0){
		vector<pair<int, int>> v(num);
		for (lli i = 0; i < num; ++i) cin >> v[i].first >> v[i].second;

		sort(v.begin(), v.end(), less<pair<int, int>>());

		bool justo = true;

		for (lli i = 1; i < num && justo; ++i){
			if (v[i].first > v[i - 1].first && !(v[i].second > v[i - 1].second)) justo = false;
		}

		if (justo) cout << "SI\n";
		else cout << "NO\n";

		cin >> num;
	}

	return 0;
}