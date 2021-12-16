#include <bits/stdc++.h>

using namespace std;


int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);


    int n, m;
    cin>>n>>m;
    int n2 = n * 2;
    int d[n2];
    bool used[n2];
    vector<vector<int> > g(n2, vector<int>(n2, 0));
    int inf = 2009000999;

    for(int i = 0; i < m; ++i){
        int st, en;
        cin >> st>> en;
        st--; en--;
        g[st][en] = 1;
        g[n+en][n+st] = 1;
        g[st][st+n] = 1;
        g[en][en+n] = 1;
        g[st+n][st] = 1;
        g[en+n][en] = 1;
    }
    /*
    for(int i = 0; i < n2; ++i){
        cout<<i<<" : ";
        for(int j = 0; j < g[i].size(); ++j){
            cout<<g[i][j]<<" ";
        }
        cout<<endl;
    } 
    return 0;*/

    
    for(int i = 0; i < n2; ++i){
        d[i] = inf;
    }

    d[0] = 0;
    queue<int>q;
    q.push(0);
    used[0] = true;

    while(!q.empty()){
        int v = q.front();
        q.pop();

        for(int i = 0; i < n2; ++i){
            if(!used[i] and g[v][i]==1){
                used[i] = true;
                q.push(i);
                d[i] = d[v] + 1;
            }
        }
        if(v==n-1){
            cout<<d[v]<<endl;
            return 0;
        }
    }

    for(int i = 0; i < n2; ++i){
        cout << d[i] << " ";
    }
    cout<<endl;

    return 0;
}

/*
0 0 | 10 220 | 1 99 | 
10 220 | 0 0 | 20 201 | 
1 99 | 20 201 | 0 0 | 
*/