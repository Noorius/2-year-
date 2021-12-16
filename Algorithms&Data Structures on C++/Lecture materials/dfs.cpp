#include <bits/stdc++.h>
#define MAXN 100
using namespace std;

vector<int> ans;
bool used[MAXN];
int n;
int a[MAXN][MAXN];

void dfs(int v){
    used[v] = true;
    for(int i=0; i<n; i++){
        if(a[v][i] == 1 and !used[i]){
            dfs(i);
        }
    }
    ans.push_back(v);
}



int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin>>a[i][j];
        }
    }
    for(int j = 0; j<n; j++){
       if(!used[j]){
           dfs(j);
       }     
    }
    //reverse(ans.begin(),ans.end());
    for(int j = 0; j<n; j++){
       cout<<ans[j]<<" ";  
    }

    return 0;
}