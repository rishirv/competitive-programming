/*
ID: verma.r1
PROG: milk
LANG: C++11
*/
#include <fstream>
#include <algorithm>
using namespace std;

struct Farmer{
    int p, a;
};

bool comp(Farmer a, Farmer b){
  return (a.p<b.p);
}

int main(){
  ifstream fin ("milk.in");
  ofstream fout ("milk.out");
  int n, a, b, amount, price=0;
  fin>>amount>>n;
  Farmer s[n], x;
  for(int i=0; i<n; i++){
    fin>>a>>b;
    s[i]=Farmer {a, b};
  }
  sort(s, s+n, comp);
  for(int i=0; i<n; i++){
    x=s[i];
    if(x.a>=amount){
      price+=x.p*amount;
      break;
    } else{
      price+=x.p*x.a;
      amount-=x.a;
    }
  }
  fout<<price<<endl;
}