#include <bits/stdc++.h>
using namespace std;
#define inf 100000

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

	int n,m;
	cin>>n;
    vector<int> cost;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        cost.push_back(temp);
    }
    cin>>m;
	vector < vector < int > > g(n, vector<int>(n,inf));

    for(int i = 0; i<m; i++){
        int temp1, temp2;
        cin>>temp1>>temp2;
        g[temp1-1][temp2-1] = cost[temp1-1];
        g[temp2-1][temp1-1] = cost[temp2-1];
    }

    /*for(auto c : g){
        for(auto para : c){
            cout<<para<<" | ";
        }
        cout<<endl;
    }*/
    
	vector<int> d (n, inf),  p (n);

	d[0] = 0;

	vector<char> u (n);
	for (int i=0; i<n; ++i) {
		int v = -1;
		for (int j=0; j<n; ++j)
			if (!u[j] && (v == -1 || d[j] < d[v]))
				v = j;
		if (d[v] >= inf)
			break;
		u[v] = true;
 
		for (int j=0; j<n; ++j){
			d[j] = min(d[j], d[v] + g[v][j]);
		}
        if(v==n-1){
            cout<<d[v];
            return 0;
        }
	}

    /*for(int i=0; i<n; ++i) {
        cout<<d[i]<<" ";
    }*/

	cout<<-1;
	/*vector<int> path;
	for (int v=f; v!=s; v=p[v])
		path.push_back (v);
	path.push_back (s);
	reverse (path.begin(), path.end());
	for(int c : path) {
		cout<<c+1<<" ";
	}*/

    return 0;

}