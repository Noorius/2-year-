#include <bits/stdc++.h>
using namespace std;
#define inf 1000

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

	int n,s,f;
	cin>>n>>s>>f;
	vector < vector < pair<int,int> > > g (n);

    for(int i = 0; i<n; i++){
        for(int j=0; j<n; j++){
            int temp;
            cin>>temp;
            g[i].push_back(make_pair(j,temp));
        }
    }

    /*for(int i = 0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<g[i][j].first<<" - "<<g[i][j].second<<" | ";
        }
        cout<<endl;
    }*/
    
	vector<int> d (n, inf),  p (n);

	s--; f--;
	d[s] = 0;

	vector<char> u (n);
	for (int i=0; i<n; ++i) {
		int v = -1;
		for (int j=0; j<n; ++j)
			if (!u[j] && (v == -1 || d[j] < d[v]))
				v = j;
		if (d[v] == inf)
			break;
		u[v] = true;
 
		for (size_t j=0; j<g[v].size(); ++j) {
			int to = g[v][j].first,
				len = g[v][j].second;
			if (d[v] + len < d[to] and len>=0) {
				d[to] = d[v] + len;
				p[to] = v;
			}
		}
	}

	if(d[f]==inf){
		cout<<-1;
		return 0;
	} 
	//else cout<<d[f];
	vector<int> path;
	for (int v=f; v!=s; v=p[v])
		path.push_back (v);
	path.push_back (s);
	reverse (path.begin(), path.end());
	for(int c : path) {
		cout<<c+1<<" ";
	}

    return 0;

}