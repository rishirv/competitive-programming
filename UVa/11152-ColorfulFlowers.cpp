//Triangle area
//Circle
//Geometry
#include <iostream>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

double a, b, c, s, r, R, x, y, z, pi = acos(-1.0);

double area(){
  return sqrt(s*(s-a)*(s-b)*(s-c));
}

int main(){
  while(cin>>a>>b>>c){
    s = 0.5*(a+b+c);
    y = area();
    r = y/s;
    z = pi*r*r;
    R = a*b*c/4/y;
    x = pi*R*R;
    x -= y;
    y -= z;
    cout<<fixed<<setprecision(4)<<x<<' '<<y<<' '<<z<<'\n';
  }
}