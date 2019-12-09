#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

string s;
vector<int> v;
bool calculate(int iz, int dr){
    int c = 0;
    int ini = iz + 1;
    int k = v[ini];
    if(iz > dr) return true;
    for(int i=iz+2; i<dr; ++i){
        if(k > 0) return false;
        if(v[i]==-k){
            bool b = calculate(ini,i);
            if(!b) return false;
            c+=v[i];
            ini = i+1;
            if(i+1<dr) k = v[ini];
        }
    }
    if(ini == dr) return c < v[dr];
    return false;
    
}

int main(){
    while(getline(cin, s)){
        v.clear();
        stringstream ss(s);
        int num;
        while(ss>>num) v.push_back(num);
        if(v.empty()) cout<<":-) Matrioshka!\n";
        else if(v[0] < 0 && v[0]+v.back()== 0 && calculate(0, v.size()-1)){
            cout<< ":-) Matrioshka!\n";
        }
        else{
            cout<<":-( Try again.\n";
        }
    }
    return 0;
}