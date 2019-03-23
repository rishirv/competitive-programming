#include <fstream>
#include <string>
using namespace std;

bool changed(int amts[], bool winners[]){
  int max=amts[0];
  bool didChange=false;
  
  for(int i=0; i<3; i++){
    if(amts[i]>max){
      max=amts[i];
    }
  }
  
  for(int i=0; i<3; i++){
    bool dummy = false;
    if(amts[i]==max){
      dummy = true;
    }
    if(winners[i] != dummy){
      didChange=true;
    }
    winners[i] = dummy;
  }
  
  return didChange;
}

int main(){
  ifstream cin("measurement.in");
  ofstream cout("measurement.out");

  int n, count=0;
  cin>>n;
  
  string s;
  int x, a, amts[3] {7, 7, 7} , cows[101] {0}, changes[101] {0};
  bool winners[3];

  for(int i=0; i<3; i++){
    amts[i]=7;
    winners[i]=true;
  }

  for(int i=0; i<101; i++){
    cows[i]=0;
    changes[i]=0;
  }

  for(int i=0; i<n; i++){
    cin>>x>>s>>a;
    changes[x]=a;
    if(s=="Bessie"){
      cows[x]=0;
    } else if(s=="Elsie"){
      cows[x]=1;
    } else if(s=="Mildred"){
      cows[x]=2;
    } else{
      return -1;
    }
  }
  
  for(int i=1; i<=100; i++){
    amts[cows[i]] += changes[i];
    if(changed(amts, winners)){
      count++;
    }
  }
  
  cout<<count<<endl;
  return 0;
}