#include <iostream>
#include <string>

using namespace std;

struct node{
    node * prev;
    int val;
    node(char newVal){
        prev = NULL;
        val = newVal - '0';
    }
};

struct st{
    private:
        node * tail;
    public:
        st(){
            tail = NULL;
        }

        void push(char x){
            node * item = new node(x);
            if(tail==NULL){
                tail=item;
            }
            else if(x=='+'){
                tail->val = tail->val + tail->prev->val;
                tail->prev = tail->prev->prev;
            }
            else if(x=='-'){
                tail->val = tail->prev->val - tail->val;
                tail->prev = tail->prev->prev;
            }
            else if(x=='*'){
                tail->val = tail->val * tail->prev->val;
                tail->prev = tail->prev->prev;
            }
            else{
                item->prev = tail;
                tail = item;
            }
        }
        void answer(){
            cout<<tail->val;
        }
};



int main(){
    st s;
    char sym;
    while(cin>>sym){
        if(sym==(char)sym)
            s.push(sym);
    }
    //getline(cin,math);
    //for(long unsigned int i = 0; i < math.length(); i+=2){
    //    s.push(math[i]);
    //}
    s.answer();
    return 0;
} 
