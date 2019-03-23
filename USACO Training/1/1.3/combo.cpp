/*
ID: verma.r1
PROG: combo
LANG: C++11
*/
#include <fstream>
#include <set>
#include <string>
using namespace std;

int n;
set<string> nums;

int mod(int a, int b){
  return (b+(a%b))%b;
}

void comb(int x, int y, int z){
  for(int i=-2; i<=2; i++){
    for(int j=-2; j<=2; j++){
      for(int k=-2; k<=2; k++){
        nums.insert(to_string(mod(x+i,n))+','+to_string(mod(y+j,n))+','+to_string(mod(z+k,n)));
      }
    } 
  }
}

int main(){
  ifstream fin ("combo.in");
  ofstream fout ("combo.out");
  int a,b,c;
  fin>>n>>a>>b>>c;
  comb(a,b,c);
  fin>>a>>b>>c;
  comb(a,b,c);
  fout<<nums.size()<<endl;
  return 0;
}