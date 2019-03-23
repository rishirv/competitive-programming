#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> p;

int main(){
  int n, x, m;
  cin >> n;
  while(n != 0){
    m = 0;
    for(int i=0; i<n; i++){
      cin>>x;
      p.push(-x);
    }
    while(p.size() >= 2){
      x = p.top();
      p.pop();
      x += p.top();
      p.pop();
      m += x;
      p.push(x);
    }
    p.pop();
    cout << -m << endl;
    cin >> n;
  }
}