/*
ID: verma.r1
PROG: prefix
LANG: C++11
*/
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main(){
  vector<string> prefix;
  string str;
  bool arr[200001] {1};
  ifstream cin ("prefix.in");
  ofstream cout ("prefix.out");

  cin>>str;
  do{
    prefix.push_back(str);
    cin>>str;
  } while(str!=".");

  str="";

  string x;

  while(cin>>x){
    str+=x;
  }
  int n=str.length();

  for(int i=0; i<n; i++){
    if(!arr[i]){
      continue;
    }
    for(string s : prefix){
      if(str.substr(i, s.length())!=s){
        continue;
      }
      arr[i+s.length()]=1;
    }
  }
  for(int i=str.length(); ;i--){
    if(arr[i]){
      cout<<i<<endl;
      break;
    }
  }
}