/*
ID: verma.r1
PROG: fence9
LANG: C++11
*/
#include <fstream>
#include <algorithm>
using namespace std;

int gcd(int a, int b){
  return min(a,b)==0 ? max(a,b) : gcd(min(a,b), max(a,b)%min(a,b)); 
}

//picks   a=b/2+i-1;

int main(){
  ifstream cin ("fence9.in");
  ofstream cout ("fence9.out");
  int m, n, p;
  cin>>m>>n>>p;
  double a=p*n/2.0;
  int b=p+gcd(m,n)+gcd(max(m-p, p-m), n);
  int i=a-b/2.0+1;
  cout<<i<<endl;
}