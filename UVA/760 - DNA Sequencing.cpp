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

int owner(int idx) { return (idx < n - m - 1) ? 1 : 2;}

vector<ii> LCS() { // O(n), returns (l: the LCS length, i: its index in the SA), i.e.,
    // solution = T[SA[i]] T[SA[i] + 1] ... T[SA[i] + l - 1]
    vector<ii> sol;
    int i, idx = 0, maxLCP = -1;
    for (i = 1; i < n; i++){
      if (owner(SA[i]) != owner(SA[i - 1])){
            if(LCP[i] < maxLCP) continue;
            if(LCP[i] > maxLCP){
                sol.clear();
            }
            maxLCP = LCP[i];
            idx = i;
            sol.push_back(ii(maxLCP, idx));
        }            
    }
    return sol;
}

int main(){
    string p, t;
    bool first = true;
    while(cin >> t >> p){
        string aux = t + "0" + p + "1";
	if(!first) cout << "\n";
	//cout << p << " " << t << " " << aux << '\n';
        strcpy(P, p.c_str());
        strcpy(T, aux.c_str());
        n = aux.size();
        m = p.size();
        constructSA();
        computeLCP();
        vector<ii> lcs = LCS();
        set<string> sol;
        for(int i=0; i<lcs.size();++i){
            int maxLCP = lcs[i].first;
            int idx = lcs[i].second;
            string a;
            for(int j=0;j<maxLCP;++j){
	      a+=T[SA[idx]+j];
	    }
	    if(a!= "") sol.insert(a);
        }
	if(sol.empty())
	  cout << "No common sequence.\n";
	else{
	  for(string s : sol){
	    cout << s << '\n';
	  }
	}
	first = false;
    }
    return 0;
}
