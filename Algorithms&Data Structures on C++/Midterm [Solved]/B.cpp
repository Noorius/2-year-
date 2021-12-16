#include <bits/stdc++.h>
#include <iostream>

using namespace std;

struct maxHeap{
    long long size,cap;
    long long * a;

    maxHeap(long n){
        size = 0;
        cap=n;
        a = new long long[n];
    }

    int lchildindex(long long p_i) { return 2*p_i+1;}
    int rchildindex(long long p_i){return 2*p_i+2;}
    int parentindex(long long ch_i){return ((ch_i-1)/2);}

    bool hasparent(long long i){ return parentindex(i)>=0;}
    bool hasleft(long long i){return lchildindex(i)<size;}
    bool hasright(long long i){return rchildindex(i)<size;}

    void swap(long long ind1, long long ind2){
        long long temp = a[ind1];
        a[ind1]=a[ind2];
        a[ind2]=temp;
    }

    void add(long long x){
        long long i = size++;
        a[i] = x;
        heapifyUp(i);
    }

    void heapifyUp(long long i){
        if(i == 1) return;
        long long p = parentindex(i);
        while(i>0 and a[p]>a[i]){
            swap(i,parentindex(i));
            i = p;
            p = parentindex(i);
        }
    }
    
    long long pop(){
        long long removable = a[0];
        swap(0,size-1);
        size--;
        heapifyDown(0);
        return removable;
        //cout<<res<<" "<<removable<<endl;
    }

    void heapifyDown(long long i){
        if(size==0){
            return;
        }
        if(!hasleft(i)){
            return;
        }
        long long c1 = lchildindex(i);
        long long c2 = rchildindex(i);
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

    int getsize(){
        return size;
    }

};

int main(){
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
    long long n;
    cin>>n;
    maxHeap sorted(n);
    for(long long i = 0,num; i < n; i++){
        cin>>num;
        sorted.add(num);
    }
    long long sum=0;
    for(long long i = 0; sorted.getsize()!=1; i++){
        long long num1 = sorted.pop() + sorted.pop();
        sorted.add(num1);
        sum += num1;
    }
    cout<<sum;
    return 0;
}