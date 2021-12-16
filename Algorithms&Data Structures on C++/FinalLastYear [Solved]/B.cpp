#include <bits/stdc++.h>

using namespace std;

#define NMAX 100000+1

struct vertex{
    int next[2];
    bool isEndOfWord;
};

vertex t[NMAX+1];
int sz = 1;
int n, m;

void init(){
    for(int j = 0; j < 2; ++j){
        t[0].next[j] = -1;  
    }
}

void add_string2(int s){
    int v = 0;
    if(t[v].next[0]==m or t[v].next[1]==m)
        return;

    if(t[v].next[0] == -1){
        for(int j = 0; j < 2; ++j){
        t[sz].next[j] = -1;  
        }
        t[v].next[0] = s*2;
    }
    if(t[v].next[1] == -1){
        for(int j = 0; j < 2; ++j){
        t[sz].next[j] = -1;  
        }
        t[v].next[1] = s-1;
    }
    
    if(t[v].next[0]==m or t[v].next[1]==m){
        t[v].isEndOfWord = true;
    }
    v = sz;
    sz++;
}

void add_string(int s, int v){
    if(s==m){
        t[v].isEndOfWord = true;
        return;
    }
    cout<<s<<endl;
    if(t[v].next[0] == -1){
        for(int j = 0; j < 2; ++j){
        t[sz].next[j] = -1;  
        }
        t[v].next[0] = s*2;
    }
    sz++;
    add_string(t[v].next[0],sz-1);

    if(t[v].next[1] == -1){
        for(int j = 0; j < 2; ++j){
        t[sz].next[j] = -1;  
        }
        t[v].next[1] = s-1;
    }
    sz++;
    add_string(t[v].next[1],sz-1);
    //v = sz;
    //sz++;
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
    init();

    add_string(n, 0);
    
    /*for(int i = 0; i < n; ++i){
        for(int j = 0; j < 10; ++j){
            cout << t[i].next[j] << " ";
        }
        cout<<endl;
    }*/

    return 0;
}