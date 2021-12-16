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

    int add(long x){
        //enlargeCheck();
        int i = size++;
        a[i] = x;
        heapifyUp(i);
    }

    void heapifyUp(int i){
        int p = parentindex(i);
        while(i and a[p]>a[i]){
            swap(i,parentindex(i));
            i = p;
            p = parentindex(i);
        }
    }
    
    int pop(){
        long removable = a[0];
        swap(0,size-1);
        size--;
        heapifyDown(0);
        return removable;
        //cout<<res<<" "<<removable<<endl;
    }

    void heapifyDown(int i){
        if(size==0){
            return;
        }
        if(!hasleft(i)){
            return;
        }
        int c1 = lchildindex(i);
        int c2 = rchildindex(i);
        int minChildIndex=c1;

        if(hasright(i))
            if(a[minChildIndex]>a[c2])
                minChildIndex=c2;
        if(a[i]<a[minChildIndex]){
            return;
        }
        if(a[i]>a[minChildIndex]){
            swap(i,minChildIndex);
            heapifyDown(minChildIndex);
        }
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
    int pop2(){
        long removable = a[0];
        swap(0,size-1);
        size--;
        Build_Heap2(0);
        return removable;
        //cout<<res<<" "<<removable<<endl;
    }

    void Build_Heap2(int i){
         if(size==0){
            return;
        }
        if(!hasleft(i)){
            return;
        }
        int c1 = lchildindex(i);
        int c2 = rchildindex(i);
        int maxChildIndex=c1;

        if(hasright(i))
            if(a[maxChildIndex]<a[c2])
                maxChildIndex=c2;
        if(a[i]>a[maxChildIndex]){
            return;
        }
        if(a[i]<a[maxChildIndex]){
            swap(i,maxChildIndex);
            heapifyDown(maxChildIndex);
        }
    }

};

int main(){
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
    long n;
    cin>>n;
    maxHeap h(n),sorted(n);
    for(long i = 0,num; i < n; i++){
        cin>>num;
        sorted.add(num);
        h.a[i] = num;
        h.size++;
    }
    for(long i = h.getsize()-1; i >= 0; i--){
        h.Build_Heap2(i);
    }
    h.print();
    for(long i = 0; i < n-1; i++){
        h.pop2();
        h.print();
    }
    for(long i = 0; i < n; i++){
        cout<<sorted.pop()<<" ";
    } 
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