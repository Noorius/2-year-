#include <bits/stdc++.h>

using namespace std;

#define NMAX 1000

struct vertex{
    int next[26];
    bool leaf;
    vertex(){
        leaf = false;
    }
};

vertex t[NMAX+1];
int sz = 1;

void init(){
    for(int j = 0; j<26; j++){
        t[0].next[j] = -1;
    }
}

void add_string(string s){
    int v = 0;
    for(int i=0; i<s.size(); ++i){
        int c = s[i] - 'a';
        if(t[v].next[c] == -1){
            for(int j=0; j<26; ++j){
                t[sz].next[j] = -1;
            }
            t[v].next[c] = sz++;
        }
        v = t[v].next[c];
    }
    t[v].leaf = true;
}

bool search(string s){
    int v = 0;
    for(int i=0; i<s.size(); ++i){
        int c = s[i] - 'a';
        if(t[v].next[c] == -1){
            return false;
        }
        v = t[v].next[c];
    }
    return t[v].leaf;
}

int main(){
    int n;
    cin>>n;
    string str;
    init();
    for(int i=0; i<n; i++){
        cin>>str;
        add_string(str);
    }

    return 0;
}