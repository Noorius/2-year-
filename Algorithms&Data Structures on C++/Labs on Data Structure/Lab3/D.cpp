#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int n;
    set<int> s;
    cin>>n;
    for(int i = 0,j; i<n; i++){
        cin>>j;
        s.insert(j);
    }
    for(set<int>::reverse_iterator it = s.rbegin(); it!=s.rend(); it++){
        if(it==s.rbegin())
            continue;
        cout<<*(it);
        break;
    }
    return 0;
}