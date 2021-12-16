#include <bits/stdc++.h>

using namespace std;
int main() {
    int n,m;
    deque<int> q;

    cin>>n;
    
    int e = n % 10;
    int d = (n/10)%10;
    int s = (n/100)%10;
    int t = (n/1000)%10;

    cout<<s*1000+d*100+e*10+t<<endl;
    cout<<e*1000+t*100+s*10+d;

    return 0;

}