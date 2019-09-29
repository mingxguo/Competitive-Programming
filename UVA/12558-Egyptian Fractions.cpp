#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;
using ll = long long int;

int a, b, k;
int limit = 100000000;
int forb[6];
vector<ll> res;


ll gcd(ll ax, ll bx) {
	if (bx == 0) return ax;
	return gcd(bx, ax%bx);
}

ll greatest(ll ax, ll bx) {
	return bx / ax + 1;
}

bool valid(int bx) {
	for (int i = 0; i < k; ++i)if (forb[i] == bx)return false;
	return true;
}

bool repeat(int bx, vector<ll> sol) {
	for (int i = 0; i < sol.size(); ++i) if (sol[i] == bx)return true;
	return false;
}

bool better(vector<ll> sol) {
	if (res.size() == 0)return true;
	if (sol.size() < res.size()) return true;
	else if (sol.size() > res.size()) return false;
	for (int i = sol.size() - 1; i >= 0; --i) {
		if (sol[i] < res[i]) return true;
		if (sol[i] > res[i]) return false;
	}
	return false;
}
//max layer, ax bx still to sum up
bool dfs(int maxl, int cur, ll ax, ll bx, vector<ll> sol) {
	if (cur == maxl) return false;
	if (ax == 1&&valid(bx) && !repeat(bx, sol)) {
		sol.push_back(bx);
		if (better(sol))res = sol;
		return true;
	}
	ll num = greatest(ax, bx);
	if (sol.size() > 0)num = max(num, sol.back()+1);
	bool ok = false;
	while (true) {
		//prone
		if ((maxl - cur)*bx <= num*ax)break;
		if (valid(num)) {
			ll nbx = bx * num;
			ll nax = ax * num - bx;
			ll g = gcd(nax, nbx);
			sol.push_back(num);
			if (dfs(maxl, cur + 1, nax / g, nbx / g, sol))ok = true;
			sol.pop_back();
		}
		++num;
	}
	return ok;
}

int main() {
	fstream in, out;
	in.open("in.txt", ios::in);
	out.open("out.txt", ios::out);
	cin.rdbuf(in.rdbuf());
	cout.rdbuf(out.rdbuf());
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		cout << "Case " << i + 1 << ": ";
		//input
		cin >> a >> b >> k;
		if (k) {
			for (int j = 0; j < k; ++j)cin >> forb[j];
		}
		vector<ll> sol;
		res.clear();
		int layer = 1;
		while (layer < limit && !dfs(layer, 0, a, b, sol)) {
			++layer;
		}
		cout << a << '/' << b << '=';
		for (int j = 0; j < res.size()-1; ++j)cout << 1<<'/'<<res[j] << '+';
		cout << 1 << '/' << res.back() << '\n';
	}
	return 0;
}