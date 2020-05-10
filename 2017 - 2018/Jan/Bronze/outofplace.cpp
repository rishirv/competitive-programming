#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  ifstream cin("outofplace.in");
  ofstream cout("outofplace.out");
  
  int prev = 0, cow, numCows, n=0, bessie=0, pos=-1, x;
  vector<int> a, cows;
  cin>>numCows;
  
  for(int i=0; i<numCows; i++){
    cin>>cow;
    if(cow != prev){
      prev = cow;
      cows.push_back(cow);
      n++;
    }
  }
  
  for(int i=0; i<n; i++){
    x = cows[i];
    cows.erase(cows.begin()+i);
    a=cows;
    sort(a.begin(), a.end());
    if(cows == a){
      bessie = x;
      pos = i;
    }
    cows.insert(cows.begin()+i, x);
  }
  
  if(bessie == 0){ //Cows in sorted order
    cout<<0<<endl;
    return 0;
  }

  int minGreater = n+1, maxLess=-1;
  
  for(int i=0; i<n; i++){
    if(cows[i] < bessie){
      maxLess = i;
    }
  }
  
  for(int i=n-1; i>=0; i--){
    if(cows[i] > bessie){
      minGreater = i;
    }
  }

  if(pos > minGreater){
    cout<<pos - minGreater<<endl;
  }
  else if(pos < maxLess){
    cout<<maxLess-pos<<endl;
  }

  return 0;
}