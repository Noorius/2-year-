#include <bits/stdc++.h>

using namespace std;


int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    vector<int> z;
    vector<string> gr(27);

    string s = "a";
    for(int i=98; i<125; i++){
        s += (char(i) + s);
        cout<<s<<endl;
    }

    /*for(int i=1; i < n; i++){
        while(z[i]+i < n and s[z[i]+i] == s[z[i]]) //
            z[i]++;
    }
    
    for(int i=0; i < n; i++){
        cout<<z[i]<<" ";
    }*/

    return 0;
}

//g++ -std=c++11 A.cpp