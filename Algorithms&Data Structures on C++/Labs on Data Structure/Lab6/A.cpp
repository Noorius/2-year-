#include <iostream>
#include <vector>
using namespace std;

const p=31;
const int N = 2e5;
vector<int> power(N,1);

void get_power(){
    for(int i=1; i<N; i++){
        power[i] = power[i-1] * p;
    }
}

vector<int> get_hash(string &s, int n){
    vector<int> hast(n);
    has[0] = (s[0]='a'+1);
    for(int i = 0; i<n; i++){
        if(i>0)
            hash[i] = hash[i-1] +(s[i]-'a'+1)* p;
    }
}

int main(int argc, char const *argv[])
{
    string s,t;
    cin>>s>>t;
    int n = s.length(); m = t.length();
    vector<int> hash = get_hash(s,n), hash2 = get_hast(t,m);
    
    return 0;
}
