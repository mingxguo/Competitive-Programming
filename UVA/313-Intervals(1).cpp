#include <bits/stdc++.h>

using namespace std;

typedef vector<pair<long long int,long long int>> vii;
typedef vector<long long int> vi;
typedef pair<long long int,long long int> ii;
typedef pair<long long int,ii> iii;
typedef vector<iii> viii;
typedef pair<double,double> dd;

struct circulo{
    long long int x1, y1, r;
};

pair<double,double> corte(long long int x0,  long long int y0, long long int x1,long long int y1, long long int r){
    double sol = 0;
    long long int a = r*r - x0*x0 - x1*x1 +2*x0*x1;
    long long int b = -2*x1*(y0-y1) + 2*x0*(y0-y1);
    long long int c = r*r - (y0-y1)*(y0-y1);
    if(a == 0){
        double p0 = x0;
        double m1 = -c/(double)b;
        double p1 = x0-y0/m1;
        return {min(p0,p1), max(p0,p1)};
    }
    else{
        double s = sqrt(b*b-4*a*c);
        double m0 = (-b+s)/(2.0*a);
        double m1 = (-b-s)/(2.0*a);
        double p0 = x0-y0/m0;
        double p1 = x0-y0/m1;
        return {min(p0,p1), max(p0,p1)};
    }
}

int main(){
    long long int N;
    while(cin >> N, N){
        long long int x0, y0;
        cin >> x0 >> y0;
        vector<circulo> circulos(N);
        for(long long int i=0;i<N;++i){
            cin >> circulos[i].x1 >> circulos[i].y1 >> circulos[i].r;
        }

        vector<pair<double,double>> puntos(N);

        for(long long int i=0;i<N;++i){
            puntos[i] = corte(x0, y0, circulos[i].x1, circulos[i].y1, circulos[i].r);
        }

        sort(puntos.begin(), puntos.end());
        vector<pair<double,double>> resul;
        double init = puntos[0].first;
        double maxicola = puntos[0].second;
        int i = 0;
        while(i < N){

            while(i < N && maxicola >= puntos[i].first){
                maxicola = max(maxicola, puntos[i].second);
                ++i;
            }
            resul.push_back({init, maxicola});
            if(i < N){
                maxicola = puntos[i].second;
                init = puntos[i].first;
            }
        }
        for(auto p: resul){
            cout << fixed << setprecision(2) << p.first << " " << fixed << setprecision(2) << p.second<< "\n";
        }
        cout << '\n';
    }

return 0;
}