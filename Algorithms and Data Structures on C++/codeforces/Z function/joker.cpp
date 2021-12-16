#include <bits/stdc++.h>

using namespace std;


bool equal(string s1, string s2){
    for(int j=0; j < s2.length(); j++){
        if(s1[j]!=s2[j] and s2[j]!='?')
            return false;
    }
    return true;
}

void isPalindrom(string s, string p){
    vector<int> vec;
    string sub;
    for(int i=0, j=0; i < s.length()-p.length()-1; i++, j++){
        if(s[i]!=p[j] and p[j]!='?'){
            j = 0;
            //continue;
        }
        else if(!(s[i]!=p[j] and p[j]!='?') and j==p.length()-1){
            cout<<s.substr(i,p.length())<<" "<<p<<endl;
            vec.push_back(i-p.length()+1);
            j = 0;
        }
    }
    cout<<vec.size()<<endl;
    for(int c : vec)
        cout<<c<<" ";
    cout<<endl;
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        string s, p;
        cin>>s>>p;
        if(s<p){
            cout<<0<<endl<<endl;
            continue;
        }
        //cout<<isPalindrom(s,p)<<endl;
        isPalindrom(s,p);
    }


    return 0;
}

//g++ -std=c++11 A.cpp