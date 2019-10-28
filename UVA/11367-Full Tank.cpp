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

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;
typedef vector<iii> viii;

int n, m, q;
int c, ori, dest;
int cost;
vi prices;


void dijkstra(int s, vector<vii> &adjList, vvi &dist) {
	dist.assign(n, vi(c+1, INT_MAX));
	dist[s][0] = 0;
	priority_queue<iii, viii, greater<iii>> pq; pq.push({ 0, {s, 0} });
	while (!pq.empty()) {
		auto front = pq.top(); pq.pop();
		int d = front.first;
		auto u = front.second;
		if (u.first == dest) {
			cost = d;
			return;
		}
		if (d > dist[u.first][u.second]) continue;
		int city = u.first;
		int tank = u.second;
		for (int j = 0; j < adjList[city].size(); j++) {
			ii v = adjList[city][j];
			int distancia = v.first;
			int adj = v.second;
			if (tank < distancia) continue;
			if (d < dist[adj][tank-distancia]) {
				dist[adj][tank - distancia] = d;
				pq.push({ d, {adj, tank - distancia} });
			}
			
		}
		if (tank < c && d + prices[city] < dist[city][tank+1]) {
			dist[city][tank + 1] = d + prices[city];
			pq.push({ d + prices[city], {city, tank + 1} });
		}
	}
}

int main() {
	while (cin >> n >> m) {
		prices.assign(n, 0);
		for (int i = 0; i < n; ++i) {
			cin >> prices[i];
		}
		int u, v, d;
		vector<vii> adjList(n);
		for (int i = 0; i < m; ++i) {
			cin >> u >> v >> d;
			adjList[u].push_back({ d, v });
			adjList[v].push_back({ d, u });
		}
		cin >> q;
		for (int i = 0; i < q; ++i) {
			cin >> c >> ori >> dest;

			vvi dist;
			cost = INT_MAX;
			dijkstra(ori, adjList, dist);

			if (cost == INT_MAX) {
				cout << "impossible\n";
			}
			else {
				cout << cost << '\n';
			}
		}
	}
	return 0;
}