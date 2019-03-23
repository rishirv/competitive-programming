/*
ID: verma.r1
PROG: msquare
LANG: C++11
*/
#include <fstream>
#include <map>
#include <string>
#include <queue>
using namespace std;

struct msquare{
  int dist;
  string path;
};

string trans(string a, char b){
  string s="";
  switch(b){
    case 'A':
      s=a.substr(4,4)+a.substr(0,4);
      break;
    case 'B': 
      s+=a[3]+a.substr(0,3)+a[7]+a.substr(4,3);
      break;
    case 'C': 
      for(int i : {0, 5, 1, 3, 4, 6, 2, 7})
        s+=a[i];
      break;
  }
  return s;
}

map<string, msquare> m;
queue<string> toInsert;

int main(){
  ifstream cin ("msquare.in");
  ofstream cout ("msquare.out");
  
  string source=string(8, ' '), y, z;
  for(int i : {0, 1, 2, 3, 7, 6, 5, 4}){
    cin>>source[i];
  }
  msquare x {1, ""};
  m["12348765"]=x;
  toInsert.push("12348765");
  if(source=="12348765"){
    cout<<0<<endl<<endl;
  } else{
    while(toInsert.empty()!=true){
      y=toInsert.front();
      toInsert.pop();
      for(char  a : {'A', 'B', 'C'}){
        z=trans(y, a);
        if(m.find(z)==m.end()){
          x.dist=m[y].dist+1;
          x.path=m[y].path+a;
          m[z]=x;
          toInsert.push(z);
        }
        if(z==source){
          break;
        }
      }
    }
    cout<<m[source].dist-1<<endl<<m[source].path<<endl;
  }
}