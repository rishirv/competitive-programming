/*
ID: verma.r1
PROG: milk3
LANG: C++11
*/
#include <fstream>
#include <set>
#include <tuple>
using namespace std;

struct pos{
  int a,b,c;
};

pos y;
int a,b,c, flag=0;
set<pos> milk;

inline bool operator<(const pos& x, const pos& y){
  return tie(x.a, x.b, x.c)<tie(y.a, y.b, y.c);
}

void solve(pos x){
  y.a = (x.a+x.b-b<0?0:x.a+x.b-b);
  y.b = (x.a+x.b-b<0?x.a+x.b:b);
  y.c=x.c;
  if(milk.insert(y).second)
    solve(y);
  y.b = (x.b+x.a-a<0?0:x.b+x.a-a);
  y.a = (x.b+x.a-a<0?x.b+x.a:a);
  y.c=x.c;
  if(milk.insert(y).second)
    solve(y);
  y.a = (x.a+x.c-c<0?0:x.a+x.c-c);
  y.c = (x.a+x.c-c<0?x.a+x.c:c);
  y.b=x.b;
  if(milk.insert(y).second)
    solve(y);
  y.c = (x.c+x.a-a<0?0:x.c+x.a-a);
  y.a = (x.c+x.a-a<0?x.c+x.a:a);
  y.b=x.b;
  if(milk.insert(y).second)
    solve(y);
  y.c = (x.c+x.b-b<0?0:x.c+x.b-b);
  y.b = (x.c+x.b-b<0?x.c+x.b:b);
  y.a=x.a;
  if(milk.insert(y).second)
    solve(y);
  y.b = (x.b+x.c-c<0?0:x.b+x.c-c);
  y.c = (x.b+x.c-c<0?x.b+x.c:c);
  y.a=x.a;
  if(milk.insert(y).second)
    solve(y);
}

int main(){
  ifstream fin ("milk3.in");
  ofstream fout ("milk3.out");
  fin>>a>>b>>c;
  pos x {0,0,c};
  milk.insert(x);
  solve(x);
  set<int> c_val;
  for(pos x : milk)
    if(x.a==0)
      c_val.insert(x.c);
  for(int i : c_val){
    fout<<i;
    if(i==c)
      fout<<endl;
    else
      fout<<" ";
  }
  return 0;
}