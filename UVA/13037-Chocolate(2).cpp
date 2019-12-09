#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int n;

int main(){
    cin >> n;
    for(int hola = 1; hola<=n; ++hola){
        vector<int> p(3);
        for(auto &i:p){
            cin >> i;
        }
        int num;
        vector<set<int>> v(3);
        for(int i = 0; i < 3; ++i){
            for(int j = 0; j < p[i]; ++j){
                cin >> num;
                v[i].insert(num);
            }
        }
        cout << "Case #" << hola << ":\n";
        vector<set<int>> col1(3), col2(3);
    
        for (int i = 0; i < 3; i++){
            set<int> aux;
            //cout <<":("<<endl;
            auto it = set_union(v[(i+1)%3].begin(),v[(i+1)%3].end(), v[(i+2)%3].begin(), v[(i+2)%3].end(), inserter(aux, aux.begin()));
            //for(auto h: aux) cout << h << ' ';
            //cout << endl;
            //cout<<"h"<<endl;
            //aux.resize(it-aux.begin());
            //cout << "o"<<endl;
            auto it_ = set_difference(v[i].begin(), v[i].end(), aux.begin(), aux.end(), inserter(col1[i], col1[i].begin()));
            //for(auto h: col1[i]) cout << h << ' ';
            //cout << endl;
            //cout << "l"<<endl;
            //col1[i].resize(it_-col1[i].begin());
            //cout << "a"<<endl;
        }
        for (int i = 0; i < 3; i++){
           set<int> aux;
            auto it = set_intersection(v[(i+1)%3].begin(),v[(i+1)%3].end(), v[(i+2)%3].begin(), v[(i+2)%3].end(),inserter(aux, aux.begin()));
            //aux.resize(it-aux.begin());
            auto it_ = set_difference(aux.begin(), aux.end(), v[i].begin(), v[i].end(), inserter(col2[i], col2[i].begin()));
            //col2[i].resize(it_-col2[i].begin());
        }

        for (int i = 0; i < 3; i++){
            cout << col1[i].size() << ' ' << col2[i].size() <<'\n';
        }
    }
    return 0;
}