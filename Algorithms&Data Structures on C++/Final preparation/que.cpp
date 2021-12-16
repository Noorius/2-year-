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

    void push(int x){
       node * item = new node(x);
       if(head == NULL){
            head = tail = item;
       }else{
           tail->prev = item;
           item->next = tail;
       }
       tail = item;
       cnt->val++;
    }

    void pop(){
        if(head==NULL){
            cout<<"error";
            return;
        }else{
            cout<<head->val;
            head = head->prev;
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

    else if(n=="push"){
        int k;
        cin>>k;
        s.push(k);
        cout<<"ok";
    }
    else if(n=="pop"){
        s.pop();
    }

    else if(n=="front")
        s.front();

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
