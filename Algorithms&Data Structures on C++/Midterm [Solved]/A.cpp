#include <iostream>

#define For(i, n)           for(int i = 0; i < n; ++i)

using namespace std;

long rows, col;

struct array{
    long * a = new long[col];
    long index = 0;
    array(){
    } 
    void add(int x){
        a[index] = x;
        index++;
    }
    long sum(){
        long sum = 0;
        for(int i =0; i<col; i++)
            sum+=a[i];
        return sum;
    }
    friend bool operator<(array &a,  array&b){
        if(a.sum() > b.sum())
            return true;
        if(a.sum() < b.sum())
            return false;
        for(int i = 0; i<col; i++){  // 1 2 3 
            if(a.a[i]<b.a[i])        // 1 2 3 
                return true;
            if(a.a[i]>b.a[i])
                return false;
        }
        return false;
    }
    void print(){
        for(int i = 0; i<col; i++)
            cout<<a[i]<<" ";
        cout<<endl;
    }
};

template <typename T>
void mergetogether(T a[],int left, int right){
    int leftEnd = left+(right-left)/2; // m
    int rightStart = leftEnd+1; //m+1
    
    int a1_size = leftEnd - left + 1;
    int a2_size = right - rightStart + 1;
    T L[a1_size], R[a2_size];

    for(int i = 0; i<a1_size; i++){
        L[i] = a[left+i];
    }
    for(int i = 0; i<a2_size; i++){
        R[i] = a[rightStart+i];
    }

    int a_i = left, l_i = 0, r_i = 0;
    while(l_i < a1_size and r_i < a2_size){ // 1 2 3  /left
        if(L[l_i]<R[r_i]){                  // 2 4 5  /right
            a[a_i] = L[l_i];
            l_i++;
        }else{
            a[a_i] = R[r_i];
            r_i++;
        }
        a_i++;
    }
    while(l_i < a1_size){
        a[a_i] = L[l_i];
        a_i++;
        l_i++;
    }
    while(r_i < a2_size){
        a[a_i] = R[r_i];
        a_i++;
        r_i++;
    }
}

template <typename T>
void merge(T a[], int l, int r){
    if(l>=r)
        return;
    int m =l+(r-l)/2;
    merge(a,l,m);
    merge(a,m+1,r);
    mergetogether(a,l,r);
} 

int main(){
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
    
    cin>>rows>>col;
    array a[rows];
    for(long i = 0; i<rows; i++){
        for(long j=0, num; j<col; j++){ //[array1, array2, array3]  // array [1, 2, 3]
            cin>>num;
            a[i].add(num);
        }
    }
    merge(a,0,rows-1);

    for(long i = 0; i<rows; i++){
        a[i].print();
    }

    return 0;
}