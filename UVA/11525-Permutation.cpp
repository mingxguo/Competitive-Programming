#include <vector>
#include <string>
#include <iostream>

using namespace std;
typedef vector<int> vi;
#define LSOne(S) (S & (-S))

struct FenwickTree {
    vi ft;
  FenwickTree(int n) {ft.assign(n + 1, 0);}
  
    int rsq(int b) {
        int t = 0;
        for (; b; b -= LSOne(b))
            t += ft[b];
        return t;
    }
    int rsq(int a, int b){return rsq(b) - rsq(a - 1);}
  
    void update(int k, int v) {
        for (; k < ft.size(); k += LSOne(k))
            ft[k] += v;
    }
    void updateRange(int a, int b, int val){
        update(a, val);
        update(b+1, -val);
    }
};

int bb(FenwickTree & ft, int k, int v){
  int ini = 1, fin = k;
  int m;
  while(ini <= fin){
    m = (ini+fin)/2;
    if(ft.rsq(m) < v){
      ini = m+1;
    }
    else if(ft.rsq(m) == v){
      if(ft.rsq(m, m) == 0){
	fin = m - 1;
      }
      else{
	ini = m;
	break;
      }
    }
    else fin = m-1;
  }
  ft.update(m, -1);
  return ini;
}

int main(){

  int casos;
  cin >> casos;
  while(casos--){
    int k;
    cin >> k;
    vector<int> sequence(k);
    for(int i = 0; i < k; ++i){
      cin >> sequence[i];
    }

    FenwickTree ft(k);
    
    for(int i = 0; i < k; ++i){
      ft.update(i+1, 1);
    }
    for(int i = 0; i < k; ++i){
      int pos = bb(ft, k, sequence[i]+1);
      cout << pos;
      if (i == k-1) cout << '\n';
      else cout << ' ';
    }
  }
}
