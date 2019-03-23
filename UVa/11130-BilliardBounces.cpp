//Easy math
#include <iostream>
#include <algorithm>
#include <math.h>
#include <cstring>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
#define PI 3.14159265358979323846 

int a, b, v, t, s;
double r;

int main(){
  while(cin>>a>>b>>v>>t>>s && a!=0){
    r = v*s/2.0;
    cout<<floor(r*cos(t*PI/180.0)/a+0.5)<<' '<<floor(r*sin(t*PI/180.0)/b+0.5)<<'\n';
  }
}