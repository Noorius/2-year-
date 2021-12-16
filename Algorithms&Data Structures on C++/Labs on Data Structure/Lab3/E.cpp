#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int n,max=-1000000,min=1000000;
    cin>>n;
    int a[n];
    
    for(int i = 0; i<n; i++){
        cin>>a[i];
        if(a[i]>max)
            max=a[i];
        if(a[i]<min)
            min=a[i];
    }
    for(int i = 0; i<n; i++){
        if(a[i]==max)
            a[i]=min;
    }
    for(int i = 0; i<n; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}