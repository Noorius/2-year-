#include <bits/stdc++.h>

using namespace std;

vector<long> res;
vector<long> ord;
long p;
long n,m;

long shift_left(long num){
    int e = num % 10;
    int d = (num/10)%10;
    int s = (num/100)%10;
    int t = (num/1000)%10;

    return s*1000+d*100+e*10+t;
}

long shift_right(long num){
    int e = num % 10;
    int d = (num/10)%10;
    int s = (num/100)%10;
    int t = (num/1000)%10;

    return e*1000+t*100+s*10+d;
}

void show(long num){
    if(num==-1){
        //cout<<res[num]<<endl;
        return;
    }
    show(ord[num]);
    cout<<res[num]<<"\n";
}


int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    deque<long> q;
    
    cin>>n>>m;

    
    q.push_back(n);
    ord.push_back(-1);
    p = 0;

    while(!q.empty()){
        long i = q.front();
        q.pop_front();
        res.push_back(i);
        
        
        long p1=i+1000;
        long p2=i-1;
        long p3=shift_right(i);
        long p4=shift_left(i);
        
        if(p1==m or p2==m or p3==m or p4==m){
            q.clear();
            break;
        }
        
        if(p1<=9999){q.push_back(p1);ord.push_back(p);}
        if(p2%10!=0){q.push_back(p2);ord.push_back(p);}
        q.push_back(p3);ord.push_back(p);
        q.push_back(p4);ord.push_back(p);
        p++;
        
    }
    
    /*for(int i =0; i<p+1;i++)
        cout<<res[i]<<" "<<ord[i]<<endl;
    cout<<"-------------------------------------"<<endl;*/
    //show(p);
    int num = -2;
    while(num!=-1){
        cout<<res[p];
        
    }
    cout<<m<<endl;

    return 0;

}