#include <iostream>

using namespace std;

struct node{
    node * next;
    node * prev;
    char val;
    node(char newVal){
        val = newVal;
        next = NULL;
        prev = NULL;
    }
};

struct st{
    private:
        node * tail;
        node * head;
    public:
    int cnt;
    st(){
        tail = NULL;
        head = NULL;
        cnt = 0;
    }

    void push(char op, char x){
        cnt++;
        node * item = new node(x);
        if(head==NULL && tail==NULL){
            tail = item;
            head = item;
        }
        else{
            if(op == '+'){
                tail->next = item;
                item->prev = tail;
                tail = item;
            }else if(op == '*'){
                head->prev = item;
                item->next = head;
                head = item;
            }
        }
    }
    char show(){
        cnt--;
        node * temp = head;
        head = head->next;
        return temp->val;
    }
};

int main(){
    st s1, s2;
    string op;
    int kolvo;
    cin>>kolvo;
    for(int i = 0; i <= kolvo; i++){
        getline(cin,op);
        if(op[0]=='+' || op[0]=='*')
            s1.push(op[0],op[2]);
        else if(op[0]=='-')
            cout<<s2.show()<<endl;
        if(s1.cnt > s2.cnt){
            s2.push('+',s1.show());
        }
    }
    return 0;
}