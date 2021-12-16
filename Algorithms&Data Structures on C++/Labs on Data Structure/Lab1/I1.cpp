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
            if(index==1){
                v[2].push(1);
                victor.push_back(make_pair(1,2));
            }else{
                v[index].push(index);
                victor.push_back(make_pair(1,index));
            }
            v[1].pop();
        }
        while(!v[2].empty()){
            int index = v[2].top();
            if(index==1){
                v[1].push(index);
                victor.push_back(make_pair(2,1));
            }else{
                v[3].push(index);
                victor.push_back(make_pair(2,3));
            }
            v[2].pop();
        }
        while(!v[3].empty() and v[3].top()==2){
            v[2].push(2);
            victor.push_back(make_pair(3,2));
            v[3].pop();
        } 
        for (int i = 0; i < victor.size(); ++i)
            cout << victor[i].first << " " << victor[i].second << endl;
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