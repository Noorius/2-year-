#include <bits/stdc++.h>
#include <iostream>

using namespace std;

bool bs(int arr[],int l, int r, int x){
    if(l>r) return false;
    int m = l+(r-l)/2;
    if(arr[m]==x) return true;
    if(arr[m]>x) return bs(arr,l,m-1,x);
    return bs(arr,m+1,r,x);
}

int main(){
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n; i++)
        cin>>a[i];
    for(int i=0,j;i<k; i++){
        cin>>j;
        if(bs(a,0,n-1,j))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
        

    return 0;
}