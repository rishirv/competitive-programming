//Circles in a rectangle
//Geometry
#include <iostream>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

int a, b, c, d;

int main(){
  while(cin>>a>>b>>c>>d && a != 0){
    if(a>=2*max(c, d) && b>=2*max(c,d) && (a-c-d)*(a-c-d)+(b-c-d)*(b-c-d) >= (c+d)*(c+d)){
      cout<<"S\n";
    } else{
      cout<<"N\n";
    }
  }
}