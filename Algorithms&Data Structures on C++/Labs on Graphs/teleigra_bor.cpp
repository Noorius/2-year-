#include <bits/stdc++.h>

using namespace std;

#define NMAX 100000+1

int sz = 1;
int n, m, o;

struct vertex{
    int* next = new int[o];
    bool isEndOfWord;
};

vertex t[NMAX+1];

void init(){
    for(int j = 0; j < o; ++j){
        t[0].next[j] = -1;  
    }
}

void add_string(string s){
    int v = 0;
    for(int i = 0; i < s.size(); ++i){
        int c = s[i] -'0';
        if(t[v].next[c] == -1){
            for(int j = 0; j < o; ++j){
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

    cin >> n >> m >> o;

    int price[m];
    for(int i = 0; i <m; i++)
        cin>>price[i];
    
    init();

    for(int i = 0; i < n; i++){
        string st;
        cin>>st;
        add_string(st);
    }

    for(int i = 0; i < n+m+1; ++i){
        cout<<i<<" "<<t[i].isEndOfWord<<" : ";
        for(int j = 0; j < o; ++j){
            cout << t[i].next[j] << " | ";
        }
        cout<<endl;
    }/**/

    return 0;
}