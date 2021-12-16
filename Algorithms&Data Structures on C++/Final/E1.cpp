#include <bits/stdc++.h>

#define MAXN 100000

using namespace std;

vector<int> ans;
vector<vector<int> > sol;
bool used[MAXN];
int n, m;
vector<vector<int> > a(MAXN, vector<int>());

void dfs(int v){
    used[v] = true;
    /*for(int i = 0; i<n; i++){
        if(!used[i] and a[v][i]==1){
            
        }
    }*/
    for(int c : a[v]){ //c kuda 
        if(used[c]){
            cout<<-1;
            exit(0);
        }/**/
        else{
           dfs(c); 
        }   
    }
    ans.push_back(v+1);
    if(ans.size()==3) return;
}

int main(){
    /*freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);*/
    cin>>n>>m;
    
    for(int i = 0; i<n; i++){
        used[i] = false;
        for(int j = 0; j<n; j++){
            if(i!=j)
                a[i].push_back(j);
        }
    }

    
    for(int i = 0; i<m; i++){
        int i1, j1;
        cin>>i1>>j1;
        i1--; j1--;
        a[i1].clear();
        //a[j1].clear();
        a[i1].push_back(j1);
        //a[j1].push_back(i1);

        /*if(used[i1] or used[j1]){
            cout<<-1;
            return 0;
        }
        if(!used[i1]){
            dfs(i1, cnt);
            sol.push_back(ans);
            ans.clear();
        }*/
    }

    /*for(int i = 0; i<n; i++){
        for(int c : a[i]){
            cout<<c<<" ";
        }
        cout<<endl;
    }
    return 0;*/

    /**/
    for(int i = 0; i<n; i++){
        if(!used[i]){
            dfs(i);
            sol.push_back(ans);
            ans.clear();
        }
    }

    
    for(auto vec : sol){
        if(vec.size()>3){
            cout<<-1;
            return 0;
        }
    }
    for(auto vec : sol){
        if(vec.size()==3){
            for(int num : vec){
                cout<<num<<" ";
            }
        }
        cout<<endl;
    }
    
    return 0;
}