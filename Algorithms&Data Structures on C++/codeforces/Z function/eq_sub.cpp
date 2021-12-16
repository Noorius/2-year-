#include <bits/stdc++.h>

using namespace std;

int cnt(string s, string sub){
    int pos = 0, n = 0;
    while((pos=s.find(sub, pos))!=string::npos){
        ++n;
        pos += sub.length();
    }
    return n;
}

int isPalindrom(string s){
    string s2, s3;
    int n = 0;
    for(int i=0, j=s.length(); i<=s.length(); i++,j--){
        s2 = s.substr(0,i);
        s3 = s.substr(j,i);
        
        if(s2!=s3) {
            n+=cnt(s,s2) + cnt(s,s3);
            //cout<<s2<<" "<<s3<<" "<<n<<endl;
        }
            
    }
    return n;
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        cout<<isPalindrom(s)<<endl;
    }


    return 0;
}

//g++ -std=c++11 A.cpp