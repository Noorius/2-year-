#include <bits/stdc++.h>
using namespace std;
 
struct Node {
  int value;
  int ans;
  Node *prev;
  Node(int x) {
    value = x;
    prev = NULL;
    ans = -1;
  }
};
 
struct Stack {
  private:
    Node *head = NULL;
    int sz = 0;
  public:
 
    int top() { 
      return head->value; 
    }
   
    void pop() {
      head = head->prev;
      sz--;
    }
 
    int size() { 
      return sz;
    }
 
    bool empty() { 
      return sz == 0; 
    }
 
    int push(int x) {
      Node * node = new Node(x);
      // write your code here 
      if(sz==0){
          head = node;
          sz++;
          return -1;
      }else{
          node->prev = head;
          head = node;
          sz++;
      }
      Node * temp = head;
      while(temp->prev!=NULL){
          if(head->value>=temp->prev->value){
              return temp->prev->value;
          }
          temp = temp->prev;
      }
      return -1;         
    }
 
}st;
 
int main() {
  int n;
  cin >> n;
  while (n--) {
    int x;
    cin >> x;
    cout << st.push(x) << " ";
  }
}