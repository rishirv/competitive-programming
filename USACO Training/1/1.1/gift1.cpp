/*
ID: verma.r1
PROG: gift1
LANG: C++11
*/
#include <fstream>
#include <string>
#include <map>
using namespace std;

int main(){
  ifstream fin ("gift1.in");
  ofstream fout ("gift1.out");
  
  int num_of_names, money, num_of_receivers;
  string name, giver;
  fin>>num_of_names;

  map<string, int> accounts;
  const int n = num_of_names;
  string names[10];
  for(int i=0; i<num_of_names; i++){
    fin>>name;
    accounts[name]=0;
    names[i]=name;
  }
  while(fin>>giver>>money>>num_of_receivers){
    if(num_of_receivers){
      accounts[giver]+=(money%num_of_receivers)-money;
      money/=num_of_receivers;
      for(int i=0; i<num_of_receivers; i++){
        fin>>name;
        accounts[name]+=money;
      }
	}
  }
  for(string x : names)
	if(x!="")
	    fout<<x<<" "<<accounts[x]<<"\n";
  return 0;
}