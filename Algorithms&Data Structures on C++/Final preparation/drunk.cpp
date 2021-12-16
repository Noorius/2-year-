#include <iostream>

using namespace std;
#define ll long long

struct node{
    ll val;
    node * next;
    node * prev;
    node(ll x){
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

    ll size(){
        return cnt->val;
    }

    void front(){
        if(head != NULL){
            cout<< head->val;
        }else cout<<"error";
    }

    void push(ll x){
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

    ll pop(){
        ll ret;
        if(head==NULL){
            return -1;
        }else{
            node * temp = head;
            ret = head->val;
            head = head->prev;
            temp = NULL;
        }
        cnt->val--;
        return ret;
    }

    void clear(){
        cout<<"ok";
        head = tail = NULL;
        cnt->val = 0;
    }
    bool empty(){
        return head==NULL;
    }

};


void command(string n, st &s){
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

}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    st p1 = st();
    st p2 = st();

    for(int i=0; i< 5; i++){
        long long n;
        cin>>n;
        if(n==0) p1.push(10);
        else p1.push(n);
        
    }
    for(int i=0; i < 5; i++){
        long long n;
        cin>>n;
        if(n==0) p2.push(10);
        else p2.push(n);
    }
    long long num1, num2;
    long long cnt = 0;
    while(true){
        if(p1.empty() or p2.empty()) {break;}
        if(cnt>=10e6) {cout<<"botva"; return 0;}
        num1 = p1.pop();
        num2 = p2.pop();
        if(num1==-1 or num2==-1) break;
        if(num1 > num2){
            p1.push(num1); p1.push(num2);
        }else{
            p2.push(num1); p2.push(num2);
        }
        cnt++;
    }
    if(p1.empty()) cout<<"second "<<cnt;
    else if(p2.empty()) cout<<"first "<<cnt;
    return 0;
}