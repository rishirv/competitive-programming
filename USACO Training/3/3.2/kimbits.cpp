/*
ID: verma.r1
PROG: kimbits
LANG: C++11
*/
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

string s;
ifstream cin ("kimbits.in");
ofstream cout ("kimbits.out");

int comb(int c, int k){
  if(c<k){
    return 0;
  }
  unsigned long long product=1;
  k=min(k, c-k);
  for(int i=0; i<k; i++){
    product*=c-i;
    product/=i+1;
  }
  return product;
}

void solve(int n, int l, double k){
  if(l==0 || k==1)
    return;
  int x, i, y;
  for(i=0; i<n; i++){
    y=0;
    for(int j=0; j<=l; j++)
      y+=comb(i,j);
    if(y>=k)
      break;
    x=y;
  }
  s[i-1]='1';
  solve(i-1, l-1, k-x);
}

int main(){
  int n, l;
  double k;
  cin>>n>>l>>k;
  s=string(n, '0');
  solve(n, l, k);
  reverse(s.begin(), s.end());
  cout<<s<<endl;
}