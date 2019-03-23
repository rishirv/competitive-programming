#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

ifstream cin ("mowing.in");
ofstream cout ("mowing.out");

struct point{
  long long x, y;
  point(int _x, int _y) : x(_x), y(_y) {}
  bool operator < (point other) const {
    return x < other.x || (x == other.x && y < other.y);
  }
};

long long n, t, x, y;
long long dp[1000010], d[1000010]; 
vector<point> v;

int main() {
  cin>>n>>t;
  for(int i=0; i<n; i++){
    cin>>x>>y;
    v.push_back(point(x, y));
  }
  sort(v.begin(), v.end());
  for(int i=0; i<n; i++){
    dp[i] = v[i].x*v[i].y + (t-v[i].x)*(t-v[i].y);
    d[i] = 1;
    for(int j=0; j<i; j++){
      if(v[j].y < v[i].y && d[j]+1>d[i]){
        dp[i] = dp[j] - (v[i].x - v[j].x)*(t-v[i].y) - (v[i].y - v[j].y)*(t-v[i].x);
        d[i] = d[j]+1;
      } else if(v[j].y < v[i].y && d[j]+1==d[i]){
        dp[i] = min(dp[i], dp[j] - (v[i].x - v[j].x)*(t-v[i].y) - (v[i].y - v[j].y)*(t-v[i].x));
      }
    }
  }
  x = 0, y=0;
  for(int i=0; i<n; i++){
    if(d[i]>y){
      x = dp[i];
      y = d[i];
    } else if(d[i] == y){
      x = min(dp[i], x);
    }
  }
  cout<<x<<'\n';
}