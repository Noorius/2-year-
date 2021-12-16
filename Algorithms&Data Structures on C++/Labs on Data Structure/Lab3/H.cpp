#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int bs(int arr[],int l, int r, int x){
    pair<int,int> p(-1,-1);
    while(l<=r){
        int m = l+(r-l)/2;
        if(arr[m]==x){
            return m;
        }
        else if(arr[m]<x)
            l = m+1;
        else
            r = m-1;
    }
    return -2;
}

int main(){
    int n,m;
    cin>>n>>m;
    int a[n];
    vector<pair<int,int> >v;

    for(int i=0;i<n; i++)
        cin>>a[i];

    for(int i=0,j,l,r;i<m; i++){
        cin>>j;
        int middle = l = r = bs(a,0,n-1,j);
        if(middle>=0){
            for(int k=middle-1; k>=0; k--){
                if(a[k]==j)
                    l=k;
            }
            for(int k=middle+1; k<n; k++){
                if(a[k]==j)
                    r=k;
            }
        }
        v.push_back(make_pair(min({middle,l,r})+1,max({middle,l,r})+1));
    }
    for(auto it : v){
        if(it.first<1 && it.second<1)
            cout<<0<<endl;
        else
            cout<<it.first<<" "<<it.second<<endl;
    }
        

    return 0;
}