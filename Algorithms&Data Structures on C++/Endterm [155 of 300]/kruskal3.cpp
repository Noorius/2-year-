#include <bits/stdc++.h>

using namespace std;

vector<int> p(100000);

int dsu_get(int v){
    return (v == p[v]) ? v : (p[v] = dsu_get (p[v]));
}

void dsu_unite(int a, int b){
    a = dsu_get (a);
	b = dsu_get (b);
	if (rand() & 1)
		swap (a, b);
	if (a != b)
		p[a] = b;
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n, m;
    cin >> n >> m;
    vector < pair < long, pair<int,int> > > g(m);

    for(int i = 0; i < m; ++i){
        int st, en;
        long w;
        cin>> st>> en >> w;
        g[i] = make_pair(w,make_pair(st,en));
    }

    long long cost = 0;
    vector<pair<int,int> > res;
    sort(g.begin(),g.end());
    p.resize(n);
    for (int i=0; i<n; ++i)
	    p[i] = i;

    vector<vector<pair<int,long> > > ans(n);
    for(int i = 0; i < m; ++i){
        int a = g[i].second.first,
            b = g[i].second.second;
        long l = g[i].first;
        
        if(dsu_get(a)!=dsu_get(b)){
            cost+=l;
            res.push_back(g[i].second);
            ans[b].push_back(make_pair(a,l));
            ans[a].push_back(make_pair(b,l));
            dsu_unite(a,b);
        }
    }

    for(int i = 0; i < n; ++i){
        if(ans[i].empty()){
            cout<<"NO";
            return 0;
        }
    }
    cout<<cost<<endl;
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