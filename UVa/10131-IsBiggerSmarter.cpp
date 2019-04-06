//Dynamic Programming
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

struct p{
  int a, b, i;
  bool operator < (p rhs) const{
    return a<rhs.a || (a == rhs.a && b > rhs.b);
  }
};

int n, lis[1000], m;
p arr[1000];
string s[1000], ms;

int main(){
  while(cin>>arr[n].a>>arr[n].b && arr[n].a != 0){
    arr[n].i = n+1;
    n++;
  }
  sort(arr, arr+n);
  for(int i=0; i<n; i++){
    for(int j=0; j<i; j++){
      if(arr[i].a > arr[j].a && arr[i].b < arr[j].b && lis[j] + 1 > lis[i]){
        lis[i] = lis[j];
        s[i] = s[j];
      }
    }
    lis[i]++;
    s[i] += to_string(arr[i].i) + '\n';
    if(lis[i] > m){
      m = lis[i];
      ms = s[i];
    }
  }
  cout<<m<<'\n'<<ms<<'\n';
}