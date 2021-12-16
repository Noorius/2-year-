#include <bits/stdc++.h>
using namespace std;

int n;
pair<int,int> p[500][500];
vector<pair<int,int> > res;

void show(int x, int y){
    if(x==-1 and y==-1)
        return;
    //cout<<x<<" "<<y<<" - "<<p[x][y].first<<" "<<p[x][y].second<<endl;
    res.push_back(make_pair(x,y));
    show(p[x][y].first, p[x][y].second);
    cout<<x<<" "<<y<<endl;
}


int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int x1,y1,x2,y2;

    //int x[8]={-2,-2,-1,-1,1,1,2,2}, y[8]={-1,1,-2,2,-2,2,-1,1};
    int x[8]={-1,1,-1,1,2,2,-2,-2}, y[8]={-2,-2,2,2,-1,1,1,-1};
    cin>>n;
    deque<pair<int,int> > q;
    //deque<pair<pair<int,int>,pair<int,int> > > r;
    //vector<vector<pair<int,int> > > p(n, vector<pair<int,int> >());
    
    
    int d[500][500];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            d[i][j] = 1000000000;
            p[i][j] = make_pair(-1,-1);
        }
    }
    cin>>x1>>y1>>x2>>y2;
            
    d[x1][y1] = 0; 
    q.push_back(make_pair(x1,y1));
    //r.push_back(make_pair(make_pair(-1,-1),make_pair(x1,y1)));

    while(!q.empty()){
        int i=q.front().first;
        int j=q.front().second;
        q.pop_front();
        for(int k = 0; k < 8; ++k){
            int u=i+x[k];
            int v=j+y[k];
            if(u>0 && u<=n && v>0 && v<=n && d[u][v] > d[i][j]+1){
                d[u][v] = d[i][j] + 1;
                p[u][v] = make_pair(i,j);
                q.push_back(make_pair(u,v));;
            }
        }
    }
    
    cout<<d[x2][y2]<<endl;
    /*
    for(i = 0; i <= n; i++){
        for(j = 0; j <= n; j++){
            cout<<d[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;

    for(i = 0; i <= n; i++){
        for(j = 0; j <= n; j++){
            cout<<p[i][j].first<<" "<<p[i][j].second<<" |";
        }
        cout<<endl;
    }
    cout<<endl; */
    show(x2, y2);
    /*reverse(res.begin(),res.end());
    for(auto c : res)
        cout<<c.first<<" "<<c.second<<endl;*/
    return 0;
}