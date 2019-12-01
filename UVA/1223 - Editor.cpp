#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

#define MAX_N 100010 // O(n log n) -> up to 100 K

char T[MAX_N], P[MAX_N];
int n, m; // input string and length
int RA[MAX_N], tempRA[MAX_N], SA[MAX_N], tempSA[MAX_N], c[MAX_N];

void countingSort(int k) { // O(n)
    int i, sum, maxi = max(300, n); // up to 255 ASCII chars or length of n
    memset(c, 0, sizeof c);
    for (i = 0; i < n; i++)
        c[i + k < n ? RA[i + k] : 0]++;
    for (i = sum = 0; i < maxi; i++) {
        int t = c[i]; c[i] = sum; sum += t;
    }
    for (i = 0; i < n; i++)
        tempSA[c[SA[i] + k < n ? RA[SA[i] + k] : 0]++] = SA[i];
    for (i = 0; i < n; i++)
        SA[i] = tempSA[i];
}
// Builds Suffix Array for string T. T should end with sth like $
void constructSA() { // O(n log n), can go up to 100000 characters
    int i, k, r;
    for (i = 0; i < n; i++) RA[i] = T[i];
    for (i = 0; i < n; i++) SA[i] = i;
    for (k = 1; k < n; k <<= 1) {
        countingSort(k);
        countingSort(0);
        tempRA[SA[0]] = r = 0;
        for (i = 1; i < n; i++)
            tempRA[SA[i]] =
            (RA[SA[i]] == RA[SA[i - 1]] && RA[SA[i] + k] == RA[SA[i - 1] + k]) ? r : ++r;
        for (i = 0; i < n; i++)
            RA[i] = tempRA[i];
        if (RA[SA[n - 1]] == n - 1) break; // optimization
    }
}

int Phi[MAX_N], PLCP[MAX_N], LCP[MAX_N];
void computeLCP() { // O(n)
    int i, L;
    Phi[SA[0]] = -1;
    for (i = 1; i < n; i++)
        Phi[SA[i]] = SA[i - 1];
    for (i = L = 0; i < n; i++) {
        if (Phi[i] == -1) { PLCP[i] = 0; continue; }
        while (T[i + L] == T[Phi[i] + L]) L++;
        PLCP[i] = L;
        L = max(L - 1, 0);
    }
    for (i = 0; i < n; i++)
        LCP[i] = PLCP[SA[i]];
}


int main(){
  int t;
  cin >> t;
  while(t--){
    string p;
    cin >> p;
    strcpy(T, p.c_str());
    n = p.size() + 1;
    T[n-1] = '0';
    constructSA();
    computeLCP();
    int sol = 0;
    for(int i=1;i<n;++i){
      if(LCP[i] > sol) sol = LCP[i];
    }
    cout << sol << '\n';
  }
  return 0;
}
