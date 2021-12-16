#include <bits/stdc++.h>

#define MAXN 10000

using namespace std;

vector<int> ans;
//vector<vector<int> > sol;
bool used[MAXN];
int n, m;
//vector<vector<int> > a(MAXN, vector<int>());
int a[MAXN][MAXN];

void dfs(int v){
    used[v] = true;
    
    for(int i = 0; i<n; i++){
        if(!used[i] and a[v][i] == 1){
            dfs(i);
        }
    }
    ans.push_back(v+1);
}

bool check(int ch, int it){
    //cout<<ch<<" ~ "<<it<<endl;
    for(int i = 0; i<n; i++){
        if(a[it][i] == 1){
            //cout<<ch<<" ~~ "<<i<<endl;
            if(i==ch){
                return false;
            }
            return check(ch, i);
        }
    }
    return true;
}

int main(){
    cin>>n>>m;
    
    for(int i = 0; i<n; i++){
        used[i] = false;
        for(int j = 0; j<n; j++){
            a[i][j] = 0;
        }
    }

	for(int i = 0; i<m; i++){
		int t1, t2;
		cin>>t1>>t2;
        if(!check(t1-1,t2-1)){
            cout<<"Impossible";
            return 0;
        }
        //cout<<endl;
		a[t1-1][t2-1] = 1;
	}

    /*for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }*/

    for(int i = 0; i<n; i++){
        if(!used[i]){
            dfs(i);
        }
    }

    cout<<"Possible\n";
    for(vector<int>::reverse_iterator i = ans.rbegin(); i!=ans.rend(); i++)
        cout<<*i<<" "; 


    return 0;
}