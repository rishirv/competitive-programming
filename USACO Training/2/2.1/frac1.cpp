/*
ID: verma.r1
PROG: frac1
LANG: C++11
*/
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

  vector<double> num;
  vector<double> denom;
  vector<int> perm;
  int n;

int gcd(int a, int b){
  return (b?gcd(b, a%b):a);
}

bool compare(int a, int b){
  return (num[a]/denom[a]-num[b]/denom[b]<0?true:false);
}

int main(){
  ifstream fin ("frac1.in");
  ofstream fout ("frac1.out");
  fin>>n;
  for(int j=1; j<=n; j++){
    for(int i=0; i<=j; i++){
      if(gcd(j,i)==1){
        num.push_back(i);
        denom.push_back(j);
      }
    }
  }
  for(int i=0; i<num.size(); i++){
    perm.push_back(i);
  }
  sort(perm.begin(), perm.end(), compare);
  for(int i:perm){
    fout<<num[i]<<"/"<<denom[i]<<endl;
  }
}