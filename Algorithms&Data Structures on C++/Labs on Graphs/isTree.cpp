#include <bits/stdc++.h>

using namespace std;


int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin >> n ;
    int inf = 1000000000;
    vector<vector<pair<int,int> > > g(n);
    vector<int> sel_e(n,-1), min_e(n,inf);

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
             int num;
             cin>>num;
             if(num==1){
                 g[i].push_back(make_pair(j,0));
             }
        }
    }

    vector<bool> used(n,false);

    for (int i=0; i<n; ++i) {
        int v = -1;
        for (int j=0; j<n; ++j)
            if (!used[j] and (v == -1 || min_e[j] < min_e[v]))
                v = j;

        used[v] = true;
        /*if (sel_e[v] != -1)
            cout << v << " " << sel_e[v] << endl;*/
    
        for (auto c : g[v]){
            int to = c.first,
                w = c.second;
                
            if (w < min_e[to]) {
                min_e[to] = w;
                sel_e[to] = v;
            }
            if(to!=sel_e[v] and used[to]){
                cout<<"NO";
                return 0;
            }
        }
            
    }
    for(int i = 0; i < n; ++i)
        cout<<min_e[i]<<" ";
    cout<<endl;
    for(int i = 0; i < n; ++i)
        cout<<sel_e[i]<<" ";

    for(int i = 0; i < n; ++i){
        if(min_e[i]==inf and sel_e[i]==-1){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}