#include <bits/stdc++.h>

using namespace std;

int cnt = 0;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int> > > a(n);
    int inf = 1000000000;
    vector<int> min_e(n,inf);
    vector<int> path(n,-1);

    for(int i = 0; i < m; ++i){
        int st, en;
        cin>> st>> en;
        a[st-1].push_back(make_pair(1,en));
        a[en-1].push_back(make_pair(1,st));
    }

    vector<bool> used(n);

    min_e[0] = 0;
    for(int i = 0; i < n; ++i){
        int v = -1;
        for(int j = 0; j < n; ++j){
            if(!used[j] and (v == -1 or min_e[j] < min_e[v]))
                v = j;
        }
        if(min_e[v] == inf){
            break;
        }
        used[v] = true;
        if(path[v] != -1){
            cout<<path[v]+1<<" "<<v+1<<endl;
            //cnt += min_e[v];
        }
        for(auto c : a[v]){
            int to = c.second;
            int w = c.first;
            if(w < min_e[to]){
                min_e[to] = w;
                path[to] = v;
            }
        }
    }
    //cout<<cnt;
    return 0;
}