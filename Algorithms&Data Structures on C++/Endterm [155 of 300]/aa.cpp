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
    
    for(vector<int>::iterator i = a[v].begin(); i!=a[v].end(); ++i){
        if(!used[*i]){
            dfs(*i);
        }
    }
    ans.push_back(v+1);
}

void check(int ch, int it){
    //cout<<ch<<" ~ "<<it<<endl;
    for(auto c : a[it]){
        if(ch==c){
            cout<<"Impossible";
            exit(0);
        }
        check(ch, c);
    }
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>n>>m;
    
    /*for(int i = 0; i<n; i++){
        used[i] = false;
        for(int j = 0; j<n; j++){
            a[i][j] = 0;
        }
    }*/

	for(int i = 0; i<m; i++){
		int t1, t2;
		cin>>t1>>t2;
        check(t1-1,t2-1);
        //cout<<endl;
		a[t1-1].push_back(t2-1);
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
            //sol.push_back(ans);
            //ans.clear();
        }
    }

    cout<<"Possible\n";
    /*for(auto ans : sol){
        for(auto c : ans)
            cout<<c<<" "; 
        cout<<endl;
    }*/
    reverse(ans.begin(), ans.end());
    for(auto c : ans)
        cout<<c<<" "; 
    


    return 0;
}