#include <bits/stdc++.h>

#define MAXN 100000

using namespace std;

vector<int> ans;
vector<vector<int> > sol;
bool used[MAXN];
int n, m;
vector<vector<int> > a(MAXN, vector<int>());

int cnt = 0;

void dfs(int v, int p = -1){
    used[v] = true;
    ans.push_back(v+1);
    for(vector<int>::iterator i = a[v].begin(); i!=a[v].end(); ++i){
        if(!used[*i]){
            dfs(*i, v);
        }else if(used[*i] and *i!=p){
            cnt++;
        }
    }
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>n>>m;
    
    for(int i = 0; i<m; i++){
        int t1,t2;
        cin>>t1>>t2;
        a[t1-1].push_back(t2-1);
    }

    for(int i = 0; i<n; i++){
        if(!used[i]){
            dfs(i);
            sol.push_back(ans);
            ans.clear();
        }
    }

    if(sol.size()!=1){
        cout<<"NO";
        return 0;
    }
    if(cnt<2) 
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}