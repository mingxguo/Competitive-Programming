#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

using transition = vector<int>;

int np, nt, nf;

bool possible(vector<int> const& state, transition t, vector<int> & next) {
	for (int i = 0; i < np; ++i) {
		next[i] = state[i] + t[i];
		if (next[i] < 0) return false;
	}
	return true;
}

bool dfs(vector<int> const& state, vector<transition> const& trans, int k, vector<int> & sol, int & cnt) {
	if (k == 0) {
		sol = state;
		return true;
	}
	if (nf - k > cnt) {
		sol = state;
		cnt = nf - k;
	}
	//through all possible transitions
	vector<int> next(np);
	for (int i = 0; i < nt; ++i) {
		if (possible(state, trans[i], next)) return dfs(next, trans, k - 1, sol, cnt);
	}
	return false;
}

int main() {
	/*fstream in, out;
	in.open("in.txt", ios::in);
	out.open("out.txt", ios::out);
	cin.rdbuf(in.rdbuf());
	cout.rdbuf(out.rdbuf());*/
	int kase = 1;
	cin >> np;
	while (np) {
		cout << "Case " << kase << ": ";
		vector<int> initial(np);
		for (int i = 0; i < np; ++i) {
			cin >> initial[i];
		}
		cin >> nt;
		int aux;
		vector<transition> trans(nt);
		for (int i = 0; i < nt; ++i) {
			vector<int> change(100, 0);
			cin >> aux;
			while (aux != 0) {
				if (aux < 0) change[abs(aux) - 1]--;
				else change[aux - 1]++;
				cin >> aux;
			}
			trans[i] = change;
		}
		cin >> nf;
		//simulation
		vector<int> sol;
		int cnt = 0;
		if (dfs(initial, trans, nf, sol, cnt)) {
			cout << "still live after " << nf << " transitions\n";			
		}
		else cout << "dead after " << cnt << " transitions\n";
		cout << "Places with tokens:";
		for (int i = 0; i < np; ++i) {
			if (sol[i] > 0) cout << ' ' << i + 1 << " (" << sol[i] << ')';
		}
		cout << "\n\n";
		++kase;
		cin >> np;
	}
	return 0;
}