#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct node{
    int val;
    node * prev;
    node(int x){
        val = x;
        prev = NULL;
    }
};

struct steck{
    private:
        node * tail;
    public:
    steck(){
        tail = NULL;
    }
    void push_back(int x){
        node * item = new node(x);
        item->prev = tail;
        tail = item;
    }
    void pop(){
        if(tail!=NULL){
            node * temp = tail;
            tail = tail->prev;
            delete temp;
        }else{
            cout<<"empty stack"<<endl;
        }
    }
    int back(){
        return tail->val;
    }
    bool empty(){
        return tail==NULL;
    }
};

int main(){
    stack <int> v[510];
    vector <pair<int,int> > victor;
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++){
        int k,l;
        cin>>k;
        for(int j = 0; j < k; j++){
            cin>>l;
            v[i].push(l);
        }   
    }

    if(n==1)
        return 0;
    else if(n==2){
        int cnt = 0;
        while(!v[1].empty()){
            if(v[1].top()==2){
                v[2].push(v[1].top());
                v[1].pop();
                cnt++; }
        }
        while(!v[1].empty()){
            if(v[1].top()==1)
                v[1].pop();
            else{
                cout<<0<<endl;
                return 0;}
        }
        for(int i=0; i<cnt; i++)
            victor.push_back(make_pair(1,2));
    }
    else if(n>2){
        while(!v[1].empty()){
            int index = v[1].top();
            v[2].push(index);
            v[1].pop();
            victor.push_back(make_pair(1,2));
        }
        
        for(int i = 2; i <=n; i++){
            while(!v[i].empty()){
                int index = v[i].top();
                if(i==2){
                    v[3].push(index);
                    victor.push_back(make_pair(2,3));
                }else if(index==1){
                    v[1].push(index);
                    victor.push_back(make_pair(i,1));
                }else{
                    v[2].push(index);
                    victor.push_back(make_pair(i,2));
                }
                v[i].pop();
            }
        }
        while(!v[2].empty()){
            int index = v[2].top();
            v[1].push(index);
            v[2].pop();
            victor.push_back(make_pair(2,1));
        }
        while(!v[1].empty() and v[1].top()!=1){
            int index = v[1].top();
            v[index].push(index);
            v[1].pop();
            victor.push_back(make_pair(1,index));
        } 
        for (int i = 0; i < victor.size(); ++i){
            cout << victor[i].first << " " << victor[i].second << endl;
        }
    }
    return 0;
}

/* ����� ����� ��� ������ ��� ������� � ������ ������.������ ������ ��� ���� � ��� ������. 
� ������ ������ ���������� �� �����. 
�� ������ ����� ����� ������� ��� -���������� �� ��� ������� ���������� No2 �� ������. 
���� ���  ����  �  ���  ��  ���������  �����������  No2  (���  ���  ����  ������  �  ������� ����������) ?��� ������. 
���� ��� ?��������� ����������.���������� ����� ������, ����� ����������� �� ������ ����. 
� ���� ������ ��������� ������ �����. 
��������� ��� ���������� �� ������ ������ � �� ���������������, � ���������� No1 ����� ���������� �� ������ ������ (������ � ������������ No2). 
������ �������� ������. ���������� No2 � ������, � No1 �� ����� ?� ������. 
������ ��� ���������� No2 �� ������ � �������. 
�������, ��� ��� ���� ���������� ������� ����� ��� �����, � ���������� � ���������� � �������� �������� ������ ����� ��������! */