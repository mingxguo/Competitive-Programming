#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <climits>
#include <iomanip>
#include <fstream>

using namespace std;

typedef vector<int> vi;

vi lis(const vi &a, int & lis_len) {
	vi L, L_id, P;
	L.assign(a.size(), 0);
	L_id.assign(a.size(), -1);
	P.assign(a.size(), -1);
	lis_len = 0;
	int lis_end = 0;
	for (int i = 0; i < a.size(); i++) {
		int pos = lower_bound(L.begin(), L.begin() + lis_len, a[i]) - L.begin();
		L[pos] = a[i];
		if (L_id[pos] == -1) {
			L_id[pos] = i;
		}
		else {
			L_id[pos] = min(L_id[pos], i);
		}
		P[i] = pos ? L_id[pos - 1] : -1;
		if (pos == lis_len) {
			lis_len++;
			lis_end = i;
		}
	}
	return L_id;
}

int main() {

	//ifstream in("datos.txt"); auto cinbuf = std::cin.rdbuf(in.rdbuf());
	//ofstream out("out.txt"); auto coutbuf = std::cout.rdbuf(out.rdbuf());
	int n;
	while (cin >> n) {
		vector<int> w(n);
		vector<int> v(n);
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
			w[n - i - 1] = v[i];
		}
		int vlis_len, wlis_len;
		auto vlis = lis(v, vlis_len);
		auto wlis = lis(w, wlis_len);
		int imax = 0;
		for (int i = 0; i < min(vlis_len, wlis_len); ++i) {
			if (vlis[i] + wlis[i] < n) {
				imax = max(imax, i + 1);
			}
		}
		cout << imax*2-1 << '\n';

	}
	return 0;
}