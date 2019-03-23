//Cycle Finding
//Floyds Cycle-Finding algorithm
//Tortoise and hare
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

int n, a, b, t, h, mu, lambda;

int f(ll x){
  ll r = (x*x)%n;
  r = (r*a)%n;
  return (r+b)%n;
}

int main(){
  while(cin>>n && n!=0){
    cin>>a>>b;
    t = f(0), h=f(t); //t=tortoise, h=hare
    while(t != h){ //Part 1 (Finding k*lambda)
      t=f(t);
      h=f(f(h));
    }
    mu = h = 0;
    while(t != h){ //Part 2 (Finding mu)
      t=f(t);
      h=f(h);
      ++mu;
    }
    lambda = 1;
    h = f(t);
    while(t != h){ //Part 3 (Finding lambda)
      h=f(h);
      lambda++;
    }
    cout<<n-lambda<<'\n';
  }
}