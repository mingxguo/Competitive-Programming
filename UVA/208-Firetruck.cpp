#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int dest;
int graph[22][22];
int vis[22];
int cnt;

void dfs(int cur) {
	vis[cur] = 1;
	for (int i = 0; i < 22; ++i) {
		if (graph[cur][i] == 1 && !vis[i])dfs(i);
	}
}

void dfs(int cur, vector<int> sol) {
	//cout sol
	if (cur == dest) {
		++cnt;
		for (int i = 0; i < sol.size(); ++i) {
			cout << '\t' << sol[i];
		}
		cout << '\n';
		return;
	}
	vis[cur] = 1;
	sol.push_back(cur);
	for (int i = 0; i < 22; ++i) {
		if (graph[cur][i] == 1 && !vis[i]) {
			dfs(i);
		}
	}
	vis[cur] = 0;
	sol.pop_back();
}

int main() {
	fstream in, out;
	in.open("in.txt", ios::in);
	out.open("out.txt", ios::out);
	cin.rdbuf(in.rdbuf());
	cout.rdbuf(out.rdbuf());
	int kase = 1;
	while (cin >> dest) {
		cout << "CASE " << kase << ":\n";
		memset(graph, 0, sizeof(graph));
		memset(vis, 0, sizeof(vis));
		cnt = 0;
		int u, v;
		while (cin >> u >> v, u + v) {
			graph[u][v] = graph[v][u] = 1;
		}
		dfs(1);
		//reachable
		if (vis[dest]) {
			memset(vis, 0, sizeof(vis));
			vector<int> sol;
			dfs(1, sol);
			cout << "There are " << cnt << " routes from the firestation to streetcorner " << dest << ".\n";
		}
	}
	return 0;
}