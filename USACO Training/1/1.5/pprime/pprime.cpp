/*
ID: verma.r1
PROG: pprime
LANG: C++11
*/
#include <fstream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

string reverse(string s){
  reverse(s.begin(), s.end());
  return s;
}

bool isPalindrome(string s){
  return s==reverse(s);
}

int main(){
  ifstream fin ("pprime.in");
  ofstream fout ("pprime.out");
  int a,b;
  fin>>a>>b;
  int lim = pow(b, 0.5);
  bool sieve[lim+1];
  vector<int> primes;
  for(bool &x : sieve){
    x=true;
  }
  sieve[0]=sieve[1]=0;
  for(int i=2; i<=lim; i++){
    if(sieve[i]){
      primes.push_back(i);
      for(int j = 0; j<=lim/i-i; j++){
        sieve[i*i+j*i]=0;
      }
    }
  }
  for(int k=a; k<=lim; k++){
    if(sieve[k]&&isPalindrome(to_string(k))){
      fout<<k<<endl;
    }
  }
  for(int j=a/lim; j<=b/lim; j++){
    fill_n(sieve, lim+1, 1);
    for(int i=max(a, j*lim+1); i<=min(b, (j+1)*lim); i++){
      for(int p : primes){
        if(i%p==0){
          sieve[i-j*lim]=0;
        }
      }
      if(sieve[i-j*lim]&&isPalindrome(to_string(i))){
        fout<<i<<endl;
      }
    }
  }
}