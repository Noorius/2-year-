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
    vector<int> p (n, -1);
	for (;;){
        bool any = false;
        for (int j=0; j<e.size(); ++j)
			if (d[e[j].a] < INF)
                if(d[e[j].b] > d[e[j].a] + e[j].cost){
                    d[e[j].b] = d[e[j].a] + e[j].cost;
                    p[e[j].b] = e[j].a;
                    any = true;
                }
        if(!any) break;
    }
		
    

    /*for(int i = 0; i < d.size(); ++i){
        cout<<d[i]<<" ";
    }
    cout<<endl;*/
    if(d[en]==INF){
        cout<<-1;
    }else{
        cout<<d[en]<<endl;
        for(vector<int>::reverse_iterator it = p.rbegin(); it!=p.rend(); it++){
            cout<<(*it)<<" ";
        }
    }

    return 0;
}
