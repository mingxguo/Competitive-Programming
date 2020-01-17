#include <iostream>

using namespace std;

int main(){
    int n, k;
    long long sol;
    while(cin >> n >> k, n+k)
    {    
        if(k > n/2) k = n -k;
        sol = 1;
        int i = 0;
        for(int i=1; i <= k; ++i){
            sol *=(n-k+i);
            sol/= i;
        }
        cout << sol << '\n';
    }
    return 0;
}