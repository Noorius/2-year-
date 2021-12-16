#include <bits/stdc++.h>

#define MAXN 100000

using namespace std;

int n, m;

void dfs(int v, vector<vector<int> > &a, vector<int> &ans, vector<bool> &used, int nt){
    used[v] = true;
    for(vector<int>::iterator i = a[v].begin(); i!=a[v].end(); ++i){
        if(!used[*i] and *i!=nt){
            dfs(*i,a,ans,used,nt);
        }
    }
    ans.push_back(v+1);
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin>>n>>m;
    
    vector<pair<int,int> > reb;

    for(int i = 0; i<m; i++){
        int i1, j1;
        cin>>i1>>j1;
        reb.push_back(make_pair(i1-1,j1-1));
    }

    for(int i = 0; i<n; i++){
        vector<vector<int> > a(n, vector<int>());
        vector<int> ans;
        vector<vector<int> > sol;
        vector<bool> used(n,false);

        for(auto c : reb){
            if(c.first < i or c.second < i or (c.first < i and c.second < i)){
                continue;
            }
            else{
                a[c.first].push_back(c.second);
                a[c.second].push_back(c.first);
            }
        }
        for(int k = 0; k<n; k++){
            if(!used[k] and k>i){
                dfs(k,a,ans,used,i);
                sol.push_back(ans);
                /*for(auto c : ans)
                    cout<<c<<" ";
                cout<<endl;*/
                ans.clear();
            }
        }
        cout<<sol.size()<<endl;
    }


    
    
    /*for(auto vec : sol){
        cout<<vec.size()<<endl;
        for(int num : vec){
            cout<<num<<" ";
        }
        cout<<endl;
    }*/
    
    return 0;
}