#include <bits/stdc++.h>

using namespace std;


int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int num;
    cin >> num;
    for(int i = 0; i < num; i++){
        int n, m;
        cin>>n>>m;
        int d[n];
        vector<vector<pair<int,int> > > g(n);//, vector<pair<int,int> >(n, make_pair(0,0)));
        int inf = 2009000999;

        for(int i = 0; i < m; ++i){
            int st, en, w;
            cin >> st>> en>> w;
            g[st].push_back({w, en});
            g[en].push_back({w, st});
        }
        /*
        for(int i = 0; i < n; ++i){
            cout<<i<<" : ";
            for(int j = 0; j < g[i].size(); ++j){
                cout<<g[i][j].first<<" "<<g[i][j].second<<", ";
            }
            cout<<endl;
        } */

        int s;
        cin >> s;

        
        for(int i = 0; i < n; ++i){
            d[i] = inf;
        }

        d[s] = 0;

        set<pair<int,int> >q;
        q.insert(make_pair(d[s],s));

        while(!q.empty()){
            int v = q.begin()->second;
            q.erase(q.begin());

            for(int i = 0; i < g[v].size(); ++i){
                int to = g[v][i].second;
                int len = g[v][i].first;
                if(d[v] + len < d[to]){
                    q.erase(make_pair(d[to],to));
                    d[to] = d[v] + len;
                    q.insert(make_pair(d[to],to));
                }
            }
        }

        for(int i = 0; i < n; ++i){
            cout << d[i] << " ";
        }
        cout<<endl;
    }

    return 0;
}

/*
0 0 | 10 220 | 1 99 | 
10 220 | 0 0 | 20 201 | 
1 99 | 20 201 | 0 0 | 
*/