#include <iostream>

using namespace std;

struct node{
    int val;
    node * next;
    node * prev;
    node(int x){
        val = x;
        next = NULL;
        prev = NULL;
    }
};

struct st{
    private:
        node * tail;
        node * cnt = new node(0);

    public:
    st(){
        tail = NULL;
    }

    int size(){
        return cnt->val;
    }

    void back(){
        if(tail != NULL){
            cout<< tail->val;
        }else cout<<"error";
    }

    void push(int x){
       node * item = new node(x);
       if(tail != NULL){
            tail->next = item;
            item->prev = tail;
       }
       tail = item;
       cnt->val++;
    }

    void pop(){
        if(tail != NULL){
            cout<<tail->val;
            tail = tail->prev;
            if(tail != NULL){
                tail->next = NULL; 
            }
            cnt->val--;
        }
        else{
            cout<<"error";
        }
    }

    void clear(){
        cout<<"ok";
        tail = NULL;
        cnt->val = 0;
    }

};


void command(string n, bool &on, st &s){
    if(n=="size")
        cout<<s.size();

    else if(n=="push"){
        int k;
        cin>>k;
        s.push(k);
        cout<<"ok";
    }
    else if(n=="pop"){
        s.pop();
    }

    else if(n=="back")
        s.back();

    else if(n=="clear"){
        s.clear();
    }
    else if(n=="exit"){
        cout<<"bye";
        on = false;
    }
}

int main(){
    st s;
    string n;
    bool on = true;
    while(on){
        cin>>n;
        command(n,on,s);
        cout<<"\n";
    }
}

