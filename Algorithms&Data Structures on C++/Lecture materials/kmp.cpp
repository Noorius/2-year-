#include <bits/stdc++.h>

using namespace std;

/*
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
*/

vector<int> f2(string s){
    int n=s.size();
    vector<int> pi(n);
    for(int i = 1; i<n; i++){
        int j = pi[i-1];    
        while(j>0 and s[i]!=s[j]){
            j = pi[j-1];
        }
        if(s[i]==s[j]) j+=1;
        pi[i] = j;
    }
    return pi;
}

/*
void finder(string t, string a, vector<int> pi){
    
    int l, k = l = 0;
    vector <int> ans;
    while(k!=t.length()){
        if(t[k]==a[l]){
            l++; k++; 
            if(l==a.size()){
                ans.push_back(k-a.size()+1);
            }
        }else{
            if(l==0){
                k++;
                if(k==t.length())
                    break;
            }   
            else{
                l = pi[l - 1];
            }
        }
    }
    if(ans.empty()){
        cout<<"Not Found"<<'\n';
        cout<<'\n';
        return;
    }
    cout<<ans.size()<<"\n";
    for(int c : ans){
        cout<<c<<" ";
    }
    cout<<'\n';
    cout<<'\n';
}


int f2(string s){
    int n=s.size(), maxi = 0;
    vector<int> pi(n);
    for(int i = 1; i<n; i++){
        int j = pi[i-1];    
        while(j>0 and s[i]!=s[j]){
            j = pi[j-1];
        }
        if(s[i]==s[j]) j+=1;
        pi[i] = j;
        maxi = max(maxi,pi[i]);
    }
    return maxi;
}

vector<int> f3(string s){
    int n = s.size();
    vector<int> pr(1+n);
    pr[1] = 0;
    int len = 0;
    for(int i = 1; i<s.size(); i++){
        while(true){
            if(s[len]==s[i]){
                len++;
                break;
            }
            if(len==0){
                break;
            }
            len = pr[len];
        }
        pr[i+1] = len;
    }
    return pr;

}*/

int main(){


    /*int n;
    string s, t;
    vector<int> pi;
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>s>>t;
        pi = f2(s);
        finder(s, t, pi);
    } 
    */
    string s;
    while(true){
        cin>>s;
        if(s==".")
            break;
        vector<int> res = f2(s);
        int n = res.size();
        int t = n - res[n-1];
        if(n%t != 0){
            cout<<1<<"\n";
        }else{
            cout<<n/t<<"\n";
        }
    }
    /*
    #3
    int rep;
    cin>>rep;

    while(rep>0){
       string s ,t;
        cin>>s;
        int n = s.size(), cnt = 0;
        for(int i=0; i<n; i++){
            t += s[i];
            reverse(t.begin(),t.end());
            cnt += t.length() - f2(t);
            reverse(t.begin(),t.end());
        }
        cout<<cnt<<'\n'; 
        rep--;
    }

    string s;
    cin>>s;
    vector<int> res = f3(s);
    for(int i=1; i<=s.size();i++)
        cout<<res[i]<<" ";
    */
    return 0;
}