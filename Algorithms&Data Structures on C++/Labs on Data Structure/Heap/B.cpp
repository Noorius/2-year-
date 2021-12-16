#include <bits/stdc++.h>
#include <iostream>

using namespace std;

struct maxHeap{
    int size,cap;
    int * a;

    maxHeap(){
        size = 0;
        cap=100;
        a = new int[cap];
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
        int* temp;
        if(size==cap){
            temp = new int[2*cap];
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

    void add(int x){
        enlargeCheck();
        a[size] = x;
        heapifyUp(size);
        size++;
    }

    int pop(){
        if(size==0) return -1;
        int removable = a[0];
        a[0] = a[size-1];
        size--;
        heapifyDown(0);
        return removable;
    }

    int heapifyUp(int i){
        while(i>0 and a[parentindex(i)]<a[i]){
            swap(parentindex(i),i);
            i = parentindex(i);
        }
        return i+1;
    }

    void heapifyDown(int i){
        if(!hasleft(i)){
            cout<<i+1<<endl;
            return;
        }
        //while(hasleft(i)){
            int c1 = lchildindex(i);
            int c2 = rchildindex(i);
            int small = c1;

            if(c2<size and a[c2] > a[c1]){
                small = c2;
            }
            if(a[i]<a[small]){
                //cout<<small+1<<endl;
                swap(i,small);
                heapifyDown(small);
                //i = small;
            }else if(a[i]>a[small]){
                cout<<i+1<<endl;
                return; //break;
            }
        //}
    }

    void print(){
        for (int i=0; i<size; i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
    int n;
    maxHeap h;
    cin>>n;
    for(int i = 0,l; i < n; i++){
        cin>>l;
        h.add(l);
    }
    int comm;
    cin>>comm;
    for(int i = 0,j,k; i < comm; i++){
        cin>>j>>k;
        h.a[j-1]-=k;
        h.heapifyDown(j-1);
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