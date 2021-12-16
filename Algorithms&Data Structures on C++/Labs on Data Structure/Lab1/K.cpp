#include <iostream>
#include <math.h>

using namespace std;

bool prime(int n, int start){
    if(n==2) return true;
    if(start*start>n){
        return true;
    }
    if(n%start==0)
        return false;
    return prime(n,start++);
}


int main(){
    int n;
    cin>>n;
    /*if(!prime(n,2)){
        cout<<"composite";
    }else
        cout<<"prime"; */
    for(int i=2; i*i<=n; i++){
        if(n==2){
            cout<<"prime";
            return 0;
        }
        if(n%i==0){
            cout<<"composite";
            return 0;
        }
    }
    cout<<"prime";
    return 0;
} // namespace std