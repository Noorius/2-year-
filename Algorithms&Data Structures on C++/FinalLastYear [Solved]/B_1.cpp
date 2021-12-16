#include <bits/stdc++.h>

using namespace std;

#define NMAX 10000+1

vector<bool> used(NMAX, false);
int n, m;
//vector<vector<int> > a(MAXN, vector<int>());
vector<int> d(NMAX), p(NMAX);

void bfs(int s){
    queue<int> q;
    q.push (s);
    used[s] = true;
    p[s] = -1;
    d[s] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        int num1 = v * 2,
            num2 = v -1;

        if (!used[num1] and num1<NMAX) {
            //p.push_back(i);
            used[num1] = true;
            p[num1] = v;
            d[num1] = d[v] + 1;
            
            if(num1==m)
                return;
            q.push(num1);
        }
        if (!used[num2] and num2 > 0 and num2<NMAX) {
            //p.push_back(i);
            used[num2] = true;
            p[num2] = v;
            d[num2] = d[v] + 1;
            
            if(num2==m)
                return;
            q.push(num2);
        }
    }
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    cin >> n >> m;
    
    bfs(n);

    if (!used[m]){
        cout << 0;
    }else{
        vector<int> path;
        for (int v=m; v!=-1; v=p[v])
            path.push_back (v);
        reverse (path.begin(), path.end());
        
        if(path.size()-1!=0){
            cout << path.size()-1<<endl;
            for (size_t i=1; i<path.size(); ++i)
                cout << path[i] << " "; 
        }else{
            cout<<path.size()-1;
        }
    }
    /*for(int i = 0; i < n; ++i){
        for(int j = 0; j < 10; ++j){
            cout << t[i].next[j] << " ";
        }
        cout<<endl;
    }*/


    return 0;
}