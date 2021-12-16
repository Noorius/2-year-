#include <bits/stdc++.h>

using namespace std;
                        //       0      n-1
bool bin_search(vector<int> &p, int l, int r, string &s, string &t){
    if(l>r) return false;
    int m = l + (r-l)/2;
    if(s.substr(p[m],t.size())==t) return true;
    if(s.substr(p[m],t.size())>t) return bin_search(p, l, m-1, s, t);
    return bin_search(p, m+1, r, s, t);
}


void count_sort(vector<int> &p, vector<int> &c){
    int n = p.size();
    vector<int> cnt(n);
    for(auto x : c){
        cnt[x]++;
    }
    vector<int> p_new(n);
    vector<int> pos(n);
    pos[0] = 0;
    for(int i = 1; i<n; i++){
        pos[i] = pos[i-1] + cnt[i-1];
    }
    for(auto x : p){
        int i = c[x];
        p_new[pos[i]] = x;
        pos[i]++;
    }
    p = p_new;
}

int main(){
    string s;
    cin>>s;
    s+="$";
    int n = s.size();
    vector<int> p(n),c(n);
    {
        vector<pair<char, int> > a(n);
        for(int i = 0; i<n; i++) a[i] = make_pair(s[i],i);
        sort(a.begin(), a.end());

        for(int i=0; i<n; i++) p[i] = a[i].second;
        c[p[0]] = 0;
        for(int i = 1; i < n; i++){
            if(a[i].first == a[i-1].first)
                c[p[i]] = c[p[i-1]];
            else    
                c[p[i]] = c[p[i-1]] + 1;
        }
    }
    int k = 0;
    while((1<<k) < n){
        for(int i = 0; i<n; i++){
            p[i] = (p[i] - (1<<k)+n) %n;
        }
        count_sort(p, c);

        vector<int> c_new(n);
        c_new[p[0]] = 0;
        for(int i = 1; i < n; i++){
            pair<int,int> prev = make_pair(c[p[i-1]], c[(p[i-1]+(1<<k))%n]);
            pair<int,int> now = make_pair(c[p[i]], c[(p[i]+(1<<k))%n]);
            if(now == prev)
                c_new[p[i]] = c_new[p[i-1]];
            else    
                c_new[p[i]] = c_new[p[i-1]] + 1;
        }
        c = c_new;
        k++;
    }

    string t;
    int op;
    cin>> op;
    string sub[n];

    for(int i=0; i<op; i++){
        cin>>t;
        
    
        if(bin_search(p, 0, n-1, s, t))
            cout<<"Yes\n";
        else{
            cout<<"No\n";
        }
        
        /*for(int j = 0; j<n; j++){
            sub[j] = s.substr(p[j], t.length());
        }
        if(bin_search(sub, 0, n-1, t))
            cout<<"Yes\n";
        else cout<<"No\n";
        sub->clear(); */
    }

    return 0;
}
/* 
ababbab$
babb
0 ababbab
2 abbab
4 bab
6 b
1 babbab
3 bbab */