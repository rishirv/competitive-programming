//Mu
//Merten
//Number of different prime factors
//NumDiffPF
//Math
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <bitset>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;

bitset<10000010> bs;
vi primes;
int arr[1000010], n;

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

int mu(ll n){
  if(n == 1) return 1;
  ll idx = 0, pf = primes[idx], ans, c=0;
  while(pf*pf <= n){
    ans = 0;
    while(n%pf==0){
      n /= pf;
      ans++;
    }
    if(ans >= 2) return 0;
    if(ans) ++c;
    pf = primes[++idx];
  }
  if(n!=1) ++c;
  return c & 1 ? -1 : 1;
}

int main(){
  seive(10005);
  for(int i=1; i<=1000000; i++) arr[i]=arr[i-1]+mu(i);
  while(cin>>n && n != 0){
    cout<<setw(8)<<n<<setw(8)<<arr[n]-arr[n-1]<<setw(8)<<arr[n]<<'\n';
  }
}