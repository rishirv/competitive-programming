/*
ID: verma.r1
PROG: ratios
LANG: C++11
*/
#include <fstream>
using namespace std;

int a[3][3], b[3], sum=300;

int yay(int v[]){
  if((v[0]+v[1]+v[2]>=sum) || (!v[0]&&!v[1]&&!v[2]))
    return 0;
  int x[3] {0, 0, 0}, l=0;
  for(int r=0; r<3; r++)
    for(int s=0; s<3; s++)
      x[r]+=v[s]*a[s][r];
  for(int r=0; r<3; r++){
    if(b[r]==0){
      if(x[r]==0)
        continue;
      return 0;
    }
    if(x[r]%b[r]==0 && x[r]!=0)
      if(l==0 || l==x[r]/b[r])
        l=x[r]/b[r];
      else
        return 0;
    else
      return 0;
  }
  return l;
}

int main(){
  ifstream cin ("ratios.in");
  ofstream cout ("ratios.out");
  int x[3], w, temp[3];
  for(int i=0; i<3; i++)
    cin>>b[i];
  for(int i=0; i<3; i++)
    for(int j=0; j<3; j++)
      cin>>a[i][j];
  for(temp[0]=0; temp[0]<100; temp[0]++){
    for(temp[1]=0; temp[1]<100; temp[1]++){
      for(temp[2]=0; temp[2]<100; temp[2]++){
        int l=yay(temp);
        if(l){
          for(int i=0; i<3; i++)
            x[i]=temp[i];
          w=l;
          sum=x[0]+x[1]+x[2];
        }
      }
    }
  }
  if(sum==300)
    cout<<"NONE"<<endl;
  else
    cout<<x[0]<<" "<<x[1]<<" "<<x[2]<<" "<<w<<endl;
}