#include <iostream>

using namespace std;

bool h(string str, string pattern){
    long long n = str.length();
    long long h[n];
    long long p[n];
    long long q = (1<<30)+1;

    p[0] = 1;
    for (long long i=1; i<n; ++i){
        p[i] = (p[i-1] * 31)%q;
    }

    for (long long i=0; i<str.length(); ++i){
        h[i]= ((str[i]-'a' + 1) * p[i])%q;
        if(i>0){
            h[i] += h[i-1];
        }
        h[i]%=q;
    }
    long long ph = 0;
    long long m = pattern.length();
    for (long long i=0; i<m; ++i){
        ph=(ph+((pattern[i]-'a'+1)*p[i])%q)%q;
    }

    bool res = false;
    for (long long i=0; i + m - 1 < n; ++i){
        long long j = i+m-1;
        long long cur = h[j];
        if(i>0){
            cur -= h[i-1];
        }
        
        if((ph * p[i])%q == cur){
            /*bool found = true;
            for(int k= i; i<=j; k++){
                if(str[i] != pattern[k-i]){
                    found = false;
                    break;
                }
            } */
            /*if(str.substr(i,m)==pattern){
                res = true;
                break;
            } */
            cout<<i<<" ";
            break;
        }
    }
    return res;
}

int main(){
    string str, patt;
    cin>>str>>patt;

    patt+=patt;

    h(patt,str);

    return 0;
}