#include <bits/stdc++.h>

using namespace std;

#define NMAX 1000000000+1;

struct edge {
	int a, b, cost;
    edge(int st, int en,int c){
        a = st;
        b = en;
        cost = c;
    }
};

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    const int INF = 1000000000;
    int n, st, en;  
    cin>>n>>st>>en;
    st--; en--;
    vector<edge> e;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++){
            int w;
            cin>>w;
            if(w>0){
                e.push_back(edge(i,j,w));
            }
        }
    }


    vector<int> d (n, INF);
	d[st] = 0;
	for (int i=0; i<n-1; ++i)
		for (int j=0; j<e.size(); ++j)
			if (d[e[j].a] < INF)
				d[e[j].b] = min (d[e[j].b], d[e[j].a] + e[j].cost);
    

    /*for(int i = 0; i < d.size(); ++i){
        cout<<d[i]<<" ";
    }*/
    if(d[en]==INF){
        cout<<-1;
    }else{
        cout<<d[en];
    }

    return 0;
}
