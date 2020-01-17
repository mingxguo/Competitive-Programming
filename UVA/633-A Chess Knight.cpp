#include <vector>
#include <queue>
#include <functional>
#include <utility>
#include <iostream>
#include <climits>
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef pair<int,ii> iii;
typedef vector<iii> viii;

vector<ii> hor =  {{-1,-2},{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2}};
vector<ii> bish = {{-2,-2},{-2,2},{2,2},{2,-2}};
vector<ii> bishhole = {{-1,-1}, {-1,1},{1,1},{1,-1}};

int n;
vector<vi> mat;
vector<vi> dist;
int ox, oy, dx, dy;

ii trasli(ii&a){
    return {2*n - 1 - a.first,a.second};
}

ii traslj(ii &a){
    return {a.first, 2*n-1-a.second};
}

bool inRange(ii p){
    return p.first >= 0 && p.first < 2*n && p.second >= 0 && p.second < 2*n;
}

int bfs(){
    vector<vector<bool>> visited(2*n, vector<bool>(2*n, false));
    queue<iii> q;
    q.push({0,{ox,oy}});
    while(!q.empty()){
        iii aux = q.front(); q.pop();
        int cost = aux.first;
        ii casilla = aux.second;
        if(casilla == ii({dx, dy})) return cost;
        for(int i =0;i<hor.size();++i){
            ii nueva = {casilla.first+hor[i].first, casilla.second+hor[i].second};
            if(inRange(nueva)  && !visited[nueva.first][nueva.second]&& mat[nueva.first][nueva.second] == 0 ){
                visited[nueva.first][nueva.second] = true;
                q.push({cost+1, nueva});
            }
        }
        for(int i =0;i<bish.size();++i){
            ii hole = {casilla.first+bishhole[i].first, casilla.second+bishhole[i].second};
            ii nueva = {casilla.first+bish[i].first, casilla.second+bish[i].second};
            if(inRange(nueva) && inRange(hole) && mat[nueva.first][nueva.second] == 0  && !visited[nueva.first][nueva.second]&& mat[nueva.first][nueva.second] == 0 ){
                visited[nueva.first][nueva.second] = true;
                q.push({cost+1, nueva});
            }
        }
        ii nueva = trasli(casilla);
        if(inRange(nueva)  && !visited[nueva.first][nueva.second]&& mat[nueva.first][nueva.second] == 0 ){
            visited[nueva.first][nueva.second] = true;
            q.push({cost+1, nueva});
        }
        nueva = traslj(casilla);
        if(inRange(nueva)  && !visited[nueva.first][nueva.second]&& mat[nueva.first][nueva.second] == 0 ){
            visited[nueva.first][nueva.second] = true;
            q.push({cost+1, nueva});
        }
    }
    return -1;
}

int main(){
    while(cin >> n, n){
        mat = vector<vi>(2*n, vector<int>(2*n,0)); 
        dist = vector<vi>(2*n, vector<int>(2*n,INT_MAX));
        cin >> ox >> oy >> dx >> dy;
        --ox;--oy;--dx;--dy;
        int i,j;
        while(cin >> i >> j, i+j){
            --i;--j;
            mat[i][j] = 1;
        }
        int x = bfs();
        if(x == -1) cout << "Solution doesn't exist\n";
        else cout << "Result : " << x << "\n";
    }
    return 0;
}