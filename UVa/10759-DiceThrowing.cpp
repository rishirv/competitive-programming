//Simplify Fractions
//Math
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;

int a, b;
ll arr[25][145], m, s, g;

ll gcd(ll a, ll b){
  if(b==0) return a;
  return gcd(b, a%b);
}

int main(){
  for(int i=1; i<=6; i++) arr[1][i] = 1;
  for(int i=2; i<=24; i++){
    for(int j=i; j<=6*i; j++){
      for(int k=1; k<=6; k++){
        if(j-k>=0) arr[i][j] += arr[i-1][j-k];
      }
    }
  }
  while(cin>>a>>b && a!=0){
    if(b>6*a) cout<<0<<'\n';
    else if(b <= a) cout<<1<<'\n';
    else{
      m = 0;
      for(int i=b; i<=144; i++) m+=arr[a][i];
      s = (ll) pow(6, a);
      g = gcd(m, s);
      m/=g;
      s/=g;
      cout<<m<<'/'<<s<<'\n';
    }
  }
}