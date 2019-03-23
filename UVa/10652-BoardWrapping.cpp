//Point
//Collinear
//Cross product
//CCW Counter Clockwise Test
//Angle Compare
//Polygon area
//Convex hull
//Computational geometry
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <iomanip>
using namespace std;

const double eps = 1e-9;

struct point{
  double x, y;
  point(double _x, double _y) : x(_x), y(_y) {}
  bool operator == (point o) const{
    return abs(x-o.x) < eps && abs(y-o.y) < eps;
  }
  bool operator < (point o) const{
    if(abs(x - o.x) > eps) return x<o.x;
    return y<o.y;
  }
};

struct vec{
  double x, y;
  vec(double _x, double _y) : x(_x), y(_y) {}
};

vec toVec(point a, point b){
  return vec(b.x-a.x, b.y-a.y);
}

double cross(vec a, vec b){
  return a.x * b.y - a.y * b.x;
}

bool ccw(point a, point b, point c){
  return cross(toVec(a, b), toVec(b, c)) > 0;
}

bool collinear(point p, point q, point r){
  return abs(cross(toVec(p, q), toVec(p, r))) < eps;
}

double dist(point a, point b){
  return hypot(a.x-b.x, a.y-b.y);
}

double area(vector<point> P){
  double are = 0.0, x1, y1, x2, y2;
  for(int i=0; i<P.size()-1; i++){
    x1 = P[i].x;
    x2 = P[i+1].x;
    y1 = P[i].y;
    y2 = P[i+1].y;
    are += (x1*y2 - x2*y1);
  }
  return abs(are)/2.0;
}

point pivot(0, 0);
int c, n;
double x, y, a, b, t, are, pi=acos(-1.0);
vector<point> p;

bool angleCmp(point a, point b){
  if(collinear(pivot, a, b)) return dist(pivot, a) < dist(pivot, b);
  double d1x = a.x - pivot.x;
  double d1y = a.y - pivot.y;
  double d2x = b.x - pivot.x;
  double d2y = b.y - pivot.y;
  return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0;
}

vector<point> CH(vector<point> P){
  int i, j, n = P.size();
  if(n <= 3){
    if(!(P[0] == P[n-1])) P.push_back(P[0]);
    return P;
  }
  int P0 = 0;
  for(int i=1; i<n; i++){
    if(P[i].y < P[P0].y || (P[i].y == P[P0].y && P[i].x > P[P0].x)) P0 = i;
  }

  point temp = P[0];
  P[0] = P[P0];
  P[P0] = temp;
  pivot = P[0];

  sort(++P.begin(), P.end(), angleCmp);

  vector<point> S;
  S.push_back(P[n-1]);
  S.push_back(P[0]);
  S.push_back(P[1]);
  i = 2;
  while(i<n){
    j = S.size()-1;
    if(ccw(S[j-1], S[j], P[i]))
      S.push_back(P[i++]);
    else
      S.pop_back();
  }
  return S;
}

int main() {
  cin>>c;
  while(c--){
    are = 0;
    cin>>n;
    p.clear();
    for(int i=0; i<n; i++){
      cin>>x>>y>>a>>b>>t;
      are += a*b;
      t *= pi/180;
      p.push_back(point(x-a/2*sin(pi/2-t)-b/2*sin(t), y+a/2*cos(pi/2-t)-b/2*cos(t)));
      p.push_back(point(x-a/2*sin(pi/2-t)+b/2*sin(t), y+a/2*cos(pi/2-t)+b/2*cos(t)));
      p.push_back(point(x+a/2*sin(pi/2-t)-b/2*sin(t), y-a/2*cos(pi/2-t)-b/2*cos(t)));
      p.push_back(point(x+a/2*sin(pi/2-t)+b/2*sin(t), y-a/2*cos(pi/2-t)+b/2*cos(t)));
    }
    cout<<setprecision(1)<<fixed<<are/area(CH(p))*100<<" %\n";
  }
}