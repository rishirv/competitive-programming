//Greedy
//Geometry
#include <iostream>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

int a, b, arr[900], n, c, t;
double f, l;

int main(){
  while(cin>>a>>b && a!= 0){
    n=a*b;
    for(int i=0; i<n; i++) cin>>arr[i];
    cin>>f;
    sort(arr, arr+n);
    f /= 100;
    c = f == 0 ? 0 : 1;
    l = arr[0];
    for(int i=0; i<n-1; i++){
      if(f/c+arr[i] <= arr[i+1]){
        l = f/c + arr[i];
        f = 0;
        break;
      } else{
        f -= c*(arr[i+1]-arr[i]);
        c++;
      }
    }
    if(f > 0){
      l = f/c + arr[n-1];
    }
    cout<<"Region "<<(++t)<<'\n';
    cout<<setprecision(2)<<fixed<<"Water level is "<<l<<" meters.\n";
    cout<<setprecision(2)<<fixed<<(100* (double) c)/n<<" percent of the region is under water.\n\n";
  }
}