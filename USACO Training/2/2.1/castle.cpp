/*
ID: verma.r1
PROG: castle
LANG: C++11
*/
#include <fstream>
#include <string>
#include <vector>
using namespace std;

string bi(int n, string s="", int x=0){
  if(x==4)
     return s;
  return bi(n/2, s+char(!(n%2)+'0'), x+1);
}

int r, c, rooms[52][52];
string walls[52][52];

int adj(int i, int j, int num){
  int count=0;
  rooms[i][j]=num;
  if(!rooms[i][j+1]&&walls[i][j][2]=='1'&&walls[i][j+1][0]=='1'){
    rooms[i][j+1]=num;
    count+=adj(i, j+1, num)+1;
  }
  if(!rooms[i][j-1]&&walls[i][j][0]=='1'&&walls[i][j-1][2]=='1'){
    rooms[i][j-1]=num;
    count+=adj(i, j-1, num)+1;
  }
  if(!rooms[i+1][j]&&walls[i][j][3]=='1'&&walls[i+1][j][1]=='1'){
    rooms[i+1][j]=num;
    count+=adj(i+1, j, num)+1;
  }
  if(!rooms[i-1][j]&&walls[i][j][1]=='1'&&walls[i-1][j][3]=='1'){
    rooms[i-1][j]=num;
    count+=adj(i-1, j, num)+1;
  }
  return count;
}

int main(){
  ifstream cin ("castle.in");
  ofstream cout ("castle.out");
  int z, num=0, maxSize=0;
  vector<int> vecA, vecB;
  vector<char> vecC;
  cin>>c>>r;
  for(int i=1; i<=r; i++){
    for(int j=1;j<=c; j++){
      cin>>z;
      walls[i][j]=bi(z);
    }
  }
  int arr[r*c+1];
  int optWall[(r-1)*(c-1)][3];
  for(int i=1; i<=r; i++){
    for(int j=1;j<=c; j++){
      if(rooms[i][j]==0){
        num++;
        z = adj(i,j,num)+1;
        arr[num]=z;
        maxSize=(maxSize<z?z:maxSize);
      }
    }
  }
  arr[0]=-1;
  cout<<num<<endl;
  cout<<maxSize<<endl;
  for(int i=1; i<=r; i++){
    for(int j=1; j<=c; j++){
      if(rooms[i][j]!=rooms[i][j+1]){
        z=arr[rooms[i][j]]+arr[rooms[i][j+1]];
        if(z>maxSize){
          maxSize=z;
          vecA.clear();
          vecB.clear();
          vecC.clear();
          vecA.push_back(i);
          vecB.push_back(j);
          vecC.push_back('E');
        } else if(z==maxSize){
          vecA.push_back(i);
          vecB.push_back(j);
          vecC.push_back('E');
        }
      }
      if(rooms[i][j]!=rooms[i-1][j]){
        z=arr[rooms[i][j]]+arr[rooms[i-1][j]];
        if(z>maxSize){
          maxSize=z;
          vecA.clear();
          vecB.clear();
          vecC.clear();
          vecA.push_back(i);
          vecB.push_back(j);
          vecC.push_back('N');
        } else if(z==maxSize){
          vecA.push_back(i);
          vecB.push_back(j);
          vecC.push_back('N');
        }
      }
    }
  }


  // for(int i : vecA){
  //   cout<<i<<" ";
  // }
  // cout<<endl;
  // for(int i : vecB){
  //   cout<<i<<" ";
  // }
  // cout<<endl;
  // for(char i : vecC){
  //   cout<<i<<" ";
  // }
  // cout<<endl;
  

  z=0;
  for(int i=0; i<vecA.size(); i++){
    if(vecB[i]<vecB[z]){
      z=i;
    } else if(vecB[i]==vecB[z]){
      if(vecA[i]>vecA[z]){
        z=i;
      } else if(vecA[i]==vecA[z]){
        if(vecC[i]=='N'){
          z=i;
        }
      }
    }
  }
  cout<<maxSize<<endl;
  cout<<vecA[z]<<" "<<vecB[z]<<" "<<vecC[z]<<endl;
  // for(int i=1; i<=r; i++){
  //   for(int j=1;j<=c; j++){
  //     cout<<rooms[i][j]<<" ";
  //   }
  //   cout<<endl;
  // }
}