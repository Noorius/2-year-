#include <bits/stdc++.h>
 
using namespace std;
 
vector<int> num();

struct Node{
    int val;
    Node* next;
    Node(): val(0), next(nullptr) {}
    Node(int x): val(x), next(nullptr) {}
    Node(Node* next): val(0), next(next) {}
    Node(int x, Node* next): val(x), next(next) {}
};
 
Node* insert(Node* head, Node* node, int p){
    Node *new_node = node;
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
}
 
Node* replace(Node* head, int p1, int p2){
    /* write your code here */
}
 
Node* reverse(Node* head){
    /* write your code here */
}
 
void print(Node* head){
    Node* n = head;
    while (head != NULL) {
        cout << n->data << " ";
        head = n->next;
    }
}
 
Node* cyclic_left(Node* head, int x){
    /* write your code here */
}
 
public static <E> Vector<E> shifted(Vector<E> input, int amount) {
    if (input.isEmpty())
        return new Vector<>();
    int shift = (amount % input.size() + input.size()) % input.size();
    if (shift == 0)
        return new Vector<>(input);
    Vector<E> v = new Vector<>(input.size());
    v.addAll(input.subList(input.size() - shift, input.size()));
    v.addAll(input.subList(0, input.size() - shift));
    return v;
}

Node* cyclic_right(Node* head, int x){
   
}
 
int main(){
    Node* head = nullptr;
    while (true)
    {
        int command; cin >> command;
        if (command == 0){
            break;
        }else if(command == 1){
            int x, p; cin >> x >> p;
            head = insert(head, new Node(x), p);
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