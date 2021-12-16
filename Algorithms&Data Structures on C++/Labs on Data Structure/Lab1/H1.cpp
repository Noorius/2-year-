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

    int front(){
        if(head != NULL){
            return head->val;
        }
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
            if(head==tail){
                tail=NULL;
                head=NULL;
            }else head = head->next;
                
            cnt->val--;
        }
    }

    void pop_back(){
        if(tail != NULL){
            
            if(head==tail){
                head=NULL;
                tail=NULL;
            }else tail = tail->prev;

            cnt->val--;
        }
    }

};

int main(){
    st s1,s2;
    char command;
    int n,k;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>command;
        if(command = '+'){
            cin>>k;
            s1.push_back(k);
        }
        if(command == '*'){
            cin>>k;
            s1.push_front(k);
        }
        if(command == '-'){
            cout<<s2.front()<<endl;
            s2.pop_front();
        }
        if(s1.size()>s2.size()){
            s2.push_back(s1.front());
            s1.pop_front();
        }
    }
}