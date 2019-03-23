//Bitmask recursive backtracking
//Clever
#include <iostream>
#include <cstring>
using namespace std;

int n, all, ans, arr[20], c;
char ch;

void backtrack(int rw, int ld, int rd, int i){
  if(rw == all){
    ans++;
    return;
  }
  int pos = arr[i] & (~(rw | ld | rd));
  while(pos){
    int p = pos & -pos;
    pos -= p;
    backtrack(rw | p, (ld | p)<<1, (rd | p)>>1, i + 1);
  }
}

int main(){
  while(cin>>n && n!=0){
    ans = 0;
    all = (1<<n)-1;
    memset(arr, 0, sizeof arr);
    for(int i=0; i<n; i++)
      for(int j=0; j<n; j++){
        cin>>ch;
        arr[j] = (arr[j]<<1) | (ch=='.');
      }
    backtrack(0, 0, 0, 0);
    cout<<"Case "<<(++c)<<": "<<ans<<'\n';
  }
}