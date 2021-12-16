#include <bits/stdc++.h>

using namespace std;

#define NMAX 100000+1

struct st{
    private:
        int *a;
        int top;

    public:
    st(int n){
        a = new int[n];
        top = -1;
    }
    int back(){
        if(top==-1) return -1;
        else return a[top];
    }

    void push(int x){
        a[++top] = x;
    }
    int pop(){
        if(top!=-1){
            top--;
            return a[top+1];
        }
    }
    int size(){
        return top+1;
    }
    void clear(){
        top = -1;
    }
};

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    string com;
    st stack = st(100);
    while(com!="exit"){
        cin>>com;
        if(com=="push"){
            int x; cin>>x;
            stack.push(x); cout<<"ok\n";
        }
        else if(com=="size") cout<<stack.size()<<"\n";
        else if(com=="clear") { stack.clear(); cout<<"ok\n";}
        else if(com=="back") cout<<stack.back()<<"\n";
        else if(com=="pop") cout<<stack.pop()<<"\n";
    }
    cout<<"bye";

    return 0;
}

//g++ -std=c++11 A.cpp