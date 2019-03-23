/*
ID: verma.r1
PROG: sprime
LANG: C++11
*/
#include <fstream>
#include <cmath>
using namespace std;

int n;

bool isVal(int i, bool seive[]){
  for(int x = 0; x<n; x++){
    if(seive[i]){
      i/=10;
    } else{
      return false;
    }
  }
  return true;
}

int main(){
  ifstream fin ("sprime.in");
  ofstream fout ("sprime.out");

  fin>>n;
  int lim = pow(10,n);
  bool sieve[lim];
  for(bool &x : sieve){
    x=true;
  }
  sieve[0]=sieve[1]=0;
  for(int i=2; i<pow(lim,0.5); i++){
    if(sieve[i]){
      for(int j = 0; j<lim-i*i; j+=i){
        sieve[i*i+j]=0;
      }
    }
  }
  for(int i = lim/10; i<lim; i++){
    if(isVal(i, sieve))
      fout<<i<<endl;
  }
}