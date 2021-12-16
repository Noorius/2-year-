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

    void enlargeCheck(){
        long* temp;
        if(size==cap){
            temp = new long[2*cap];
            for(int i=0;i<cap;i++){
                temp[i]=a[i];
            }
            cap*=2;
            delete[] a;
            a = temp;
        }
    }

    void swap(int ind1, int ind2){
        int temp = a[ind1];
        a[ind1]=a[ind2];
        a[ind2]=temp;
    }

    void add(long x){
        //enlargeCheck();
        if(size>=cap){
            cout<<-1<<endl;
            return;
        }
        a[size] = x;
        cout<<heapifyUp(size)<<endl;
        size++;
    }

    int heapifyUp(int i){
        while(i>0 and a[parentindex(i)]<a[i]){
            swap(parentindex(i),i);
            i = parentindex(i);
        }
        return i+1;
    }
    
    int pop(){
        if(size==0) return -1;
        long removable = a[0];
        a[0] = a[size-1];
        size--;
        cout<<heapifyDown(0)<<" ";
        return removable;
    }

    int heapifyDown(int i){
        int result;
        if(size==0){
            return 0;
        }
        if(!hasleft(i)){
            return i+1;
        }
        int c1 = lchildindex(i);
        int c2 = rchildindex(i);
        int maxChildIndex=c1;

        if(hasright(i))
            if(a[maxChildIndex]<a[c2])
                maxChildIndex=c2;
        if(a[i]>a[maxChildIndex]){
            return i+1;
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
            cout<<h.pop()<<endl;
        }else if(op==2){
            cin>>num;
            h.add(num);
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