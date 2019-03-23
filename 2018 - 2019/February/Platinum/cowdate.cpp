#include <fstream>
#include <algorithm>
#include <math.h>
using namespace std;

double arr[1000000], opp[1000000], pre[10000000], n, mx;

ifstream cin ("cowdate.in");
ofstream cout ("cowdate.out");

int main() {
  cin>>n;
  pre[0] = opp[0] = 1;
  for(int i=1; i<=n; i++){
    cin>>arr[i];
    arr[i] /= 1000000;
    opp[i] = 1 - arr[i];
    pre[i] = pre[i-1]*opp[i];
  }
  int j = 2;
  for(int i=1; i<=n; i++){
    j = 0;
    double p = 0, q = arr[i];
    while(q>p && i+j <= n){
      p = q;
      ++j;
      q = p*opp[i+j] + arr[i+j]*pre[i+j-1]/pre[i-1];
    }
    mx = max(mx, p);
  }
  cout<<(int) floor(mx*1000000)<<endl;
}