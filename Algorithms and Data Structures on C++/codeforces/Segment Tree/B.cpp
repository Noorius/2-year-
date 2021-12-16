#include <bits/stdc++.h>

using namespace std;

struct segtree{
    vector<long long> tree;
    int size;
    void init(int n){
        size = 1;
        while(size<n) size*=2;

        tree.assign(2*size-1,0);
    }

    void build(vector<int> &a, int x, int lx, int rx){
        if(rx - lx ==1){
            if(lx < a.size())
                tree[x] = a[lx];
        }else{
           int m = (lx+rx)/2; 
           build(a,2 * x + 1, lx, m);
           build(a,2 * x + 2, m, rx);
           tree[x] = tree[2*x+1] + tree[2*x+2];
        }
    
    }

    void build(vector<int> &a){
        init(a.size());
        build(a, 0, 0, size);
    }

    void set(int i, int v, int x, int lx, int rx){
        if(rx - lx == 1){
            tree[x] = v;
            return;
        }
        int m = (lx+rx)/2;
        if(i<m){
            set(i, v, 2 * x + 1, lx, m);
        }else{
            set(i,v,2 * x + 2, m, rx);
        }
        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }
    void set(int i, int v){
        set(i,v,0,0,size);
    }

    long long sum(int l, int r, int x, int lx, int rx){
        if(l>= rx or lx>=r){
            return 0;
        }
        if(lx >= l and rx <= r){
            return tree[x];
        }
        int m = (lx+rx)/2;
        long long summa = sum(l,r,2*x+1,lx, m) + sum(l,r,2*x+2,m,rx);
        return summa;
    }

    long long sum(int l, int r){
        return sum(l,r,0,0,size);
    }
};

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n, m;
    cin>>n>>m;
    segtree s;
    vector<int> a(n);
    for(int i=0;i<n;i++){cin>>a[i];}
    s.build(a);

    for(int t = 0; t<m; t++){
        int c; cin>>c;
        if(c==1){
            int i, v;
            cin>>i>>v;
            s.set(i,v);
        }else{
            int l,r;
            cin>>l>>r;
            cout<<s.sum(l,r)<<"\n";
        }
    }

    return 0;
}

//g++ -std=c++11 A.cpp