#include <bits/stdc++.h>

using namespace std;

#define NMAX 100000+1

struct vertex{
    int next[10];
    bool isEndOfWord;
};

vertex t[NMAX+1];
int sz = 1;
int n, m;

void init(){
    for(int j = 0; j < 10; ++j){
        t[0].next[j] = -1;  
    }
}

void add_string(string s){
    int v = 0;
    for(int i = 0; i < s.size(); ++i){
        int c = s[i] -'0';
        if(t[v].next[c] == -1){
            for(int j = 0; j < 10; ++j){
               t[sz].next[j] = -1;  
            }
            t[v].next[c] = sz++;
        }
        v = t[v].next[c];
    }
    t[v].isEndOfWord = true;
}

bool search(string s){
    int v = 0;
    for(int i = 0; i < s.size(); ++i){
        int c = s[i] - '0';
        if(t[v].next[c] == -1) return false;
        v = t[v].next[c];
    }
    return t[v].isEndOfWord;
}


int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    cin >> n >> m;
    string s;
    init();
    cin>>s;

    for(int i = 0; i <= n-m; i++){
        string sub = s.substr(i,m);
        if(search(sub)){
            cout<<"YES";
            return 0;
        }
        add_string(sub);
    }
    cout<<"NO";
    
    /*for(int i = 0; i < n; ++i){
        for(int j = 0; j < 10; ++j){
            cout << t[i].next[j] << " ";
        }
        cout<<endl;
    }*/

    return 0;
}