/*
ID: verma.r1
PROG: heritage
LANG: C++11
*/
#include <fstream>
#include <string>
using namespace std;

struct node{
  char a;
  node *l;
  node *r;
};

ifstream cin ("heritage.in");
ofstream cout ("heritage.out");

void construct(node &r, string pre, string in){
  int i;
  r.a=in[0];
  r.l=NULL;
  r.r=NULL;
  for(i=0; i<pre.length(); i++)
    if(pre[i]==in[0])
      break;
  if(i!=0){
    r.l=new node;
    construct(*(r.l), pre.substr(0, i), in.substr(1, i));
  }
  if(i!=pre.length()-1){
    r.r=new node;
    construct(*(r.r), pre.substr(i+1, pre.length()-i-1), in.substr(i+1, pre.length()-i-1));
  }
}

void print(node r){
  if(r.l!=NULL)
    print(*(r.l));
  if(r.r!=NULL)
    print(*(r.r));
  cout<<r.a;
}

int main(){
  string pre, in;
  node r;
  cin>>pre>>in;
  construct(r, pre, in);
  print(r);
  cout<<endl;
}