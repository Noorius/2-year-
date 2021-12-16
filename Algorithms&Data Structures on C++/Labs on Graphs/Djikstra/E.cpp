#include <bits/stdc++.h>

using namespace std;


int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n;
    cin >> n;

    int st, en;
    cin>>st>>en;
    st--; en--;

    int d[n];
    pair<int,int> p[n];
    vector<vector<pair<int,pair<int,int> > > > g(n);//, vector<pair<int,int> >(n, make_pair(0,0)));
    int inf = 2009000999;

    int m;
    cin>>m;
    for(int i = 0; i < m; ++i){
        int st1, b, en1, f;
        cin >> st1>> b >> en1 >> f;
        st1--; en1--;
        g[st1].push_back(make_pair(en1,make_pair(b,f)));
    }
    /*
    for(int i = 0; i < n; ++i){
        cout<<i<<" : ";
        for(int j = 0; j < g[i].size(); ++j){
            cout<<g[i][j].first<<" "<<g[i][j].second.first<<" "<<g[i][j].second.second<<" | ";
        }
        cout<<endl;
    } */

    for(int i = 0; i < n; ++i){
        d[i] = inf;
    }

    d[st] = 0;
    p[st] = {0,0};

    set<pair<int,int> >q;
    q.insert(make_pair(st,0));

    while(!q.empty()){
        int v = q.begin()->first;
        int st_w = q.begin()->second;
        q.erase(q.begin());

        for(int i = 0; i < g[v].size(); ++i){
            int to = g[v][i].first;
            int st_t = g[v][i].second.first;
            int en_t = g[v][i].second.second;
            if(d[v] + (st_t-st_w)+(en_t-st_t) < d[to] and st_t >= st_w){
                q.erase(make_pair(to, g[p[to].first][p[to].second].second.second));
                d[to] = d[v] + (st_t-st_w)+(en_t-st_t);
                p[to] = {v,i};
                q.insert(make_pair(to, en_t));
            }

        }
        if(v==en and d[v]!=inf){
            cout<<d[v]<<endl;
            return 0;
        }
    }

    /*for(int i = 0; i < n; ++i){
        cout << d[i] << " ";
    }*/
    cout<<-1;
    cout<<endl;

    return 0;
}

/*
0 0 | 10 220 | 1 99 | 
10 220 | 0 0 | 20 201 | 
1 99 | 20 201 | 0 0 | 
*/