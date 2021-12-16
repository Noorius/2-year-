#include <iostream>
 
using namespace std;
 
int cnt = 0;

struct Node{
    int val;
    Node* next;
    int index;
    Node(): val(0), next(nullptr), index(0){}
    Node(int x, int index): val(x), next(nullptr), index(index) {}
    Node(Node* next): val(0), next(next) {}
    Node(int x, Node* next): val(x), next(next) {}
};
 
Node* insert(Node* head, Node* item, int p){
    Node *new_node = item;
    if (p ==0) {
        new_node->next = head;
        head=new_node;
    }
    else {
            Node *temp = head;
    while (p !=1) {
        temp= temp->next;
        p-=1;
    }
    new_node->next = temp->next;
    temp->next =new_node;
    }
    return head;
}
 
Node* remove(Node* head, int p){
        if (p ==0) {
    head= head->next;
        }
    else {
            Node *temp = head;
    while (p!=1) {
    temp= temp->next;
    p-=1;
            }
    temp->next = temp->next->next;
        }
        return head;
}
 
Node* replace(Node* head, int p1, int p2){
    if(p1==0){
        head=head->next;
    }
    Node* temp = head;
    while(temp->next->index!=p1){
        temp=temp->next;
    }
    Node * rep = temp->next;
    remove(head, p1);
    insert(head,rep,p2);
    return head;
}
 
bool rev = -1;
Node* reverse(Node* head){
    rev = rev * -1;
    return head;
}
 
void print_rev(Node *cur){
    if(!cur) return;
    print_rev(cur->next);
    cout<<cur->val<<endl;
}

void print(Node* head){
    if(!head){
        cout<<-1;
        return;
    } 
    if(rev==1){
        print_rev(head);
    }else{
        Node * cur = head;
        while(cur){
            cout<<cur->val<<endl;
            cur = cur->next;
        }
    }
}
 
Node* cyclic_left(Node* head, int x){
    for(int i=0; i<=x; i++){
        insert(head, head->next,cnt);
        head = head->next;
    }
    return head;
}
 
Node* cyclic_right(Node* head, int x){
    for(int i=0; i<x; i++){
        while(head->index!=cnt-x){
            insert(head,head->next,cnt);
            head = head->next;
        }
    }
    return head;
}
 
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    Node* head = nullptr;
    while (true)
    {
        int command; cin >> command;
        if (command == 0){
            break;
        }else if(command == 1){
            int x, p; cin >> x >> p;
            head = insert(head, new Node(x,p), p);
        }else if (command == 2){
            int p; cin >> p;
            head = remove(head, p);
        }else if (command == 3){
            print(head);
        }else if (command == 4){
            int p1, p2; cin >> p1 >> p2;
            head = replace(head, p1, p2);
        }else if (command == 5){
            head = reverse(head);
        }else if (command == 6){
            int x; cin >> x;
            head = cyclic_left(head, x);
        }else if (command == 7){
            int x; cin >> x;
            head = cyclic_right(head, x);
        }   
    }
    return 0;
}