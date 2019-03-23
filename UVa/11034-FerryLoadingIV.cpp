#include <iostream>
#include <queue>
#include <string>
using namespace std;

int a, l, m, j, p, n;
string s;
queue<int> arr[2];
bool f;

int main(){
  cin>>a;
  for(int i=0; i<a; i++){
    cin>>l>>m;
    l*=100;
    f = n = 0;
    for(int i=0; i<m; i++){
      cin>>j>>s;
      arr[s == "left" ? 0 : 1].push(j);
    }

    while(true){
      p = 0;
      if(arr[0].empty() && arr[1].empty()) break;
      while(!arr[f].empty() && arr[f].front()+p<=l){
        p += arr[f].front();
        arr[f].pop();
      }
      f = !f;
      n++;
    }
    cout<<n<<endl;
  }
}