#include <bits/stdc++.h>

#define MAXN 100

using namespace std;

//vector<vector<int> > sol;
bool used[MAXN][MAXN];
int dist[MAXN][MAXN];
int n, m, am = 0;
//vector<vector<int> > a(MAXN, vector<int>());
int a[MAXN][MAXN];
queue<pair<int,int> > q;
int coor_x[4] = {-1,1,0,0}, coor_y[4] = {0,0,-1,1};

void bfs(){
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if(dist[x][y] > am)
            am = dist[x][y];

        for (int i=0; i<4; i++) {
            int to_x = x + coor_x[i];
            int to_y = y + coor_y[i];
            if (!used[to_x][to_y] and a[to_x][to_y]==1) {
                used[to_x][to_y] = true;
                a[to_x][to_y]=2;
                q.push(make_pair(to_x,to_y));
                dist[to_x][to_y] = dist[x][y] + 1;
            }
        }
    }
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>n>>m;
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            int t;
            cin>>t;
            if(t == 2){
                q.push(make_pair(i,j));
                used[i][j] = true;
                dist[i][j] = 0;
            }
            a[i][j] = t;
        }
    }

    bfs();

    /*
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }*/
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(a[i][j] == 1){
                cout<<-1;
                return 0;
            }
        }
    }
    cout<<am<<endl;

    return 0;
}