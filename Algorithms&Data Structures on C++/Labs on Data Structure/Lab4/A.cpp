#include <bits/stdc++.h>
#include <iostream>

using namespace std;

struct node{
    int data;
    node* left;
    node* right;
    node(int newVal){
        data=newVal;
        left = NULL;
        right = NULL;
    }
};

struct bst{
    private:
        node * _root;
        int cnt;

        node* insert(node* current, int data){
            if(current == NULL)
                return new node(data);
            else if(data<current->data){
                current->left = insert(current->left,data);
            }else if(data>current->data){
                current->right = insert(current->right,data);
            }
            return current;
        }
        bool find(node * current, int x){
            if(current == NULL) return false;
            if(current->data==x) return true;
            if(current->data > x) return find(current->left,x);
            return find(current->right, x);
        }
        void print(node * current, int level){
            if(current!=NULL){
                print(current->left,level+1);
                cout<<current->data<<" "<<level<<endl;
                print(current->right,level+1);
            }
        }
        int rightmost(node * current){
            if(current==NULL) return -1;
            if(current->right==NULL) return current->data;
            return rightmost(current->right);
        }
        int leftmost(node * current){
            if(current==NULL) return -1;
            if(current->left==NULL) return current->data;
            return leftmost(current->left);
        }
        node* del(node * current, int x){
            if(current == NULL) return NULL;
            if(current->data==x){
                if(current->left==NULL and current->right==NULL){
                    delete current;
                    return NULL;
                }else if(current->left!=NULL and current->right==NULL){
                    node * temp = current->left;
                    delete current;
                    return temp;
                }else if(current->right!=NULL and current->left==NULL){
                    node * temp = current->right;
                    delete current;
                    return temp;
                }else if(current->right!=NULL and current->left!=NULL){
                    current->data = rightmost(current->left);
                    current->left = del(current->left,current->data);
                }
            }else if(current->data < x){
                current->right = del(current->right,x);
                return current;
            }else if(current->data > x){
                current->left = del(current->left,x);
                return current;
            }
            return current;
        }
        int height(node * current){
            if(current==NULL) return 0;
            return max( height(current->left),height(current->right)) +1;
        }
        void size(node * current){
            if(current!=NULL){
                size(current->left);
                cnt++;
                size(current->right);
            }
        }
        int second_max(node * current){
            if(current->right!=NULL){
                node*temp = current;
                while(temp->right->right!=NULL){
                    temp = temp->right;
                }
                node * right = temp->right;
                if(right->left==NULL)
                    return temp->data;
                return rightmost(right->left);
            }else{
                return rightmost(current->left);
            }
        }
        void sortedBST(node * current){
            if(current!=NULL){
                sortedBST(current->left);
                cout<<current->data<<endl;
                sortedBST(current->right);
            }
        }
        void leaves(node * current){
            if(current!=NULL){
                leaves(current->left);
                if((current->left!=NULL and current->right==NULL) or (current->left==NULL and current->right!=NULL))
                    cout<<current->data<<endl;
                leaves(current->right);
            }
        }
        bool balanced(node * current){
            if(current==NULL) return true;
            return (abs(height(current->left)-height(current->right))<=1 and balanced(current->left) and balanced(current->right));
        }

    public:
        bst(){
            _root = NULL;
            cnt = 0;
        }
        void add(int x){
            node * res = insert(_root, x);
            if(_root==NULL)
                _root = res;
        }
        void del(int x){
            del(_root, x);
        }
        bool find(int x){
            return find(_root, x);
        }
        void print(){
            print(_root,0);
            cout<<endl;
        }
        void height(){
            int h = height(_root);
            if(h<=0)
                cout<<0;
            else
                cout<<h;
        }
        void size(){
            cnt=0;
            size(_root);
            cout<<cnt;
        }
        void second_max(){
            cout<< second_max(_root);
        }
        void sortedBST(){
            sortedBST(_root);
        }
        void leaves(){
            leaves(_root);
        }
        void balanced(){
            (balanced(_root)) ? cout<<"YES" : cout<<"NO";
        }

};


int main(){
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
    int n;
    bst * tree = new bst();
    while(cin>>n){
        if(n==0)
            break;
        tree->add(n);
    }
    tree->balanced();
    return 0;
}