#include <bits/stdc++.h>

#define MAXN 100000

using namespace std;

vector<long long> ans;
vector<vector<long long> > sol;
bool used[MAXN];
long long n, m;
vector<vector<long long> > a(MAXN, vector<long long>());
//long long a[MAXN][MAXN];

void dfs(long long v){
    used[v] = true;
    ans.push_back(v+1);
    for(auto c : a[v]){
        if(!used[c]){
            dfs(c);
        }
    }
    
}

bool check(long long ch, long long it){
    //cout<<ch<<" ~ "<<it<<endl;
    for(auto c : a[it]){
        if(c==ch){
            return false;
        }
        return check(ch, c);
    }
    return true;
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>n>>m;
    
    for(long long i = 0; i<n; i++){
        used[i] = false;
    }

	for(long long i = 0; i<m; i++){
		long long t1, t2;
		cin>>t1>>t2;
        if(!check(t1-1,t2-1)){
            cout<<"Impossible";
            return 0;
        }
        //cout<<endl;
		a[t1-1].push_back(t2-1);
	}

    for(long long i = 0; i<n; i++){
        if(!used[i]){
            dfs(i);
        }
    }

    cout<<"Possible\n";
    //reverse(ans.begin(), ans.end());
    for(auto c : ans){
        cout<<c<<" ";
    }
    /*for(vector<long long>::reverse_iterator i = ans.rbegin(); i!=ans.rend(); i++)
        cout<<*i<<" "; */


    return 0;
}