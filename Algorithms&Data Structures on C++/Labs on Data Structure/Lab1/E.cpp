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
    node * head;
    node * tail;
    node * cnt = new node(0);

    st(){
        head = NULL;
        tail = head;
    }

    int front(){
        return head->val;
    }

    void push_back(int x){
       node * item = new node(x);
       if(tail != NULL){
            tail->next = item;
            item->prev = tail;
            tail = item;
       }
       else{
           tail = item;
           head = tail;
       }  
    }

    int pop_front(){
        int temp = head->val;

        if(head==tail){
            tail=NULL;
            head=NULL;
        }else{
            head = head->next;
            head->prev = NULL;
        }

        return temp;
    }

    bool empty(){
        return head==NULL;
    }

};

void compare(st &s1, st &s2){

    while(!s1.empty() and !s2.empty()){

        if(s1.front() > s2.front() and (s1.front()==0 and s2.front()==9)){
            s1.push_back(s1.pop_front());
            s1.push_back(s2.pop_front());
            s1.cnt->val++;
        }else{
            s2.push_back(s1.pop_front());
            s2.push_back(s2.pop_front());
            s2.cnt->val++;
        }
        if(s1.cnt->val + s2.cnt->val >= 1000000){
            cout<<"botva";
            exit(0);
        }
    }
    
}

int main(){
    st s1, s2;

    for(int i = 0, j; i<10; i++){
        cin>>j;
        if(i<=4)
            s1.push_back(j);
        else
            s2.push_back(j);
    }

    compare(s1,s2);

    if(s1.cnt->val > s2.cnt->val){
        cout<<"first"<<" ";
    }else{
        cout<<"second"<<" ";
    }
    cout<<s1.cnt->val + s2.cnt->val;

    return 0;
}