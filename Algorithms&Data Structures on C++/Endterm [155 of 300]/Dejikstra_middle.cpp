#include <bits/stdc++.h>

using namespace std;

#define ll                  long long
#define vt                  vector
#define For(i, n)           for(int i = 0; i < n; ++i)
#define pii                 pair<long long, long long>

const int MAX = 2009000999;

const int N = 2e5;
vt<vt<pii> > g(N);
int n, m;

ll Dijkstra(int s, int f) {
	vt<int> dist(n, MAX);
	dist[s] = 0;
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	pq.push({dist[s], s});
	while (!pq.empty()) {
		pii cur = pq.top();
		pq.pop();
        
		if (dist[cur.second] < cur.first) {
			continue;
		}
		for (pii neighbour : g[cur.second]) {
            // min_time[cur.from] <= cur.time_to_start && min_time[cur.to] > cur.time_to_end {
            //     min_time[cur.to] = cur.time_to_end;
            // } 
			if (dist[neighbour.first] > cur.first + neighbour.second) {
				dist[neighbour.first] = cur.first + neighbour.second;
				pq.push({dist[neighbour.first], neighbour.first});
			}
		}
	}
    //vt<int> path {f};
    /*int temp_f = f;
    while (dist[temp_f] != 0) {
        for (pii neighbour : g[temp_f]) {
            if (dist[neighbour.first] + neighbour.second == dist[temp_f]) {
                temp_f = neighbour.first;
                path.push_back(temp_f);
                break;
            }
        }
    }
    reverse(path.begin(), path.end());*/
    if(dist[f] >= MAX){
        cout<<-1;
        exit(0);
    }
	return dist[f];
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	cin >> n >> m;
    For(i, m) {
        int v, u, c; cin >> v >> u >> c;
        v--; u--;
        g[v].push_back({u, c});
        g[u].push_back({v, c});
    }
    ll p = 0;
    bool w1=false, w2=false;
    int s, i, i2, f; cin >> s >> i >> i2>> f;
    s--; i--; i2--; f--;
    if(s==i==i2==f){
        cout<<0;
        exit(0);
    }
    else if(s==f){
        ll res1 = Dijkstra(s, i);
        ll res2 = Dijkstra(s, i2);
        ll res3 = Dijkstra(i, i2);
        if(res1 < res2){
            p+=res1;
        }else{
            p+=res2;
        }
        if(res3>res1+res2){
            p+=(res1 + res2);
        }else{
            p+=res3;
        }
    }
    else if(s!=i!=i2!=f){
        ll res1 = Dijkstra(s, i);
        ll res2 = Dijkstra(s, i2);
        if(res1 < res2){
            p+=res1;
            res1 = Dijkstra(i, i2);
            w2 = true;
        }else{
            p+=res2;
            res1 = Dijkstra(i2, i);
            w1 = true;
        }
        p += res1; 
        p += w1 ? Dijkstra(i, f) : Dijkstra(i2, f);
    }
    
    cout<<p;  
    
    
    
    //int total_dist = res1.first + res2.first + ;
    //cout<<res1.first<<" "<<res2.first<<" "<<res3.first<<" "<<res4.first;
    /*vt<int> total_path;
    for (int v : res1.second) {
        total_path.push_back(v);
    }
    for (int i = 1; i < res2.second.size(); i++) {
        total_path.push_back(res2.second[i]);
    }
    cout << total_dist << endl;
    for (int v : total_path) {
        cout << v << " ";
    }*/
    //cout << endl;
    return 0;
}