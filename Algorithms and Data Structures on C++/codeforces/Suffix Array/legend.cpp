#include <bits/stdc++.h>

using namespace std;

void countSort(vector<int> &p, vector<int> &c) {
    int n = p.size();
    vector<int> cnt(n);
    for (auto x : c) {
        cnt[x]++;
    }
    vector<int> pos(n);
    pos[0] = 0;
    for (int x = 1; x < n; x++) {
        pos[x] = pos[x - 1] + cnt[x - 1];
    }
    vector<int> p_new(n);
    for (auto x : p) {
        p_new[pos[c[x]]] = x;
        pos[c[x]]++;
    }
    p = p_new;
}

pair<vector<int>, vector<int> > computeSuffixArray(string s) {
    s += "$";
    int n = s.size();
    vector<int> pos(n), class_(n);
    // pos[i]: the i-th item's index, i.e., s[pos[i]:] is the i-th item in suffix
    // array
    // class_[i]: the equivalance class of s[i]
    {
        // k = 0
        vector<pair<char, int>> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = {s[i], i};
        }
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++) {
            pos[i] = a[i].second;
        }
        class_[pos[0]] = 0;
        for (int i = 1; i < n; i++) {
            class_[pos[i]] = class_[pos[i - 1]] + int(a[i - 1].first != a[i].first);
        }
    }
    int k = 0;
    while ((1 << k) < n && class_[pos[n - 1]] < n - 1) {  // for early termination
        // k -> k + 1
        for (int i = 0; i < n; i++) {
            // actually, this is the first counting sort of a radix sort
            //   class_[i] = class_[(pos[i] - (1 << k) + n) % n]
            pos[i] = (pos[i] - (1 << k) + n) % n;
        }
        countSort(pos, class_);
        vector<int> class_new(n);
        class_new[pos[0]] = 0;
        for (int i = 1; i < n; i++) {
            pair<int, int> prev = {class_[pos[i - 1]],
                                   class_[(pos[i - 1] + (1 << k)) % n]};
            pair<int, int> curr = {class_[pos[i]], class_[(pos[i] + (1 << k)) % n]};
            class_new[pos[i]] = class_new[pos[i - 1]] + int(prev != curr);
        }
        class_ = class_new;
        k++;
    }
    return {pos, class_};
}

vector<int> computeLCP(const vector<int> &p, const vector<int> &c,
                       const string &s) {
    int n = p.size();
    int k = 0;

    vector<int> lcp(n - 1);
    for (int i = 0; i < n - 1; i++) {
        int pi = c[i];  // pi >= 1 as "$" is always the smallest suffix string
        int j = p[pi - 1];
        // lcp[pi] = lcp(s[i:], s[j:])
        while (s[i + k] == s[j + k]) {
            k++;
        }
        lcp[pi - 1] = k;  // shift to left by one
        k = max(k - 1, 0);
    }
    return lcp;
}



int main() {
    string s = "";
    cin>>s;

    auto result = computeSuffixArray(s);
    vector<int> p = result.first;
    /*
    for (const auto &elem : result.first) {
        cout << elem << " ";
    } 
    cout << endl;
    */
    vector<int> lcp = computeLCP(result.first, result.second, s);

    for (int i = 2; i < result.first.size(); i++) {
        cout<<lcp[i]<<" "<<s.substr(result.first[i], result.first.size()-result.first[i])<<endl;
    }
    

    /*int maxi = 0;
    string res;
    for(int i = 2; i < lcp.size(); i++) {
        bool cl1 = (p[i] >= 0 and p[i] <s.size());
        bool cl2 = (p[i+1] >= 0 and p[i+1] <s.size());
        if(cl1 != cl2 and maxi < lcp[i]){
            maxi = lcp[i];
            res = s.substr(p[i], maxi);
            //cout<<maxi<<" "<<res<<endl;
        }
    }
    cout<<res<<endl;
    */
    return 0;
}
/*
ababba$
babb
0 ababbab
2 abbab
4 bab
6 b
1 babbab
3 bbab 


itmouniversity
14 $
8 ersity$
0 itmouniversity$
11 ity$
6 iversity$
2 mouniversity$
5 niversity$
3 ouniversity$
9 rsity$
10 sity$
1 tmouniversity$
12 ty$
4 university$
7 versity$
13 y$


3 $ 0
2 a$  1
1 aa$ 2
0 aaa$ 3
*/