#include <bits/stdc++.h>

#define MAXN 100000

using namespace std;

vector<int> ans;
vector<vector<int> > sol;
bool used[MAXN];
int n, m;
vector<vector<int> > a(MAXN, vector<int>());

void dfs(int v, int p = -1){
    used[v] = true;
    ans.push_back(v+1);
    for(vector<int>::iterator i = a[v].begin(); i!=a[v].end(); ++i){
        if(!used[*i]){
            dfs(*i, v);
        }else if(used[*i] and *i!=p){
            cout<<"NO";
            exit(0);
        }
    }
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>n;
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            int temp;
            cin>>temp;
            if(temp==1)
                a[i].push_back(j);
        }
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
    cout<<"YES";
    return 0;
}