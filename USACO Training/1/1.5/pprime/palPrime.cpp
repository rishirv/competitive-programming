/*
ID: verma.r1
PROG: pprime
LANG: C++11
*/
#include <fstream>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> primes;
ifstream fin ("pprime.in");
ofstream fout ("pprime.out");
int a,b;

bool isPrime(int x){
  if(x<a||x>b){
    return false;
  }
  for(int p : primes){
    if(x%p==0){
      return false;
    }
  }
  return true;
}

void genPal(int n, int x, string s){
  if(x==ceil(n/2.0)){
    if(isPrime(stoi(s))){
      fout<<s<<endl;
    }
  } else if(x==0){
    for(char i='1'; i<='9'; i++){
      s[x]=i;
      s[n-x-1]=i;
      genPal(n, x+1, s);
    }
  } else{
    for(char i='0'; i<='9'; i++){
      s[x]=i;
      s[n-x-1]=i;
      genPal(n, x+1, s);
    }
  }
}

string reverse(string s){
  reverse(s.begin(), s.end());
  return s;
}

bool isPalindrome(string s){
  return s==reverse(s);
}

int main(){
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
  for(int p : primes)
    if(p>=a&&isPalindrome(to_string(p)))
      fout<<p<<endl;

  for(int i=ceil(log10(a)); i<=ceil(log10(b)); i++){
    string s(i, ' ');
    genPal(i, 0, s);
  }
}