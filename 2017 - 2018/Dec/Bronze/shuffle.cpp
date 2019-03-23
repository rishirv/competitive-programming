#include <fstream>
using namespace std;

void rev(int order[], int shuffle[], int n){
  int newShuffle[n+1];
 
  for(int i=1; i<=n; i++){
    newShuffle[shuffle[i]]=order[i];
  }
 
  for(int i=1; i<=n; i++){
    order[i]=newShuffle[i];
  }
}

int main(){
  ifstream cin("shuffle.in");
  ofstream cout ("shuffle.out");

  int n;
  cin>>n;
  
  int shuffle[n+1];

  for(int i=1; i<=n; i++){
    cin>>shuffle[i];
  }
  
  int order[n+1];
  for(int i=1; i<=n; i++){
    cin>>order[i];
  }
  
  int revS[n+1];
  for(int i=1; i<=n; i++){
    revS[shuffle[i]]=i;
  }
  
  for(int i=0; i<3; i++){
    rev(order, revS, n);
  }
  
  for(int i=1; i<=n; i++){
    cout<<order[i]<<endl;
  }
}