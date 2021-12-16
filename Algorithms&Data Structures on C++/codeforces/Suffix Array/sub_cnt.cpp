#include <bits/stdc++.h>

using namespace std;
    
int sub_cnt(vector<int> &p, string &s, string &t){
    int left = 0;
    int right = p.size();

    while(left < right){
        int mid = left + (right-left)/2;

        string sub = s.substr(p[mid],t.length());
        if(t > sub)
            left = mid+1;
        else
            right = mid;
    }

    if(left >= p.size() || s.substr(p[left],t.length())!=t)
        return 0;

    int left2 = left;
    right = p.size();

    while(left2 < right){
        int mid = left2 + (right-left2)/2;

        string sub = s.substr(p[mid],t.length());
        if(t >= sub)
            left2 = mid+1;
        else
            right = mid;
    }
    return right - left;
} 


void count_sort(vector<int> &p, vector<int> &c)
{
    int n = p.size();
    vector<int> cnt(n);
    for (auto x : c)
    {
        cnt[x]++;
    }
    vector<int> p_new(n);
    vector<int> pos(n);
    pos[0] = 0;
    for (int i = 1; i < n; i++)
    {
        pos[i] = pos[i - 1] + cnt[i - 1];
    }
    for (auto x : p)
    {
        int i = c[x];
        p_new[pos[i]] = x;
        pos[i]++;
    }
    p = p_new;
}

vector<int> computeSuffArr(string s){
    s += "$";
    int n = s.size();
    vector<int> p(n), c(n);
    {
        vector<pair<char, int> > a(n);
        for (int i = 0; i < n; i++)
            a[i] = make_pair(s[i], i);
        sort(a.begin(), a.end());

        for (int i = 0; i < n; i++)
            p[i] = a[i].second;
        c[p[0]] = 0;
        for (int i = 1; i < n; i++)
        {
            c[p[i]] = c[p[i - 1]] + int(a[i].first != a[i - 1].first);
        }
    }
    int k = 0;
    while ((1 << k) < n)
    {
        for (int i = 0; i < n; i++)
        {
            p[i] = (p[i] - (1 << k) + n) % n;
        }
        count_sort(p, c);

        vector<int> c_new(n);
        c_new[p[0]] = 0;
        for (int i = 1; i < n; i++)
        {
            pair<int, int> prev = make_pair(c[p[i - 1]], c[(p[i - 1] + (1 << k)) % n]);
            pair<int, int> now = make_pair(c[p[i]], c[(p[i] + (1 << k)) % n]);
                
            c_new[p[i]] = c_new[p[i - 1]] + int(now != prev);
        }
        c = c_new;
        k++;
    }
    return p;
}

int main()
{
    string s;
    cin >> s;
    
    vector<int> p = computeSuffArr(s);
    
    int n = p.size();
    int op = 0;
    cin >> op;

    for (int i = 0; i < op; i++)
    {   
        string t;
        cin >> t;
        cout << sub_cnt(p, s, t) << "\n";
    }

    

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