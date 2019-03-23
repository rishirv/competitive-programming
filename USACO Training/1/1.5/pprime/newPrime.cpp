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

vector<int> primes;

bool isPrime(int x){
  for(int p : primes){
    if(x%p==0){
      return 0;
    }
  }
  return 1;
}

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
  for(int i=a; i<=lim; i++){
    if(sieve[i]&&isPalindrome(to_string(i))){
      fout<<i<<endl;
    }
  }
  for(int i=max(lim,a); i<=b; i++){
    if(isPrime(i)&&isPalindrome(to_string(i))){
      fout<<i<<endl;
    }
  }
}