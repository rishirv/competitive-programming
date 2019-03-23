/*
ID: verma.r1
PROG: fracdec
LANG: C++11
*/
#include <fstream>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;

int gcd(int i, int j){
  if(j==0){
    return i;
  }
  return gcd(j, i%j);
}

int main(){
  ifstream cin ("fracdec.in");
  ofstream cout ("fracdec.out");
  int n, d, t=0, f=0, x;
  bool flag=false;
  string s="";
  cin>>n>>d;
  x=gcd(d, n);
  d/=x;
  n/=x;
  if(n>=d){
    s+=to_string(n/d);
    n%=d;
  } else{
    s+="0";
  }
  s+=".";
  while(d%2==0){
    d/=2;
    t++;
  }
  while(d%5==0){
    d/=5;
    f++;
  }
  if(d!=1){
    flag=true;
  }
  x=max(t, f);
  if(x){
    d*=pow(2,t)*pow(5,f);
    n*=pow(10, x);
    s+=string(x-to_string(n/d).length(), '0');
    s+=to_string(n/d);
    n%=d;
  }
  if(flag){
    s+="(";
    n*=10;
    s+=to_string(n/d);
    n%=d;
    int remainder=n;
    while(flag){
      n*=10;
      if(remainder==n%d){
        flag=false;
      } else{
        s+=to_string(n/d);
        n%=d;
      }
    }
    s+=")";
  } else if(x==0){
    s+="0";
  }
  t=s.length();
  cout<<s[0];
  for(x=1; x<t; x++){
    cout<<s[x];
    if(x%76==75){
      cout<<endl;
    }
  }
  if(t<76 || x%76){
    cout<<endl;
  }
}