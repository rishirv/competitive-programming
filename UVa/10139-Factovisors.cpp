//Math
#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;

bitset<100010> bs;
vi primes;
int a, b, idx, pf, c, d, e;
bool f;

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

int main(){
  seive(100000);
  while(cin>>a>>b){
    cout<<b;
    f = (b == 0 ? false : true);
    idx = 0;
    pf = primes[idx];
    while(f && pf*pf <= b){
      c = d = 0;
      e = a;
      while(b%pf==0){
        b /= pf;
        c++;
      }
      while(e>0){
        d += e/pf;
        e/=pf;
      }
      if(c>d) f=false;
      pf = primes[++idx];
    }
    if(b != 1 && a < b) f = false;
    if(f) cout<<" divides ";
    else cout<<" does not divide ";
    cout<<a<<"!\n";
  }
}