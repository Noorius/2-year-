#include <iostream>

using namespace std;

int main(){
    int n,max=-1000000,index=0;
    cin>>n;;
    for(int i = 0,j; i < n; i++){
        cin>>j;
        if(j>max){
            max=j;
            index=i+1;
        }
            
    }
    cout<<index;

    return 0;
}