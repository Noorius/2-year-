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
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>n>>m;
    
    vector<pair<int,int> > reb;

    for(int i = 0; i<m; i++){
        int i1, j1;
        cin>>i1>>j1;
        reb.push_back(make_pair(i1-1,j1-1));
    }

    for(int i = 0; i<n; i++){
        vector < pair < int, pair<int,int> > > g(m);

        for(auto c : reb){
            if(c.first < i or c.second < i or (c.first < i and c.second < i)){
                continue;
            }
            else{
                g.push_back(make_pair(0,make_pair(c.first,c.second)));
            }
        }
        vector<int> tree_id(n);
        for (int k=i+1; k<n; ++k)
            tree_id[i] = i;

        vector<vector<pair<int,int> > > ans(n);
        for(int k = i+1; k < m; ++k){
            int a = g[k].second.first,
                b = g[k].second.second;
            
            if(tree_id[a] != tree_id[b]){
                int old_id = tree_id[b],
                    new_id = tree_id[a];
                for(int j = 0; j < n; ++j){
                    if(tree_id[j] == old_id)
                        tree_id[j] = new_id;
                }
            }
        }
        cout<<tree_id[i]<<endl;
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