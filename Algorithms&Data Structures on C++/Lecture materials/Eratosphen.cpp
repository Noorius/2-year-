#include <iostream>
using namespace std;
const int N = (int)2e5 + 5;


int n;
bool is_composite[N];
int main(){
    cin>> n;
    is_composite[1] = 1;
    for(int i=2; i * i <=n; i++){
        if(!is_composite[i]){
            for(int j = i*i; j<=n; j+=i)
                is_composite[j] = 1;
        }
    }
    for(int i=1; i<=n; i++){
        if(!is_composite[i])
            cout<<i<<" ";
    }

    return 0;
}
