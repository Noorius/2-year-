#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int n,m,min[800],max[800];
    cin>>n>>m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int input;
            cin>>input;
            if(i==0) max[j]=input;
            else if(max[j]<input) max[j]=input;
            if(j==0) min[i]=input;
            else if(min[i]>input) min[i]=input;
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
            if(min[i]==max[j]) cnt++;
    
    cout<<cnt;
    return 0;
}