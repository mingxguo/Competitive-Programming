#include <bits/stdc++.h>

using namespace std;

typedef vector<pair<int,int>> vii;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<iii> viii;
typedef vector<unordered_set<int>> adj;

/*MAXFLOW*/
int n,m;
int s = 0, t, f;
const int MAX_V = 500 + 2; // + 2 para el source y sink artificiales
vvi res; // matriz residual
adj adjList; // pon en adjList tambien los back edges
void augment(int v, int minEdge, vi &p) {
	if (v == s) {
		f = minEdge;
		return;
	}
	else if (p[v] != -1) {
		augment(p[v], min(minEdge, res[p[v]][v]), p);
		res[p[v]][v] -= f, res[v][p[v]] += f;
	}
}
int edmondsKarp() {
	int mf = 0;
	while (true) {
		f = 0;
		bitset<MAX_V> vis; vis[s] = true;
		queue<int> q; q.push(s);
		vi p(adjList.size(), -1);
		while (!q.empty()) {
			int u = q.front(); q.pop();
			if (u == t) break;
            for(auto it = adjList[u].begin(); it != adjList[u].end(); ++it){
                int v = *it;
				if (res[u][v] > 0 && !vis[v])
					vis[v] = true, q.push(v), p[v] = u;
            }
		}
		augment(t, INT_MAX, p);
		if (f == 0) break;
		mf += f;
	}
	return mf;
}

int L,W,N,D;

bool intersect(ii const& a, ii const& b){
    return ((a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second)) 
            <= 4*D*D;
}

int main(){
    int casos = 1;
    while(cin >> L >>W  >> N >> D, L+W+D+N){
        // Entrada
        vii defenders(N);
        for(int i =0;i<N;++i){
            cin >> defenders[i].first >> defenders[i].second;
        }

        // Construir grafo
        res = vvi(2*N+2, vi(2*N+2, 0));
        adjList = adj(2*N+2);
        for(int i = 0;i<N;++i){
            adjList[i+1].insert(i+N+1);
            adjList[i+N+1].insert(i+1);
            res[i+1][i+N+1] = 1;
            for(int j = 0;j<N;++j){
                if(i == j) continue;
                if(intersect(defenders[i], defenders[j])){
                    adjList[i+N+1].insert(j+1);
                    adjList[j+1].insert(i+N+1);
                    res[i+N+1][j+1] = 1;
                }
            }
        }
        for(int i=0;i<N;++i){
            // Toca abajo
            if(defenders[i].second <= D){
                adjList[i+1].insert(0);
                adjList[0].insert(i+1);
                res[0][i+1] = 1;
            }

            // Toca arriba
            if(abs(W - defenders[i].second) <= D){
                adjList[2*N+1].insert(i+N+1);
                adjList[i+N+1].insert(2*N+1);
                res[i+N+1][2*N+1] = 1;
            }
        }
        cout << "Case " << casos << ": " ;
        s = 0; t = 2*N+1;
        cout << edmondsKarp() << '\n';
        ++casos;
    }
    return 0;
}