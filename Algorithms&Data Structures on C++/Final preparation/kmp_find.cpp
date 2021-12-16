#include <bits/stdc++.h>

using namespace std;

#define NMAX 100000+1

vector<int> pr(string s) {
	int n = s.length();
	vector<int> pi (n);
	for (int i=1; i<n; ++i) {
		int j = pi[i-1];
		while (j > 0 && s[i] != s[j])
			j = pi[j-1];
		if (s[i] == s[j])  ++j;
		pi[i] = j;
	}
	return pi;
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    string s, pat;
    cin>>s>>pat;
    s = pat+"$"+s;
    vector<int> p = pr(s);

	for(int i=0; i<p.size(); ++i) {
		if(p[i]==pat.length()){
            cout<<i-pat.length()-1-(pat.length()-1)<<" ";
        }
	}

    return 0;
}

//g++ -std=c++11 A.cpp