#include <vector>
#include <string>
#include <iostream>
#include <unordered_set>
#include <utility>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <climits>
#include <queue>
#include <fstream>


using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

void dijkstra(int s, vector<vii> &adjList, vi &dist) {
	dist.assign(adjList.size(), INT_MAX);
	dist[s] = 0;
	priority_queue<ii, vii, greater<ii>> pq; pq.push(ii(0, s));
	while (!pq.empty()) {
		ii front = pq.top(); pq.pop();
		int d = front.first, u = front.second;
		if (d > dist[u]) continue;
		for (int j = 0; j < adjList[u].size(); j++) {
			ii v = adjList[u][j];
			if (dist[u]+ v.first < dist[v.second]) {
				dist[v.second] = dist[u] + v.first;
				pq.push(ii(dist[v.second], v.second));
			}
		}
	}
}

int n, m; 
vector<vector<int>> adj; // matriz de adyacencia del grafo
vector<vector<int>> memo; 

// devuelve el coste de ir desde pos al origen (el v¨¦rtice 0)
// pasando por todos los v¨¦rtices no visitados (con un bit a 0)
int tsp(int V, int pos, int visitados) {
	if (visitados == (1 << V) - 1) // hemos visitado ya todos los v¨¦rtices
		return adj[pos][0]; // volvemos al origen
	if (memo[pos][visitados] != -1)
		return memo[pos][visitados];

	int res = 1000000000;
	for (int i = 1; i < V; ++i)
		if (!(visitados & (1 << i))) // no hemos visitado v¨¦rtice i
			res = min(res, adj[pos][i] + tsp(V, i, visitados | (1 << i)));
	return memo[pos][visitados] = res;
}

int main() {
	//ifstream in("datos.txt");
	//ofstream out("out.txt");
	//cin.rdbuf(in.rdbuf());
	//cout.rdbuf(out.rdbuf());
	int t;
	cin >> t;
	while (t--) {
		vi dist;
		cin >> n >> m;
		vector<vii> adjList(n);
		while (m--) {
			int u, v, c;
			cin >> u >> v >> c;
			adjList[u].push_back({c,v});
			adjList[v].push_back({ c,u });
		}
		int q;
		cin >> q;
		vi super(q);
		for(int i=0;i<q;++i) {
			cin >> super[i];
		}

		// q supers y el vertice 0 (casa)
		adj.assign(q+1, vector<int>(q+1, 0));
		memo.assign(q+1, vector<int>(1 << q+1, -1));
		//rellenar adj para tsp
		for (int i = 0; i < q; ++i) {
			vi dist(n);
			dijkstra(super[i], adjList, dist);
			for (int j = 0; j < q; ++j) {
				if (i == j) continue;
				adj[i + 1][j + 1] = dist[super[j]];
				adj[j + 1][i + 1] = dist[super[j]];
			}
			adj[0][i + 1] = dist[0];
			adj[i + 1][0] = dist[0];
		}

		/*for (int i = 0; i < q + 1; ++i) {
			for (int j = 0; j <= q; ++j) {
				cout << adj[i][j] << ' ';
			}
			cout << endl;
		}*/
		cout << tsp(q+1, 0, 1 << 0) << '\n';
	}
	return 0;
}