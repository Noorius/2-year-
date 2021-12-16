#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void write(){
    string n1;
    vector<string> v;
    vector<string>::iterator it;
    while(cin>>n1){
        char k = n1[0];
        n1.erase(0,1);
        if(k=='+')
            v.push_back(n1);
        else{
            it = find(v.begin(),v.end(),n1);
            if(it!=v.end()){
                v.erase(it);
            }
            else{
                v.clear();
                v.push_back("ERROR");
                break;
            }
        }

    }
    if(v.empty()){
        v.push_back("EMPTY");
    }
    sort(v.begin(),v.end());
    for(it=v.begin(); it!=v.end();it++){
        cout<<*it<<" ";
    }
    
        
}

int main(){
    
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
    write();

    return 0;
}