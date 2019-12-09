#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

int n,m,k,v;
int main(){
    while(cin >> n >> m){
        unordered_map<int, vector<int>> mapa;
        int num;
        for (int i = 0; i < n; ++i){
            cin >> num;
            mapa[num].push_back(i+1);
        }
        while (m--){
            cin >> k >> v;
            if (mapa[v].empty() || mapa[v].size() < k) cout << "0\n";
            else cout << mapa[v][k-1] << '\n';
        }


    }
    return 0;
}