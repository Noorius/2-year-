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
        node * head;
        node * tail;
        node * cnt = new node(0);

    public:
    st(){
        head = NULL;
        tail = head;
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
        if(head != NULL){
            cout<< tail->val;
        }else cout<<"error";
    }

    void push_front(int x){
       node * item = new node(x);
       if(head != NULL){
            head->prev = item;
            item->next = head;
       }
       else{
           head = item;
           tail = head;
       }  
       head = item;
       cnt->val++;
    }

    void push_back(int x){
       node * item = new node(x);
       if(tail != NULL){
            tail->next = item;
            item->prev = tail;
       }
       else{
           tail = item;
           head = tail;
       }  
       tail = item;
       cnt->val++;
    }

    void pop_front(){
        if(head != NULL){
            cout<<head->val;
        
            if(head==tail){
                tail=NULL;
                head=NULL;
            }else head = head->next;
                
            cnt->val--;
        }
        else{
            cout<<"error";
        }
    }

    void pop_back(){
        if(tail != NULL){
            cout<<tail->val;
            
            if(head==tail){
                head=NULL;
                tail=NULL;
            }else tail = tail->prev;

            cnt->val--;
        }
        else{
            cout<<"error";
        }
    }

    void clear(){
        cout<<"ok";
        head = NULL;
        tail = NULL;
        cnt->val = 0;
    }

};


void command(string n, bool &on, st &s){
    if(n=="size")
        cout<<s.size();

    else if(n=="push_front"){
        int k;
        cin>>k;
        s.push_front(k);
        cout<<"ok";
    }
    else if(n=="push_back"){
        int k;
        cin>>k;
        s.push_back(k);
        cout<<"ok";
    }
    else if(n=="pop_front"){
        s.pop_front();
    }
    else if(n=="pop_back"){
        s.pop_back();
    }
    else if(n=="front")
        s.front();

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