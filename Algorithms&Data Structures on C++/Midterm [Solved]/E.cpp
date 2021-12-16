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
            }else if(data>=current->data){
                current->right = insert(current->right,data);
            }
            return current;
        }
        /* bool find(node * current, int x){
            if(current == NULL) return false;
            if(current->data==x) return true;
            if(current->data > x) return find(current->left,x);
            return find(current->right, x);
        }
        void print(node * current, int level){
            if(current!=NULL){
                print(current->left,level+1);
                cout<<current->data<<" ";
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
            if((current->right==NULL and current->left!=NULL) or (current->right!=NULL and current->left==NULL))
                return 1;
            return min(height(current->left),height(current->right)) + 1;
        } */
        void triangle(int n,int& sum, node * current){
            if(current!=NULL){
                triangle(n,sum,current->left);
                //cout<<height_left(current)<<" "<<height_right(current)<<" n is "<<n<<endl;
                if(height_left(current)==height_right(current) and height_left(current)>=n)
                    sum++;
                triangle(n,sum,current->right);
            }
        }
        int height_left(node * current){
            int cnt=1;
            while(current->left!=NULL){
                cnt++;
                current = current->left;
            }
            return cnt;
        }
        int height_right(node * current){
            int cnt=1;
            while(current->right!=NULL){
                cnt++;
                current = current->right;
            }
            return cnt;
        }
        /* void size(node * current){
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
        int second_mini(node * current){
            if(current->left!=NULL){
                node*temp = current;
                while(temp->left->left!=NULL){
                    temp = temp->left;
                }
                return temp->data;
            }else{
                return current->right->data;
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
        } */

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
        /* void del(int x){
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
        } */
        void triangle(int n){
            for(int i=2; i<=n; i++){
                int sum = 0;
                triangle(i,sum, _root);
                //cout<< triangle(i,sum, _root)<<" ";
                cout<<sum<<" ";
            }
        }
        /* int size(){
            cnt=0;
            size(_root);
            return cnt;
        }
        int second_max(){
            return second_max(_root);
        }
        int second_mini(){
            return second_mini(_root);
        }
        int mini(){
            return leftmost(_root);
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
        bool one_el(){
            return _root->left==NULL and _root->right==NULL;
        } */

};


int main(){
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    bst * tree = new bst();
    for(int i=0,num; i<n; i++){
        cin>>num;
        tree->add(num);
    }
    tree->triangle(n);

    return 0;
}