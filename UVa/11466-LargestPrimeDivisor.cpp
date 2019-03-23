//Prime Sieve
//Sieve of Eratosthenes
//IsPrime Is Prime
//Prime Factors
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

ll factors(ll n){
  ll idx = 0, pf = primes[idx], m = -1, c = 0;
  while(pf*pf <= n){
    if(n%pf==0) ++c;
    while(n%pf==0){
      n /= pf;
      m = pf;
    }
    pf = primes[++idx];
  }
  if(n!=1){
    m=n;
    ++c;
  }
  return c > 1 ? m : -1;
}

bool isPrime(ll n){
  if(n <= 10000000) return bs[n];
  for(ll p : primes) if(n % p == 0) return false;
  return true;
}

int main(){
  seive(10000000);
  while(cin>>n && n!=0) cout<<factors((ll) abs(n))<<'\n';
}