#include <iostream>
#include <algorithm>

using namespace std;

struct node{
    node * prev;
    string data;
    int cnt;
    node(string newData){
        data=newData;
        prev = NULL;
        cnt=1;
    }
};

struct WordStack{
    node * tail;

    WordStack(){
        tail=NULL;
    }

    void push(string newData){
        node * item = new node(newData);
        if(tail==NULL){
            tail=item;
            return;
        }
        if(tail->data > item->data){
            item->prev = tail;
            tail = item;
            return;
        }
        if(tail->data==item->data){
            tail->cnt++;
            return;
        }
        node * temp = tail;
        while(temp->prev && temp->prev->data <= item->data){
            if(temp->prev->data == item->data){
                temp->prev->cnt++;
                return;
            }
            temp = temp->prev;
        }
        node * prev = temp->prev;
        temp->prev = item;
        item->prev = prev;
    }
    void show(){
        node * cur = tail;
        while(cur){
            cout<<cur->data<<" "<<cur->cnt<<endl;
            cur = cur->prev;
        }
    }
    
};

struct CountStack{
    node * tail;

    CountStack(){
        tail=NULL;
    }
    void push(node* newNode){
        if(tail==NULL){
            tail=newNode;
            return;
        }
        if(newNode->cnt > tail->cnt){
            newNode->prev = tail;
            tail = newNode;
            return;
        }
        node* temp = tail;
        while(temp->prev && temp->prev->cnt >= newNode->cnt){
            temp=temp->prev;
        }
        node * node = temp->prev;
        temp->prev = newNode;
        newNode->prev = node;
    }
    void show(){
        node * cur = tail;
        while(cur){
            cout<<cur->data<<" "<<cur->cnt<<endl;
            cur = cur->prev;
        }
    }
};

string delSpaces(string str1) 
{
    string s = ".,:;!?";
    for(int i=0; i<s.size();i++){
        str1.erase(remove(str1.begin(), str1.end(), s[i]), str1.end());
    }
    string str2 = "";
    for(int i=0; i<str1.size();i++){
        str2+=char(tolower(str1[i]));
    }
    return str2;
}

void write(){
    string n;
    WordStack st1;
    CountStack st2;
    while(cin>>n){
        st1.push(delSpaces(n));
    }
    //st1.show();
    node*cur = st1.tail;
    while(cur){
        node * temp = new node(cur->data);
        temp->cnt = cur->cnt;
        st2.push(temp);
        cur = cur->prev;
    }
    st2.show();
}

int main(){
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
    write();
    return 0;
}

