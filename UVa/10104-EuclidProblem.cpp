//Euclidean Algorithm
//Extended Euclid
//Linear Diophantine
//Math
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;

int a, b, x, y, d, m;

void euclid(int a, int b){
  if(b == 0){
    x=1;
    y=0;
    d=a;
  } else{
    euclid(b, a%b);
    int t = y;
    y = x - (a/b)*y;
    x = t;
  }
}

int main(){
  while(cin>>a>>b){
    euclid(a, b);
    m = (int) abs(x) + (int) abs(y);
    cout<<x<<' '<<y<<' '<<d<<'\n';
  }
}