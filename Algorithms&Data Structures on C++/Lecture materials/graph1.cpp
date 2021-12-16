#include <bits/stdc++.h>

using namespace std;

#define MXN 100

bool used[MXN];
int a[MXN][MXN];
int n;

void dfs(int v){
    used[v] = true;
    for(int i=0; i<n; i++){
        if(a[v][i]==1 and !used[i]){
            dfs(i);
        }
    }
}

int main(){
    cin>>n;
    
    for(int i =0; i<n; i++){
        for(int j =0; j<n; j++){
            cin>>a[i][j];
        }
    }
    queue<int> q;
    q.push(0);
    used[0] = true;

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i=0; i<n; i++){
            if(a[cur][i]=1 and !used[i]){
                q.push(i);
                used[i]=true;
                
            }
        }
    }

    return 0;
}