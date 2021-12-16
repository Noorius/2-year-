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
        node * head;
        node * cnt = new node(0);

    public:
    st(){
        tail = NULL;
        head = NULL;
    }

    int size(){
        return cnt->val;
    }

    void front(){
        if(head != NULL){
            cout<< head->val;
        }else cout<<"error";
    }
    void back(){
        if(tail != NULL){
            cout<< tail->val;
        }else cout<<"error";
    }

    void push_back(int x){
       node * item = new node(x);
       if(tail == NULL and head == NULL){
            head = tail = item;
       }else{
           tail->prev = item;
           item->next = tail;
       }
       tail = item;
       cnt->val++;
    }

    void push_front(int x){
       node * item = new node(x);
       if(head == NULL and tail== NULL){
            head = tail = item;
       }else{
           head->next = item;
           item->prev = head;
       }
       head = item;
       cnt->val++;
    }

    void pop_front(){
        if(head==NULL){
            cout<<"error";
            return;
        }else if(tail==head){
            cout<<head->val;
            tail = head = NULL;
        }else{
            cout<<head->val;
            head = head->prev;
        }
        cnt->val--;
    }

    void pop_back(){
        if(tail==NULL){
            cout<<"error";
            return;
        }else if(tail==head){
            cout<<tail->val;
            tail = head = NULL;
        }else{
            cout<<tail->val;
            tail = tail->next;
        }
        cnt->val--;
    }

    void clear(){
        cout<<"ok";
        head = tail = NULL;
        cnt->val = 0;
    }

};


void command(string n, bool &on, st &s){
    if(n=="size")
        cout<<s.size();

    else if(n=="push_back"){
        int k;
        cin>>k;
        s.push_back(k);
        cout<<"ok";
    }
    else if(n=="push_front"){
        int k;
        cin>>k;
        s.push_front(k);
        cout<<"ok";
    }
    else if(n=="pop_back"){
        s.pop_back();
    }
    else if(n=="pop_front"){
        s.pop_front();
    }
    else if(n=="front")
        s.front();
    else if(n=="back"){
        s.back();
    }
    else if(n=="clear"){
        s.clear();
    }
    else if(n=="exit"){
        cout<<"bye";
        on = false;
    }
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    st s;
    string n;
    bool on = true;
    while(on){
        cin>>n;
        command(n,on,s);
        cout<<"\n";
    }
}
