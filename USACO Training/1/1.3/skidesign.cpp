/*
ID: verma.r1
PROG: skidesign
LANG: C++11
*/
#include <fstream>
#include <set>
#include <map>

using namespace std;

struct Point{
  int x,y;
};

bool operator<(const Point& a, const Point& b){
  return a.x < b.x;
}

int n;
set<map<Point,Point>> pairings;

void pairs(int x, map<int, int> m, Point points[]){
  if(x==n/2){
    map<Point,Point> r;
    for(int i=0; i<n; i++){
      r[points[i]]=points[m[i+1]-1];
    }
    pairings.insert(r);
  } else{
    int i,j;
    for(i=1; i<n; i++){
      if(m.count(i)==0||m[i]==0){
        for(j=i+1; j<=n; j++){
          if(m[j]==0){ //Works
            map<int, int> temp = m;
            temp[i]=j;
            temp[j]=i;
            pairs(x+1, temp, points);
          }
        }
        break; //Works
      }
    }
  }
}

bool loop(Point points[], map<Point, Point> m){
  for(int i=0; i<n; i++){
    set<Point> loop;
    Point start = points[i], end;
    loop.insert(start);
    while(true){
      end=m[start];
      if(!loop.insert(end).second)
        return true;
      Point mp {1000000001,1000000001};
      for(int j=0; j<n; j++){
        Point p = points[j];
        if(p.y==end.y&&p.x<mp.x&&p.x>end.x)
          mp=p;
      }
      if(mp.x==1000000001&&mp.y==1000000001)
        break;
      else{
        start=mp;
        if(!loop.insert(start).second)
          return true;
      }
    }
  }
  return false;
}
int main(){
  ofstream fout ("skidesign.out");
  ifstream fin ("skidesign.in");
  int x, y, count=0;
  fin>>n;
  Point points[n];
  for(int i=0; i<n; i++){
    fin>>x>>y;
    points[i]  = Point {x, y};
  }
  map<int, int> m;
  pairs(0, m, points);
  for(auto m : pairings){
    if(loop(points, m)){
      count+=1;
    }
  }
  fout<<count<<endl;
}