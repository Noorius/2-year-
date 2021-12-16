#include <bits/stdc++.h>

#define MAXN 100

using namespace std;

//vector<vector<int> > sol;
bool used[MAXN];
int n, st, en;
vector<vector<int> > a(MAXN, vector<int>());
vector<int> d(MAXN), p(MAXN);

void bfs(int s){
    queue<int> q;
    q.push (s);
    used[s] = true;
    p[s] = -1;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i=0; i<n; i++) {
            int to = a[v][i];
            if (!used[i] and to==1) {
                //p.push_back(i);
                used[i] = true;
                p[i] = v;
                d[i] = d[v] + 1;
                q.push(i);
                if(i==en-1)
                    return;
            }
        }
    }
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>n;

    for(int i = 0; i<n; i++){
        used[i] = false;
        for(int j = 0; j<n; j++){
            int temp;
            cin>>temp;
            a[i][j] = temp;
        }
    }

    cin>>st>>en;
    /*for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    } */
    
    bfs(st-1);
    /*for(int i=0; i<n; i++)
        cout<<used[i]<<" "; */
    if (!used[en-1]){
        cout << -1;
        return 0;
    }else{
        vector<int> path;
        for (int v=en-1; v!=-1; v=p[v])
            path.push_back (v);
        reverse (path.begin(), path.end());
        cout << path.size()-1<<endl;
        if(path.size()-1!=0){
            for (size_t i=0; i<path.size(); ++i)
                cout << path[i] + 1 << " "; 
        }
        
    }
    


    return 0;
}