#include <iostream>
#include <stack>
#include <queue>
using namespace  std;

stack<int> s;
queue<int> q;
priority_queue<int> p;
bool a, b, c;

int main(){
  int n, op, x;
  while(cin>>n){
    a = b = c = true;
    q = queue<int>();
    s = stack<int>();
    p = priority_queue<int>();
    while(n--){
      cin>>op>>x;
      if(op == 1){
        s.push(x);
        q.push(x);
        p.push(x);
      } else{
        if(s.empty() || s.top() != x) a = false;
        else s.pop();
        if(q.empty() || q.front() != x) b = false;
        else q.pop();
        if(p.empty() || p.top() != x) c = false;
        else p.pop();
      }
    }
    if(a && !b && !c){
      cout<<"stack"<<endl;
    } else if(!a && b && !c){
      cout<<"queue"<<endl;
    } else if(!a && !b && c){
      cout<<"priority queue"<<endl;
    } else if(!a && !b && !c){
      cout<<"impossible"<<endl;
    } else cout<<"not sure"<<endl;
  }
}