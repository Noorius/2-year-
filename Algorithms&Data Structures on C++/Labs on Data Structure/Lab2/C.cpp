#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct node{
    string val;
    node * prev;
    node * next;
    node(string newVal){
        val = newVal;
        next = NULL;
        prev = NULL;
    }
};

struct st{
    private:
        node * tail;
    public:
    bool  error;
    st(){
        tail=NULL;
        error = false;
    }

    void push(char x, string n){
        if(x=='+'){
            node * item = new node(n);
            if(tail == NULL){
                tail = item;
            }else{
                tail->next = item;
                item->prev = tail;
                tail = item;
            }
        }else if(x=='-'){
            node * wanted = find(n);
            if(wanted==NULL or tail==NULL){
                error = true; 
                return;
            }else if(!tail->prev && !tail->next){
                tail=tail->prev=tail->next=NULL;
                return;
            }else if(wanted==tail){
                wanted=NULL;
                tail = tail->prev;
                tail->next = NULL;
                return;
            }else if(!wanted->prev){
                wanted->next->prev=NULL;
                wanted=NULL;
                return;
            }
            wanted->prev->next = wanted->next;
            wanted->next->prev = wanted->prev;
            wanted=NULL;
        }
            
    }

    node* find(string x){
        node*temp = tail;
        while(temp){
            if(temp->val == x){
                return temp;
            }
            temp=temp->prev;
        }
        return NULL;
    }

    bool empty(){
        return tail == NULL;
    }

    void show(){
        if(empty()){
            cout<<"EMPTY";
            return;
        }
        if(error){
            cout<<"ERROR";
            return;
        }
        node * cur = tail;
        vector<string> v;
        vector<string>::iterator it = v.begin();
        while(cur){
            v.push_back(cur->val);
            cur = cur->prev;
        }
        sort(v.begin(),v.end());
        for(auto it : v){
            cout<<it<<" ";
        }
    }
};


void write(){
    string n;
    st s;
    while(cin>>n){
        char k = n[0];
        n.erase(n.begin(),n.begin()+1);
        s.push(k,n);
    }
    s.show();
}

int main(){
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
    write();
    return 0;
}

//cout<<"tail "<<tail<<"tail val "<<tail->val<<endl;
//cout<<"wanted "<<wanted<<"wanted val "<<wanted->val<<endl;