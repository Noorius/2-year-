#include <bits/stdc++.h>

using namespace std;


int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n, m;
    cin >> n >> m;
    vector < pair < int, pair<int,int> > > g(m);

    int cost = 0;
    vector<pair<int,int> > res;

    for(int i = 0; i < m; ++i){
        int st, en, w;
        cin>> st>> en ;
        g[i] = make_pair(0,make_pair(st,en));
    }
    vector<int> tree_id(n);
    for (int i=0; i<n; ++i)
	    tree_id[i] = i;

    vector<vector<pair<int,int> > > ans(n);
    for(int i = 0; i < m; ++i){
        int a = g[i].second.first,
            b = g[i].second.second;
        
        if(tree_id[a] != tree_id[b]){
            res.push_back(make_pair(a,b));
            ans[b].push_back(make_pair(a,0));
            ans[a].push_back(make_pair(b,0));
            int old_id = tree_id[b],
                new_id = tree_id[a];
            for(int j = 0; j < n; ++j){
                if(tree_id[j] == old_id)
                    tree_id[j] = new_id;
            }
        }
    }

    /*for(int i = 0; i < n; ++i){
        if(ans[i].empty()){
            cout<<"NON-CONNECTED";
            return 0;
        }
    }*/
    for(int i = 0; i < n; ++i){
        cout<<i<<" : ";
        sort(ans[i].begin(),ans[i].end());
        for(int j = 0; j < ans[i].size(); ++j){
            if(j+1==ans[i].size()){
                cout<<ans[i][j].first<<"("<<ans[i][j].second<<")";
            }else
                cout<<ans[i][j].first<<"("<<ans[i][j].second<<"), ";
        }
        cout<<endl;
    }
    return 0;
}