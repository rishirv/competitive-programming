//Prime Sieve
//Sieve of Eratosthenes
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

bitset<1000010> bs;
vi primes;
int n;

void seive(ll bound){
  bs.set();
  bs[0]=bs[1]=0;
  for(ll i=2; i<=bound; i++){
    if(bs[i]){
      for(ll j=i*i; j<=bound; j+=i){
        bs[j]=0;
      }
    }
  }
}

int main(){
  seive(1000000);
  while(cin>>n && n!=0){
    for(int i=3; i<=n/2; i++){
      if(bs[i] & bs[n-i]){
        cout<<n<<" = "<<i<<" + "<<n-i<<'\n';
        break;
      }
    }
  }
}