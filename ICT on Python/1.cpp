#include <iostream>

using namespace std;

bool even(int n){
    int b = n;
    for(int i=2; i<n; i+=2){
        b = n;
        b-=i;
        if(b%2==0)
            return true;
    }
    return false;
}

int main(){
    int n;
    cin>>n;
    cout<<even(n);

    return 0;
}