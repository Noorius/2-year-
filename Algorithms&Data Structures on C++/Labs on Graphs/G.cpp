#include <bits/stdc++.h>

#define MAXN 1000

using namespace std;

bool used[MAXN][MAXN];
int n, m, am;
int a[MAXN][MAXN];

void dfs(int i, int j){

    if(a[i-1][j]==1 and !used[i-1][j]){
        used[i-1][j] = true;
        a[i-1][j] = 0;
        dfs(i-1,j);
    }
    if(a[i+1][j]==1 and !used[i+1][j]){
        used[i+1][j] = true;
        a[i+1][j] == 0;
        dfs(i+1,j);
    }
    if(a[i][j-1]==1 and !used[i][j-1]){
        used[i][j-1] = true;
        a[i][j-1]==0;
        dfs(i,j-1);
    }
    if(a[i][j+1]==1 and !used[i][j+1]){
        used[i][j+1] = true;
        a[i][j+1]==0;
        dfs(i,j+1);
    } 
}

void find_comps(){
    am = 0;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            if(a[i][j]==1 and !used[i][j]){
                used[i][j] = true;
                dfs(i,j);
                am++;
            }
        }
    }
    
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>n>>m;
    
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            char temp;
            cin>>temp;
            if(temp == '#')
                a[i][j] = 1;
            else
                a[i][j] = 0;
        }
    }
    find_comps();
    cout<<am;

    return 0;
}