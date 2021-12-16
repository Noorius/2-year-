#include <bits/stdc++.h>

#define MAXN 100000

using namespace std;

vector<int> ans;
vector<vector<int> > sol;
bool used[MAXN];
int n, m;
vector<vector<int> > a(MAXN, vector<int>());

void dfs(int v){
    used[v] = true;
    ans.push_back(v+1);
    for(vector<int>::iterator i = a[v].begin(); i!=a[v].end(); ++i){
        if(!used[*i]){
            dfs(*i);
        }
    }
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>n>>m;
    
    for(int i = 0; i<m; i++){
        int i1, j1;
        cin>>i1>>j1;
        a[i1-1].push_back(j1-1);
        a[j1-1].push_back(i1-1);
    }
    cout<<(n-1) - m;
    return 0;
    for(int i = 0; i<n; i++){
        if(!used[i]){
            dfs(i);
            sol.push_back(ans);
            ans.clear();
        }
    }
    cout<<sol.size()<<endl;
    for(auto vec : sol){
        cout<<vec.size()<<endl;
        for(int num : vec){
            cout<<num<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}