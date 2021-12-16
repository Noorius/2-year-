#include <iostream>

using namespace std;

int nod(int n, int m){
    if(m==0 or n==0)
        return max(n,m);
    return nod(max(n,m)%min(n,m), min(n,m));
}


int main(){
    int n,m;
    cin>>n>>m;
    cout<<nod(n,m);
    return 0;
} // namespace std
