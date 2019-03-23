//Points
//Lines
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

int gcd(int a, int b){
  return a == 0 ? (int) abs(b) : gcd(b%a, a);
}

struct point{
  ll x, y, z;
  bool operator < (point o){
    return x*x + y*y < o.x*o.x + o.y*o.y;
  }
};

int n, g, c;
point arr[100000];
map<ii, int> m;
vector<ii> v;

int main(){
  while(cin>>n && n!=0){
    for(int i=0; i<n; i++) cin>>arr[i].x>>arr[i].y>>arr[i].z;
    m.clear();
    v.clear();
    sort(arr, arr+n);
    for(int i=0; i<n; i++){
      g = gcd(arr[i].x, arr[i].y);
      if(m[ii(arr[i].x/g, arr[i].y/g)]){
        if(arr[i].z > m[ii(arr[i].x/g, arr[i].y/g)]){
          m[ii(arr[i].x/g, arr[i].y/g)] = arr[i].z;
        } else{
          v.push_back(ii(arr[i].x, arr[i].y));
        }
      } else{
        m[ii(arr[i].x/g, arr[i].y/g)] = arr[i].z;
      }
    }

    sort(v.begin(), v.end());
    cout<<"Data set "<< ++c << ":\n";
    if(v.size()){
      cout<<"Some lights are not visible:\n";
      for(int i=0; i<v.size()-1; i++){
        cout<<"x = "<<v[i].first<<", "<<"y = "<<v[i].second<<";\n";
      }
      cout<<"x = "<<v[v.size()-1].first<<", "<<"y = "<<v[v.size()-1].second<<".\n";
    } else{
      cout<<"All the lights are visible.\n";
    }
  }
}