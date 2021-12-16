#include <bits/stdc++.h>

using namespace std;

#define NMAX 100000+1
int n,m;

int solution(int *A) {
    vector<int> P;
    int min = 20000 ;
    int dif = 0 ;
    P.resize(n+1);
    P[0] = 0;
    for(int i = 1 ; i < P.size(); i ++)
    {
        P[i] = P[i-1]+A[i-1];

    }
    sort(P.begin(),P.end());
    for(int i = 1 ; i < P.size(); i++)
    {
         dif = P[i]-P[i-1];
         if(dif<min)
         {
             min = dif;
         }
    }
    return min;
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    
    cin>>n>>m;
    int a[n];
    int p[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    p[0] = 0;
    for(int i=1; i<n+1; i++){
        p[i] = p[i-1] + a[i-1];
    }
    /*p[0] = a[0];
    for(int i=1; i<n; i++){
        p[i] = p[i-1] + a[i];
    }
    cout<<solution(a);
    return 0;*/

    sort(p, p+n+1);

    int mini = INT_MAX;
    for(int i=1; i<n+1; i++){
        int minimal = p[i] - p[i-1];

        if(mini > minimal){
            mini = minimal;
        }
    }
    cout<<mini;

    return 0;
}

//g++ -std=c++11 A.cpp