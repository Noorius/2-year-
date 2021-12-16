#include <bits/stdc++.h>
#include <iostream>

using namespace std;

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

int bs(int arr[],int l, int r, int x){
    if(l>r) return -1;
    int m = l+(r-l)/2;
    if(arr[m]==x) return m;
    if(arr[m]>x) return bs(arr,l,m-1,x);
    return bs(arr,m+1,r,x);
}

int main(){
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int a[n],c[n];
    for(int i = 0,l; i<n; i++){
        cin>>l;
        a[i] = l;
        c[i] = l;
    }
    //merge(a,0,n-1);

    int row,col;
    cin>>row>>col;
    int b[row][col];
    for(int i=0; i<row;i++){
        for(int j=0; j<col; j++){
            cin>>b[i][j];
            /*int index = bs(a,0,col-1,b[i][j]);
            if(index!=-1){
                cout<<i<<" "<<j<<"\n";
            } */
        }
    }
    bool found = false;
    for(int ind = 0,l; ind<n; ind++){
        for(int i=0; i<row;i++){
            if(found) break;
            for(int j=0; j<col; j++){
                if(found) break; 
                if(a[ind]==b[i][j]){
                    cout<<i<<" "<<j<<"\n";
                    found = true;
                }
            }
        }
        if(!found) cout<<-1<<"\n";
        else found = false;
    }
    return 0;
}