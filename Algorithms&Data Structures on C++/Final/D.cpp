#include <bits/stdc++.h>
#include <iostream>

using namespace std;

vector<int> pr;

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
        
        int height1(node * current){
            queue<node*> q;
            q.push(current);
            q.push(NULL);
            while(!q.empty()){
                node * temp = q.front();
                q.pop();
                if(temp==NULL)
                    cnt++;
                if(temp!=NULL){
                    if(temp->left)
                        q.push(temp->left);
                    if(temp->right)
                        q.push(temp->right);
                }else if(!q.empty()){
                    q.push(NULL);
                }
            }
            return cnt;
        }
        int height(node * current){
            if(current==NULL) return 0;
            //int leftheight = height(current->left);
            //int rightheight = height(current->right);
            //if(leftheight>rightheight) 
            //    return leftheight+1;
            //else 
            //    return rightheight+1;
            return max( height(current->left),height(current->right)) +1;
        }

        void p(node * current){
            if(current!=NULL){
                p(current->left);
                pr.push_back(height(current->left)+height(current->right)+1);
                p(current->right);
            }
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
        int height(){
            int h = height(_root);
            if(h<=0)
                return 0;
            else
                return h;
        }
        void p(){
            p(_root);
        }

};


int main(){
    /*freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);*/
    int n;
    cin>>n;
    bst * tree = new bst();
    for(int i = 0, l; i < n; i++){
        cin>>l;
        if(!tree->find(l)){
            tree->add(l);
        }    
    }
    tree->p();
    
    sort(pr.rbegin(),pr.rend());
    cout<<pr[0];
    
    return 0;
}