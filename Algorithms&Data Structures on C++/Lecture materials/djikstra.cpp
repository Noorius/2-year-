#include <bits/stdc++.h>
#define MAXN 100
using namespace std;



int main(){
    int n;
    cin>>n;
    
    bool used[n];
    int d[n];
    int a[n][n];
    int inf = INT_MAX /2;

    for(int i=0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin>>a[i][j];
            if(a[i][j]==0)
                a[i][j] = inf;
        }
    }

    int s;
    cin>>s;
    s--;

    for(int i=0; i<n; i++){
        d[i] = inf;
    }
    d[s] = 0;
    for(int i=0; i<n; i++){
        int v = -1;
        for(int j = 0; j<n; j++){
            if(!used[j]){
                if(v == -1 or d[v]>d[j]){
                    v = j;
                }
            }
        }
        if(d[v] == inf) break;
        used[v] = true;
        for(int j = 0; j<n; j++){
            d[j] = min(d[v],d[v]+a[v][j]);
        }
        for(int j = 0; j<n; j++){
            cout<<d[j]<<" ";
        }
    }

    return 0;
}