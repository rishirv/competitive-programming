//Euler Totient Function
//Phi
//EulerPhi
//Math
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <bitset>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;

bitset<10000010> bs;
vi primes;
ll n;

void seive(ll bound){
  bs.set();
  bs[0]=bs[1]=0;
  for(ll i=2; i<=bound; i++){
    if(bs[i]){
      for(ll j=i*i; j<=bound; j+=i) bs[j]=0;
      primes.push_back(i);
    }
  }
}

ll totient(ll n){
  ll idx = 0, pf = primes[idx], ans = n;
  while(pf*pf <= n){
    if(n%pf==0) ans -= ans/pf;
    while(n%pf==0) n /= pf;
    pf = primes[++idx];
  }
  if(n!=1) ans -= ans/n;
  return ans;
}

int main(){
  seive(100000);
  while(cin>>n && n!=0) cout<<totient(n)<<'\n';
}