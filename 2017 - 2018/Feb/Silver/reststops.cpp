#include <fstream>
using namespace std;

int main() {
  ifstream cin ("reststops.in");
  ofstream cout ("reststops.out");

  int l, n, rf, rb;
  cin>>l>>n>>rf>>rb;
  
  long long tastiness[n], position[n], maxTaste, maxPos=-1, t=0, grass=0, timeSpent;
  
  for(int i=0; i<n; i++)
    cin >> position[i] >> tastiness[i];
  
  while(true){
    maxTaste = 0;
    for(int i = maxPos+1; i<n; i++){
      if(tastiness[i] >= maxTaste){
        maxTaste = tastiness[i];
        maxPos = i;
      }
    }

    timeSpent = (rf-rb)*position[maxPos] - t;
    t += timeSpent;
    grass += maxTaste*timeSpent;
    if(maxPos==n-1) break;
  }
  
  cout<<grass<<endl;
  return 0;
}