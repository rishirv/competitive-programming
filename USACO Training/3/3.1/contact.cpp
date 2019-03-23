/*
ID: verma.r1
PROG: contact
LANG: C++11
*/
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

bool isLess(string a, string b){
  for(int x=0; x<a.length(); x++){
    if(a[x]!=b[x])
      return a[x]<b[x];
  }
  return false;
}

bool comp(string x, string y){
  return (x.length()==y.length() ? isLess(x,y) : x.length()<y.length());
}

int main(){
  ifstream cin ("contact.in");
  ofstream cout ("contact.out");

  map<string, int> freq;
  map<int, vector<string>, greater<int>> pattern;
  string str="", x;
  int a, b, n;
  cin>>a>>b>>n;

  while(cin>>x){
    str+=x;
  }
  
  for(int i=0; i<=str.length()-a; i++){
    for(int j=a; j<=b; j++){
      x=str.substr(i,j);
      if(x.length()==j)
        ++freq[x];
    }
  }
  for(auto y : freq){
    pattern[y.second].push_back(y.first);
  }
  int i=0;
  for(auto y : pattern){
    ++i;
    cout<<y.first<<endl;
    sort(y.second.begin(), y.second.end(), comp);
    for(int i=0; i<y.second.size(); i++){
      cout<<y.second[i];
      if(i%6==5 || i==y.second.size()-1)
        cout<<endl;
      else
        cout<<" ";
    }
    if(i==n)
      break;
  }
}