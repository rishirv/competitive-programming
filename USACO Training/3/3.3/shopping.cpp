/*
ID: verma.r1
PROG: shopping
LANG: C++11
*/
#include <fstream>
#include <algorithm>
using namespace std;

int arr[6][6][6][6][6], code[1000], amt[6], prc[6], s, b, coden, x, o[99][7];

int encode(int n){
  if(!code[n])
    code[n]=++coden;
  return code[n];
}

int main(){
  ifstream cin ("shopping.in");
  ofstream cout ("shopping.out");

  cin>>s;
  for(int i=0; i<s; i++){
    cin>>b;
    for(int j=0; j<b; j++){
      cin>>x;
      cin>>o[i][encode(x)];
    }
    cin>>o[i][6];
  }
  cin>>b;

  int y, z;

  for(int i=0; i<b; i++){
    cin>>x>>y>>z;
    amt[encode(x)]=y;
    prc[encode(x)]=z;
  }
  
  for(int a=0; a<=amt[1]; a++){
    for(int b=0; b<=amt[2]; b++){
      for(int c=0; c<=amt[3]; c++){
        for(int d=0; d<=amt[4]; d++){
          for(int e=0; e<=amt[5]; e++){
            arr[a][b][c][d][e]=999*25;
            arr[0][0][0][0][0]=0;
            for(int i=0; i<s; i++)
              if(a>=o[i][1] && b>=o[i][2] && c>=o[i][3] && d>=o[i][4] && e>=o[i][5])
                arr[a][b][c][d][e]=min(arr[a][b][c][d][e], arr[a-o[i][1]][b-o[i][2]][c-o[i][3]][d-o[i][4]][e-o[i][5]] + o[i][6]);
            if(a>0)
              arr[a][b][c][d][e]=min(arr[a][b][c][d][e], arr[a-1][b][c][d][e]+prc[1]);
            if(b>0)
              arr[a][b][c][d][e]=min(arr[a][b][c][d][e], arr[a][b-1][c][d][e]+prc[2]);
            if(c>0)
              arr[a][b][c][d][e]=min(arr[a][b][c][d][e], arr[a][b][c-1][d][e]+prc[3]);
            if(d>0)
               arr[a][b][c][d][e]=min(arr[a][b][c][d][e], arr[a][b][c][d-1][e]+prc[4]);
            if(e>0)
              arr[a][b][c][d][e]=min(arr[a][b][c][d][e], arr[a][b][c][d][e-1]+prc[5]);
          }
        }
      }
    } 
  }
  cout<<arr[amt[1]][amt[2]][amt[3]][amt[4]][amt[5]]<<endl;
}