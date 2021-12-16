#include <bits/stdc++.h>

#define MAXN 100000

using namespace std;

vector<int> ans;
vector<vector<int> > sol;
bool used[MAXN];
int n, m;
vector<vector<int> > a(MAXN);

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
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int t;
            cin>>t;
            a[i].push_back(t);
        }
    }
    /*for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;*/

    for(int i = 0; i < m; i++){
        int c1, c2, c3;
        cin>>c1>>c2>>c3;
        c1--; c2--; c3--;
        if(a[c1][c2]==1 and a[c1][c3]==1 and a[c2][c1]==1 and a[c2][c3]==1 and a[c3][c1]==1 and a[c3][c2]==1)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }

    return 0;
    /*for(int i = 0; i<n; i++){
        if(!used[i]){
            dfs(i);
            sol.push_back(ans);
            ans.clear();
        }
    }
    
    for(auto vec : sol){
        cout<<vec.size()<<endl;
        for(int num : vec){
            cout<<num<<" ";
        }
        cout<<endl;
    }
    
    return 0;*/
}