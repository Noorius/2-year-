#include <bits/stdc++.h>

using namespace std;

#define NMAX 100000+1

struct vertex{
    struct vertex *next[26];
    bool isEndOfWord;
};

int n;

struct vertex *getNode(void){
    struct vertex *Node = new vertex;
    Node->isEndOfWord = false;
    for(int i = 0; i <26; i++){
        Node->next[i] = NULL;
    }
    return Node;
}

void add_string(struct vertex *root, string s){
    struct vertex *newL = root;

    for(int i = 0; i < s.size(); ++i){
        int c = s[i] -'a';
        if(!newL->next[c]){
            newL->next[c] = getNode();
        }
        newL = newL->next[c];
    }
    newL->isEndOfWord = true;
}

void remove(struct vertex *root, string s){
    struct vertex *newL = root;

    for(int i = 0; i < s.size(); ++i){
        int c = s[i] - 'a';
        if(newL->next[c] == NULL) return;
        newL = newL->next[c];
    }
    newL -> isEndOfWord = false;
}

int cnt(struct vertex *root){
    int res = 0;

    if(root->isEndOfWord) res++;

    for(int i = 0; i < 26; ++i){
        if(root->next[i]) res+=cnt(root->next[i]);
    }
    return res;
}

int st_cnt(struct vertex *root, string s){
    struct vertex *newL = root;

    for(int i = 0; i < s.size(); ++i){
        int c = s[i] - 'a';
        if(newL->next[c] == NULL) return 0;
        newL = newL->next[c];
    }
    return cnt(newL);
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    cin >> n;
    struct vertex *root = getNode();

    for(int i = 0; i < n; i++){
        string op, w;
        cin>>op>>w;
        if(op == "+"){
            add_string(root,w);
        }else if(op == "-"){
            remove(root,w);
        }else if(op == "?"){
            cout<<st_cnt(root,w)<<"\n";
        }
    }
    /*for(int i = 0; i < n; ++i){
        for(int j = 0; j < 10; ++j){
            cout << t[i].next[j] << " ";
        }
        cout<<endl;
    }*/

    return 0;
}