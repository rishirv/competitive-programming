#include <fstream>
#include <iomanip>
#include <algorithm>
using namespace std;

long n, w;

// int main() {
//   cin>>w>>n;
//   long arr[n][w], v[n], we[n];
//   for(int i=0; i<n; i++){
//     cin>>v[i]>>we[i];
//   }
//   for(int i=0; i<n; i++){
//     for(int j=0; j<w; j++){
//       arr[i][j] = max(i>=1 ? arr[i-1][j] : 0, j>= we[i] ? (i>=1 ? arr[i-1][j-we[i]] : 0) + v[i] : 0);
//     }
//   }
//   cout<<arr[n-1][w-1]<<endl;
// }

ifstream cin("in.txt");
ofstream cout("out.txt");

double arr[2000000];

int main() {
  cin>>w>>n;
  int v[n], we[n];
  for(int i=0; i<n; i++){
    cin>>v[i]>>we[i];
  }
  for(int i=0; i<n; i++){
    for(int j=w-1; j>=we[i]; j--){
      arr[j] = max(arr[j], arr[j-we[i]] + v[i]);
    }
  }
  cout<<fixed<<arr[w-1]<<endl;
}