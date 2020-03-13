#include <vector>
#include <string>
#include <iostream>
#include <unordered_set>
#include <utility>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;


const int UNVISITED = -1;
vi S;

vvi adjList, sccs;
int V, dfsCounter;
vi dfs_num, dfs_low, cur_scc;

unordered_map<string,int> mapa;
unordered_map<int,string> reverse_mapa;

void tarjanSCC(int u) {
    //cout<<u<<endl;
    dfs_num[u] = dfs_low[u] = dfsCounter++;
    cur_scc[u] = 1;
    S.push_back(u);
    for (int j = 0; j < adjList[u].size(); j++) {
        int v = adjList[u][j];
        if (dfs_num[v] == 0)
            tarjanSCC(v);
        if (cur_scc[v] == 1) // El nodo v ha sido visitado, pero esta en la misma SCC que u? Podria tratarse de un forward edge a otra SCC.
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }
        // inserta aqui u en un vector para generar un reverse toposort si quieres.
    if (dfs_low[u] == dfs_num[u]) {
        vi scc;
        while (true) {
            int v = S.back(); S.pop_back();
            cur_scc[v] = 0;
            scc.push_back(v);
            if (u == v) break;
        }
        sccs.push_back(scc);
    }
}
int main(){
    int n, m;
    int casos = 1;
    while(cin>>n >> m, n+m){
        int counter = 0;
        dfs_low = vi(n,-1);
        dfs_num = vi(n,0);
        cur_scc = vi(n,0);
        dfsCounter = 1;
        mapa.clear();
        S.clear();
        sccs.clear();
        reverse_mapa.clear();
        adjList = vvi(n);
        int N = n;
        string s,t;
        while(m--){
            cin >> s >> t;
            if(mapa.find(s)==mapa.end()){
                mapa[s] = counter;
                reverse_mapa[counter] = s;
                ++counter;
            }
            if(mapa.find(t)==mapa.end()){
                mapa[t] = counter;
                reverse_mapa[counter] = t;
                ++counter;
            }
            adjList[mapa[s]].push_back(mapa[t]);
        }
        for(int i=0; i < n; ++i){
            if(dfs_num[i]==0){
                tarjanSCC(i);
            }
        }
        vector<string> listas;
        //cout<<sccs.size()<<endl;
        for(int i=0; i < sccs.size();++i){
            set<string> s;
            for(auto j: sccs[i]){
                s.insert(reverse_mapa[j]);
            }
            string x = *s.begin();
            s.erase(s.begin());
            for(auto i: s){
                x += ", "+ i;
            }
            listas.push_back(x);
        }
        sort(listas.begin(), listas.end());
        cout<<"Calling circles for data set "<<casos<<":\n";
        for(auto i: listas){
            cout<<i<<"\n";
        }
        cout<<"\n";
        ++casos;
    }
    return 0;
}