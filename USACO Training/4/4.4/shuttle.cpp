/*
ID: verma.r1
PROG: shuttle
LANG: C++11
*/

#include <fstream>
#include <vector>
using namespace std;

ifstream cin ("shuttle.in");
ofstream cout ("shuttle.out");

int main() {
  int n, c = 1;
  cin>>n;
  vector<int> moves;
  moves.push_back(1);
  while(c<n){
    for(int i=0; i<moves.size(); i++) ++moves[i];
    c++;
    if(c%2==1){
      for(int i=2*c-2; i>=2; i-=2) moves.push_back(i);
      moves.push_back(1);
    } else{
      for(int i=4; i<=2*c; i+=2) moves.push_back(i);
      moves.push_back(2*c+1);
    }
  }
  if(n%2==1){
    for(int i=3; i<=2*n+1; i+=2) moves.push_back(i);
  } else{
    for(int i=2*n-1; i>=1; i-=2) moves.push_back(i);
  }
  for(int i = n*(n+1)/2-2; i>=0; i--){
    moves.push_back(2*(n+1)-moves[i]);
  }
  moves.push_back(n+1);
  for(int i=0; i<moves.size(); i++) {
    if(i%20 != 0){ 
      cout<<" ";
    } else if(i != 0){
      cout<<endl;
    }
    cout<<moves[i];
  }
  cout<<endl;
}