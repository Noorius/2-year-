#include <bits/stdc++.h>

#define ll long long

using namespace std;

int f(string s){
    vector<string> pr;
    vector<string> sf;
    

    for(int i=0;i<s.length()-1; i++){
        pr.push_back(s.substr(0,i+1));
        sf.push_back(s.substr(s.size()-i-1,i+1));
    }
    for(int i=s.size()-2;i>=0; i--){
        if(pr[i]==sf[i])
            return pr[i].size();
    }
    return 0;
}

//n^3
vector<int> f1(string s){
    int n=s.size();
    vector<int> pi(n);
    for(int i = 1; i<n; i++){
        for(int k=0; k<=i; k++){
            if(s.substr(0,k)==s.substr(i-k+1,k))
                pi[i]=k;
        }
    }
    return pi;
}

vector<ll> f2(string s){
    ll n=s.size();
    vector<ll> pi(n);
    for(ll i = 1; i<n; i++){
        ll j = pi[i-1];    
        while(j>0 and s[i]!=s[j]){
            j = pi[j-1];
        }
        if(s[i]==s[j]) j+=1;
        pi[i] = j;
    }
    return pi;
}

/*bool finder(string t, string a, vector<int> pi){
    int l, k = l = 0;
    while(true){
        if(t[k]==a[l]){
            k++; l++;
            if(l==a.size()){
                return true;
            }
        }else{
            if(l==0){
                k++;
                if(k==t.length())
                    return false;
            }   
            else{
                l = pi[l - 1];
            }
        }
    }
}*/

int main(){
    /*freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);*/
    ll n;
    cin>>n;
    

    for(ll i=0; i<n; i++){
        string s, ls = "";
        ll num;
        cin>>s>>num;

        vector<ll> pr_p = f2(s);
        ll maxi = pr_p[s.length()-1];//*max_element(pr_p.begin(), pr_p.end());

        string sub = s.substr(maxi, s.length()-maxi);
        

        /*for(ll j=0; j<(num*s.size()); j++){
            ls+=sub;
        }*/

        //vector<ll> pi = f2(s+"#"+ls);

        cout<<(sub.length()*num)+maxi<<endl;

        /*for(auto c : pi){
            cout<<c<<" ";
        }
        cout<<endl;*/

        /*ll cnt = 0;
        ll f_i = -1;
        for(ll i=s.length()+1; i<pi.size(); i++){
            if(f_i==-1 and pi[i]>0)
                f_i = i;
            if(pi[i]==s.length())
                cnt++;
            if(cnt==num){
                if(f_i!=-1)
                    cout<<i-f_i+1<<endl;
                else
                    cout<<i-s.length()+1<<endl;
                break;
            }
            
        }*/
        /*int n = ls.length();
        int t = n - pi[n-1];

        if(n % t !=0)
            cout<<1<<endl;
        else{
            cout<< n / t<<endl;
        }*/
    }
    /* 
    if(finder(s, t, pi)){
        cout<<"Found";
    }else{
        cout<<"Not found";
    }
    */

    
    return 0;
}