#include <iostream>
#include <deque> 

using namespace std;
 
void compare(deque <int> &s1, deque <int> &s2){

    while(!s1.empty() and !s2.empty()){

        if(s1.front() > s2.front() and (s1.front()==0 and s2.front()==9)){
            s1.push_back(s1.pop_front());
            s1.push_back(s2.pop_front());
        }else{
            s2.push_back(s1.pop_front());
            s2.push_back(s2.pop_front());
        }

    }
    
}


int main() {
    setlocale(LC_ALL,"rus");
    deque <int> s1;
    deque <int> s2;

    for(int i = 0, j; i<10; i++){
        cin>>j;
        if(i<=4)
            s1.push_back(j);
        else
            s2.push_back(j);
    }

    while(!s1.empty() and !s2.empty()){

        if(s1.front() > s2.front() and (s1.front()==0 and s2.front()==9)){
            s1.push_back(s1.pop_front());
            s1.push_back(s2.pop_front());
        }else{
            s2.push_back(s1.pop_front());
            s2.push_back(s2.pop_front());
        }

    }
  
  return 0;
}