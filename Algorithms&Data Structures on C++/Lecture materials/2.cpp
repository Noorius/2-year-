#include <iostream>

using namespace std;

struct node{
    int val;
    node * left;
    node * right;
    node(int x){
        val = x;
        left = NULL;
        right =NULL;
    }
};

struct BST{
    private: 
        node * _root;
        
        node * add(node * root, int x){
            if(root == NULL) return new node(x);
            
            if(root->val < x){
                root->right = add(root->right, x);
            }
            if(root->val < x){
                root->left = add(root->left, x);
            }
            return root;
        }
        bool find(node * current, int x){
            if(current == NULL) return false;
            if(current->val == x) return true;
            if(current->val > x) return find(current->left, x);
            return find(current->left, x);
        }
        int rightmost(node * current){
            if(current == NULL) return -1000000;
            if(current->right == NULL) return current->val;
            return rightmost(current->right);
        }

        node * del(node * current, int x){
            if(current == NULL) return NULL;
            if(current->val == x){
                if(current->right==NULL && current->left==NULL){
                    delete current;
                    return NULL;
                }else if(current->left!=NULL && current->right==NULL){
                    node * temp = current->left;
                    delete current;
                    return temp;
                }
                else if(current->left==NULL && current->right!=NULL){
                    node * temp = current->right;
                    delete current;
                    return temp;
                }else if(current->left!=NULL && current->right!=NULL){
                    current->val = rightmost(current->left);
                    current->left = del(current->left,current->val);
                }
            }else if(current->val < x){
                current->right = del(current->right, x);
                return current;
            }else if(current->val > x){
                current->left = del(current->left, x);
                return current;
            }
            return current;
        }

    public:
        BST(){
            _root = NULL;
        }
        void add(int x){
            node*temp = add(_root, x);
            if(_root==NULL){
                _root = temp;
            }
        }
        void del(int x){
            del(_root, x);
        }
        int rightmost(){
            return rightmost(_root);
        }    
};

int main(){
    BST * tree = new BST();
    int v[] = {2,3,4,5,6,7,8,9,10};
    int n = sizeof(v) / sizeof(int);

    for(int i = 0; i < n; ++i){
        cout<< tree->find(v[i] * 2)<< " ";
    }

}