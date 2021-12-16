#include <iostream>

using namespace std;

int h(string str){
    int p = 31;
    int s=0, q = 1e+9 + 7;
    for (int i=0; i<str.length(); ++i){
        s=s+((str[i]-'a' + 1)*p)%q;
        p=(p*31)%q;
    }
    return s;
}

int main(){
    string str;
    cin>>str;

    cout<<h(str);

    return 0;
}