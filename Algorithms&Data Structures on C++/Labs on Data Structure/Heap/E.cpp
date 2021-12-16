#include <bits/stdc++.h>
#include <iostream>

using namespace std;

struct maxHeap{
    int size,cap;
    long * a;

    maxHeap(long n){
        size = 0;
        cap=n;
        a = new long[n];
    }
    int peek(){
        return a[0];
    }

    int lchildindex(int p_i) { return 2*p_i+1;}
    int rchildindex(int p_i){return 2*p_i+2;}
    int parentindex(int ch_i){return ((ch_i-1)/2);}

    bool hasparent(int i){ return parentindex(i)>=0;}
    bool hasleft(int i){return lchildindex(i)<size;}
    bool hasright(int i){return rchildindex(i)<size;}

    void swap(int ind1, int ind2){
        int temp = a[ind1];
        a[ind1]=a[ind2];
        a[ind2]=temp;
    }

    void add(long x){
        //enlargeCheck();
        size++;
        int i = size - 1;
        a[i] = x;
        cout<<heapifyUp(i)+1<<endl;
    }

    int heapifyUp(int i){
        while(i>0 and a[parentindex(i)]>a[i]){
            swap(i,parentindex(i));
            i = parentindex(i);
        }
        return i;
    }
    
    void pop(){
        long removable = a[0];
        swap(0,size-1);
        size--;
        heapifyDown(0);
    }

    int heapifyDown(int i){
        int result;
        if(size==0){
            return 0;
        }
        if(!hasleft(i)){
            return i;
        }
        int c1 = lchildindex(i);
        int c2 = rchildindex(i);
        int maxChildIndex=c1;

        if(hasright(i))
            if(a[maxChildIndex]<a[c2])
                maxChildIndex=c2;
        if(a[i]>a[maxChildIndex]){
            return i;
        }
        if(a[i]<a[maxChildIndex]){
            swap(i,maxChildIndex);
            result=heapifyDown(maxChildIndex);
        }
        return result;
    }

    void print(){
        for (long i=0; i<size; i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    void del(int i){
        cout<<a[i]<<endl;
        swap(i,size-1);
        size--;
        heapifyDown(i);
        return;
    }
    int getsize(){
        return size;
    }

};

int main(){
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
    long n,m;
    cin>>n>>m;
    maxHeap h(n);
    for(long i = 0,op,num; i < m; i++){
        cin>>op;
        if(op==1){
            if(h.getsize()==0){ cout<<-1<<endl; continue;}
            pair<int,int> res = h.pop();
            cout<<res.first<<" "<<res.second<<endl;
        }else if(op==2){
            cin>>num;
            if(h.getsize()==n){cout<<-1<<endl;continue;}
            h.add(num);
        }else if(op==3){
            cin>>num;
            if(num>h.getsize() or num<1) {cout<<-1<<endl;continue;}
            h.del(num-1); 
        }
    }
    h.print();
    return 0;
}

/* while(hasleft(i)){
            int small = lchildindex(i);
            if(hasright(i) and a[rchildindex(i)] < a[lchildindex(i)]){
                small = rchildindex(i);
            }
            if(a[i]<a[small]){
                break;
            }else{swap(i,small);}
            i = small;
        } */