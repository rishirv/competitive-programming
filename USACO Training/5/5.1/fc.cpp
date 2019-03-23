/*
ID: verma.r1
PROG: fc
LANG: C++11
*/
#include <fstream>
#include <math.h>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

struct point{
  double x, y, angle;
};

bool compare(point a, point b){
  return a.angle < b.angle;
}

bool zcp(point p1, point p2, point p3){
  return (p2.x - p1.x)*(p3.y - p1.y) - (p2.y - p1.y)*(p3.x - p1.x) <= 0;
}

double dist(point p1, point p2){
  return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

point points[10000];
int minp = 0, n;
vector<int> hull;

int main() {
  ifstream cin ("fc.in");
  ofstream cout ("fc.out");

  cin>>n;
  for(int i=0; i<n; i++){
    cin>>(points[i].x)>>(points[i].y);
    if(points[i].y < points[minp].y || (points[i].y == points[minp].y && points[i].x < points[minp].x))
      minp = i;
  }

  point temp = points[minp];
  points[minp] = points[0];
  points[0] = temp;

  for(int i=1; i<n; i++)
    points[i].angle = atan2(points[i].y - points[0].y, points[i].x-points[0].x);

  sort(points+1, points+n, compare);

  hull.push_back(0);
  hull.push_back(1);
  hull.push_back(2);

  for(int i=3; i<n; i++){
    while(zcp(points[hull[hull.size()-2]], points[hull[hull.size()-1]], points[i]))
      hull.pop_back();
    hull.push_back(i);
  }

  double d = dist(points[hull[hull.size()-1]], points[hull[0]]);

  for(int i=1; i<hull.size(); i++)
    d += dist(points[hull[i-1]], points[hull[i]]);

  cout<<setprecision(2)<<fixed<<d<<endl;
}