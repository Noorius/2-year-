#include <iostream>

using namespace std;

struct node{
    int val;
    string name;
    node * next;
    node * prev;
    node(int x, string newName){
        val = x;
        name = newName;
        next = NULL;
        prev = NULL;
    }
};

struct st{
    private:
        node * head;
        node * tail;
        node * cur;

    public:
    st(){
        head = NULL;
        tail = head;
    }

    void push_back(int x, string name){
       node * item = new node(x,name);
       if(tail != NULL){
            tail->next = item;
            item->prev = tail;
       }
       else{
           tail = item;
           head = tail;
       }  
       tail = item;
    }

    void view(){
        cur = head;
        while(cur!=NULL){
            cout<<cur->val<<" "<<cur->name<<endl;
            cur = cur->next;
        }
    }

};


int main()
{
    st s9,s10,s11;
    int num;
    string name;

    while (cin >> num >> name)
    {
        if(num==9)
            s9.push_back(num, name);
        else if(num==10)
            s10.push_back(num, name);
        else if(num==11)
            s11.push_back(num, name);
    }
    s9.view();
    s10.view();
    s11.view();

    return 0;
}