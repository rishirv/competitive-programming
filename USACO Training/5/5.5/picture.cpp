/*
ID: verma.r1
PROG: picture
LANG: C++11
*/
#include <fstream>
#include <algorithm>
using namespace std;

struct rect{
  int s, x, y, X, Y;
};

ifstream cin ("picture.in");
ofstream cout ("picture.out");
long per = 0, n, x = 0, k;
rect p[362874];

int main (){
  cin>>n;

  for(int i = 0; i < n ; i++) {
    k = x;
    x++;

    cin>>p[k].x>>p[k].y>>p[k].X>>p[k].Y;
    p[k].s = 1;

    for(int j = 0;  j < k; j++){
      p[x].x = max(p[j].x, p[k].x);
      p[x].y = max(p[j].y, p[k].y);
      p[x].X = min(p[j].X, p[k].X);
      p[x].Y = min(p[j].Y, p[k].Y);
      p[x].s = -p[j].s * p[k].s;

      if(p[x].x == p[k].x && p[x].X == p[k].X &&
        p[x].y == p[k].y && p[x].Y == p[k].Y){
        x = k;
        break;
      }

      if((p[x].X >= p[x].x && p[x].Y >= p[x].y)){
        x++; 
      }
    }
  }

  for (int i = 0; i < x; i++){
    per += p[i].s * (p[i].X - p[i].x + p[i].Y - p[i].y);
  }
  cout<<per*2<<endl;
}