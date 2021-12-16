#include <bits/stdc++.h>
using namespace std;
#define inf 10e9+10
#define ll long long

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

	ll n, m;
	cin>>n>>m;
    vector<pair<ll,ll> > cost;
    for(int i=0;i<n;i++){
        ll temp, temp2;
        cin>>temp>>temp2;
        cost.push_back({temp,temp2});
    }
    
    /*for(auto c : g){
        for(auto para : c){
            cout<<para<<" | ";
        }
        cout<<endl;
    }*/

	vector<ll> d (n, inf);

	
    set<pair<ll,pair<ll,pair<ll,ll> > > >pq;
    pq.insert(make_pair(0, make_pair(0, make_pair(cost[0].first,cost[0].second))));
    d[0] = 0;

	while(!pq.empty()) {
		pair<ll,pair<ll,pair<ll,ll> > > cur = *pq.begin();

        pq.erase(pq.begin());
        if(cur.first > d[cur.second.first]) continue;
        
		for (int j=0; j<n; ++j){
            if(cur.second.first != j){
                ll len = abs(cur.second.second.first - cost[j].first) + abs(cur.second.second.second - cost[j].second);
                len = max(len, cur.first);
                if(len < d[j]){
                    pq.erase(make_pair(d[j],make_pair(j,make_pair(cost[j].first,cost[j].second))));
                    d[j] = len;
                    pq.insert(make_pair(d[j],make_pair(j,make_pair(cost[j].first,cost[j].second))));
                }
            }
		}
	}
    cout<<d[n-1];
    /*for(int i=0; i<n; ++i) {
        cout<<d[i]<<" ";
    }*/

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