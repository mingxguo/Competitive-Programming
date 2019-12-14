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
typedef pair<int, iii> iiii;
typedef vector<vector<int>> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<iiii> viiii;


#define INF INT_MAX/2


int A,B,M,L,K, ori, dest;
int cost;

// dist[vertice][botas usadas][distancia recorrida con las botas]
void dijkstra(int s, vector<vii> &adjList, vvvi &dist) {
        dist.assign(A+B, vvi(K+1, vi(L+1, INF)));
	dist[s][0][0] = 0;
	priority_queue<iiii, viiii, greater<iiii>> pq; pq.push({ 0, {s, {0, 0}}});
	while (!pq.empty()) {
		auto front = pq.top(); pq.pop();
		int d = front.first;
		auto u = front.second;
		int city = u.first;
		int botas_usadas = u.second.first;
		int distancia_recorrida = u.second.second;
		if (city == dest) {
			cost = d;
			return;
		}
		if (d > dist[city][botas_usadas][distancia_recorrida]) continue;
		for (int j = 0; j < adjList[city].size(); j++) {
			ii v = adjList[city][j];
			int distancia = v.first;
			int adj = v.second;
			//he venido usando botas
			if(distancia_recorrida > 0){
			  //tengo que parar de usar las mismas
			  if(city >= A || (distancia_recorrida + distancia) > L){
			     // se puede usar nuevas botas
			    if(distancia <= L && botas_usadas+1 < K){
			      if (d < dist[adj][botas_usadas+1][distancia]) {
				dist[adj][botas_usadas+1][distancia] = d;
				pq.push({ d, {adj, {botas_usadas+1, distancia}} });
			      }
			    }
			  }
			  //se puede seguir usando las mismas botas
			  else{
			    if (d < dist[adj][botas_usadas][distancia_recorrida+distancia]) {
				dist[adj][botas_usadas][distancia_recorrida+distancia] = d;
				pq.push({d, {adj, {botas_usadas, distancia_recorrida+distancia}} });
			    }
			  }
			  // seguir el camino sin usar botas nuevas
			  if (d + distancia < dist[adj][botas_usadas+1][0]) {
			    dist[adj][botas_usadas+1][0] = d + distancia;
			    pq.push({ d + distancia, {adj, {botas_usadas+1, 0}} });
			  }			
			}
			//no he venido con botas
			else{
			  // se puede usar botas
			  if(distancia <= L && botas_usadas < K){
			    if (d < dist[adj][botas_usadas][distancia]) {
			      dist[adj][botas_usadas][distancia] = d;
			      pq.push({ d, {adj, {botas_usadas, distancia}} });
			    }
			  }
			  // no se puede usar botas o no usar aunque se pueda
			  if (d + distancia < dist[adj][botas_usadas][0]) {
			    dist[adj][botas_usadas][0] = d + distancia;
			    pq.push({ d + distancia, {adj, {botas_usadas, 0}} });
			  }
			}
		}
	}
}

int main(){
  int casos;
  cin >> casos;
  while(casos--){
    cin >> A >> B >> M >> L >> K;
    vector<vii> adjList(A+B);
    while(M--){
      int u, v, d;
      cin >> u >> v >> d;
      --u;--v;
      adjList[u].push_back({d, v});
      adjList[v].push_back({d, u});
    }

    ori = A+B-1;
    dest = 0;
    vvvi dest;
    dijkstra(ori, adjList, dest);
    cout << cost << '\n';
    
  }
  return 0;
}
