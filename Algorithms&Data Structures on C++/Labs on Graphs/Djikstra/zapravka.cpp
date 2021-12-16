#include <bits/stdc++.h>
using namespace std;
#define inf 1000000000

/*bool oper(const pair<int, int>& r, const pair<int, int> &l) {
        //Compare canonical forms of l and r.
        return ;
}*/

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

	int n,m;
	cin>>n>>m;

	vector < vector < pair<int,int> > > g(n, vector < pair<int,int> >(n,{0,0}) );

    for(int i = 0; i<m; i++){
        int x, y, t, w;
        cin>>x>>y>>t>>w;
        g[x-1][y-1] = make_pair(t,w-3e6);
        g[y-1][x-1] = make_pair(t,w-3e6);
    }

    /*for(auto c : g){
        for(auto para : c){
            cout<<para.first<<" "<<para.second<<" | ";
        }
        cout<<endl;
    }*/
    
	vector<pair<int,int> > d (n, make_pair(0,-inf));

	d[0] = make_pair(0,-inf);

	vector<char> u (n);
	for (int i=0; i<n; ++i) {
		int v = -1;
		for (int j=0; j<n; ++j)
			if (!u[j] && (v == -1 || d[j].second > d[v].second))
				v = j;
        
		/*if (d[v].first == 0 and d[v].second == -inf)
			break;*/

		u[v] = true;

		for (int j=0; j<n; ++j){

			int time_road = g[v][j].first;
            int max_w = g[v][j].second;
            int trans_w = d[v].second;
            if(v==0) trans_w = max_w;

            if(d[v].first+time_road <= 1440 and j!=v and max_w>=100){ 
                if(trans_w > max_w){
                    trans_w = max_w;
                }
                if(trans_w > d[j].second and (d[v].first+time_road < 1440 and v!=n-1)){
                    d[j] = make_pair(d[v].first+time_road,trans_w);
                }
            }
		}
	}

    cout<<d[n-1].second/100<<endl;

    return 0;

}

/*
0 0 | 10 220 | 1 99 | 
10 220 | 0 0 | 20 201 | 
1 99 | 20 201 | 0 0 | 
*/