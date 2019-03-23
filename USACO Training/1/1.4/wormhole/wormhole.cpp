/*
ID: verma.r1
PROG: wormhole
LANG: C++11
*/
#include <fstream>
#include <set>
using namespace std;

int n, count=0, pairs[13] {0}, x[13], y[13];
ifstream fin ("wormhole.in");
ofstream fout ("wormhole.out");

void loop(void){
  for(int i=1; i<=n; i++){
    set<int> loop;
    int start=i, end;
    fout<<start<<endl;
    loop.insert(start);
    while(true){
      end=pairs[start]; //Starts has a wormhole to end
      fout<<end<<endl;
      if(!loop.insert(end).second){ //End is already in the set
        count+=1;
        fout<<"yay!"<<endl;
        return;
      }
      int mp = 0;
      for(int j=1; j<=n; j++){
        if(y[j]==y[end]&&(mp==0||x[j]<x[mp])&&x[j]>x[end])
          mp=j;
      }
      if(mp==0)
        fout<<"broke"<<endl;
        break;
      start=mp;
      fout<<start<<endl;
      if(!loop.insert(start).second){ //Start is already in the set
        count+=1;
        fout<<"yay!"<<endl;
        return;
      }
    }
  }
  return;
}

void pairing(int x){
  if(x==n/2){
    fout<<pairs[0]<<pairs[1]<<pairs[2]<<pairs[3]<<pairs[4]<<pairs[5]<<pairs[6]<<endl;
    loop();
  }
  else{
    int i;
    for(i=1; i<n; i++){
      if(pairs[i]==0)
        break;
    }
    for(int j=i+1; j<=n; j++){
      if(pairs[j]==0){ 
        pairs[i]=j;
        pairs[j]=i;
        pairing(x+1);
        pairs[i]=0;
        pairs[j]=0;
      }
    }
  }
}

int main(){
  int a, b, count=0;
  fin>>n;
  for(int i=1; i<=n; i++){
    fin>>a>>b;
    x[i]=a;
    y[i]=b;
  }
  pairing(0);
  fout<<::count<<endl;
}