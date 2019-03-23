/*
ID: verma.r1
PROG: milk4
LANG: C++11
*/
#include <fstream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

ifstream cin ("milk4.in");
ofstream cout ("milk4.out");

int q, p, n;
bool dp[20001];
int pails[100], options[100];

bool possible(){
  if(n == 1){
    return (q % options[0] == 0);
  } else if(n == 2){
    int x = q;
    while(x>options[1]){
      x-= options[1];
      if(x%options[0] == 0) return true;
    }
    return false;
  }

  memset(dp, false, 20001*sizeof(bool));
  dp[0] = true;

  for(int i=0; i<n; i++){
    for(int j=0; j<=q-options[i]; j++){
      if(dp[j]) dp[j+options[i]] = true;
      if(dp[q]) return true;
    }
  }
  return false;
}

bool bfs(int cur, int top){
  if(cur == n){
    return possible();
  } else{
    for(; top < p-n+cur+1; top++){
      options[cur] = pails[top];
      if(bfs(cur+1, top+1)) return true;
    }
    return false;
  }
}

int main() {
  cin>>q>>p;
  for(int i=0; i<p; i++){
    cin>>pails[i];
  }

  sort(pails, pails+p);

  for(n=1; n<=p; n++){
    if(bfs(0, 0)){
      cout<<n<<" ";
      for(int i=0; i<n-1; i++){
        cout<<options[i]<<" ";
      }
      cout<<options[n-1]<<endl;
      break;
    }
  }
}