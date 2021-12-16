#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct node{
    string val;
    int index;
    node * prev;
    node * next;
    node(int newIndex, string newVal){
        index = newIndex;
        val = newVal;
        prev = NULL;
        next = NULL;
    }
};

struct st{
    private:
        node * tail;
        node * head;
    public:
        int cnt;
        bool error;
        st(){
            tail=NULL;
            head=NULL;
            cnt = 0;
            error = false;
        }

        void push(char op, int index, string n){

            if(op=='-'){
                if(index>cnt){
                    error=true;
                    return;
                }    
                node * temp = head;
                while(temp->index!=index) {
                    temp=temp->next;
                }    
                if(temp->next==NULL and temp->prev==NULL)
                    head=tail=NULL;
                else if(temp==head){
                    head = head->next;
                    head->prev=NULL;
                    temp=head;
                    while(temp!=NULL){
                        temp->index--;
                        temp=temp->next;
                    } 
                }else if(temp==tail){
                    tail = tail->prev;
                    tail->next=NULL;
                    temp=NULL;
                }else{
                    node* nextNode = temp->next;
                    temp->next->prev = temp->prev;
                    temp->prev->next = temp->next;
                    temp=NULL;
                    while(nextNode!=NULL){
                        nextNode->index--;
                        nextNode = nextNode->next;
                    }
                } 
                cnt--;   
                
            }else if(op=='+'){
              node * item = new node(index,n);
              if(head==NULL){
                  head=tail=item;
                  cnt++;
              }else if(cnt==1 and index==1){
                  head = item;
                  head->next = tail;
                  tail->prev = head;
                  tail->index++;
                  cnt++;
              }else if(index<=cnt){
                  node*temp = head;
                  while(temp->index!=index){
                      temp=temp->next;
                  }
                  if(temp==head){
                      head->prev = item;
                      item->next = head;
                      head = item;
                  }else{
                      temp->prev->next = item;
                      item->prev = temp->prev;
                      temp->prev = item;
                      item->next = temp;
                  }
                  while(temp){
                      temp->index++;
                      temp=temp->next;
                  }
                  cnt++;
              }else if(index-1==cnt){
                  tail->next = item;
                  item->prev = tail;
                  tail = item;
                  cnt++;
              }else{
                  error=true;
              }


            }else if(op=='*'){
                if(index>cnt){
                    error=true;
                    return;
                } 
                node*temp = head;
                while(temp->index!=index){
                    temp=temp->next;
                }
                temp->val = n;
            }
                
        }

        void show(){
            if(error){
                cout<<"ERROR";
                return;
            }
            if(cnt==0 and head == NULL){
                cout<<"EMPTY";
                return;
            }
            node * cur = head;
            while(cur){
                cout<<cur->val<<endl;
                cur = cur->next;
            }
        }
};

void write(){
    string n, n2;
    char op;
    int index;
    st s;
    while(cin>>n){
        op = n[0];
        n.erase(0,1);
        index = stoi(n);

        getline(cin,n2);
        n2.erase(0,1);

        s.push(op,index,n2);
        if(s.error)
            break;
    }
    s.show();
}

int main(){
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
    write();
    return 0;
}