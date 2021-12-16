#include <bits/stdc++.h>
#include <iostream>

#define For(i, n)           for(int i = 0; i < n; ++i)

using namespace std;

struct woman{
    int weight, height, boobs;

    friend bool operator<(woman &a, woman &b){
        if(a.weight < b.weight)
            return true;
        else return false;
        if(a.height > b.height)
            return true;
        else return false;
        if(a.boobs > b.boobs)
            return true;
        else return false;
        return false;
    }
};


template <typename T>
void mergetogether(T a[],int left, int right){
    int leftEnd = left+(right-left)/2;
    int rightStart = leftEnd+1;
    
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
    while(l_i < a1_size and r_i < a2_size){
        if(L[l_i]<R[r_i]){
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
    //freopen("output.txt", "w", stdout);
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    woman a[n];

    For(i,n){
        a[i].weight = rand() % 150 + 1;
        a[i].height = rand() % 200 +1;
        a[i].boobs = rand() % 10 + 1;
    }
        
    merge(a, 0, n-1);

    For(i,n)
        printf("%d %d %d\n", a[i].weight, a[i].height,a[i].boobs);
    return 0;
}