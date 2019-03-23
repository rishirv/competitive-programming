#include <fstream>
#include <algorithm>
using namespace std;

int arr[100000], n, sum, m, k[100000], nk=1;
double avg, tmp;

ifstream cin("homework.in");
ofstream cout ("homework.out");

int main() {
  cin>>n;
  for(int i=0; i<n; i++) cin>>arr[i];
  sum = arr[n-1] + arr[n-2];
  m = min(arr[n-1], arr[n-2]);
  avg = sum-m;
  k[0] = n-2;
  for(int j=n-3; j>=1; j--){
    m = min(m, arr[j]);
    sum += arr[j];
    tmp = (sum-m)/((double) n-j-1);
    if(tmp >= avg){
      if(tmp > avg) nk=0;
      avg = tmp;
      k[nk++] = j;
    }
  }

  for(int i=nk-1; i>=0; i--) cout<<k[i]<<'\n';
}