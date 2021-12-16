#include <iostream>
#include <string>

using namespace std;

struct node{
    char val;
    int n = 0;
    node * prev;
    node(char newVal){
        val = newVal;
        prev = NULL;
    }

};

struct st{
    private:
        node * tail;
    public:
        st(){
            tail=NULL;
        }

        void push(char x){
            node * item = new node(x);

            if(tail == NULL){
                tail = item;
            }else if((tail->val == '(' && item->val == ')')||(tail->val == '{' && item->val == '}')||(tail->val == '[' && item->val == ']')){
                tail = tail->prev;
            }
            else{
                item->prev = tail;
                tail = item;
            }
        }

        bool empty(){
            return tail == NULL;
        }
};

int main(){
    st s;
    string seq;
    cin>>seq;

    for(int i = 0; i < seq.size(); i++){
        s.push(seq[i]);
    }
    
    if(s.empty()){
        cout<<"yes";
    }else{
        cout<<"no";
    }

    return 0;
} 