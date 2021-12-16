#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int n,cnt=0,m=1;
    cin>>n;
    while(m<n){
        m*=2;
        cnt++;
    }
    cout<<cnt;

    return 0;
}