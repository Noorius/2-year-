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
        cin>> st>> en >> w;
        g[i] = make_pair(w,make_pair(st-1,en-1));
    }

    sort(g.begin(),g.end());
    vector<int> tree_id(n);
    for (int i=0; i<n; ++i)
	    tree_id[i] = i;


    for(int i = 0; i < m; ++i){
        int a = g[i].second.first,
            b = g[i].second.second,
            l = g[i].first;
        if(tree_id[a] != tree_id[b]){
            cost += l;
            res.push_back(make_pair(a,b));
            int old_id = tree_id[b],
                new_id = tree_id[a];
            for(int j = 0; j < n; ++j){
                if(tree_id[j] == old_id)
                    tree_id[j] = new_id;
            }
        }
    }
    cout<<cost;
    return 0;
}