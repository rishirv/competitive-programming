/*
ID: verma.r1
PROG: sprime
LANG: C++11
*/
#include <fstream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

vector<int> primes;
char digits[4] {'1', '3', '7', '9'};
int n;
ofstream fout ("sprime.out");

bool isPrime(int x){
  for(int p : primes)
    if(x!=p && x%p==0)
      return false;
  return true;
}

void genSprime(string x, int i){
  if(i==n){
    fout<<x<<endl;
  } else{
    for(char y : digits)
      if(isPrime(stoi(x+y)))
        genSprime(x+y, i+1);
  }
}

int main(){
  ifstream fin ("sprime.in");
  fin>>n;
  int lim=pow(10,n), sq=pow(lim, 0.5);
  bool sieve[sq+1];
  for(bool &x : sieve){
    x=true;
  }
  sieve[0]=sieve[1]=0;
  for(int i=2; i<=sq; i++){
    if(sieve[i]){
      primes.push_back(i);
      for(int j = 0; j<=sq/i-i; j++){
        sieve[i*i+j*i]=0;
      }
    }
  }
  genSprime("2", 1);
  genSprime("3", 1);
  genSprime("5", 1);
  genSprime("7", 1);
}