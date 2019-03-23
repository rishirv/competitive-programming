#include <iostream>
#include <bitset>
using namespace std;

pair<int, int> arr[15];
bitset<15> bs;
int n, m, a, b, start, last;

bool domino(int c = 0, int pre = start){
  if(c == n) return pre == last;
  for(int i=0; i<m; i++){
    if(!bs[i] && (arr[i].first == pre || arr[i].second == pre)){
      bs[i] = true;
      if(domino(c+1, arr[i].first == pre ? arr[i].second : arr[i].first)){
        bs[i] = false;
        return true;
      }
      bs[i] = false;
    }
  }
  return false;
}

int main() {
  while(cin>>n && n!= 0){
    cin>>m>>a>>start>>last>>a;
    for(int i=0; i<m; i++){
      cin>>a>>b;
      arr[i] = make_pair(a, b);
    }
    cout<<(domino() ? "YES\n" : "NO\n");
  }
}