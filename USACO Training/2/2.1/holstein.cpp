/*
ID: verma.r1
PROG: holstein
LANG: C++11
*/
#include <fstream>
#include <vector>
using namespace std;

int v, g, n, vitamins[25], feed[15][25];
vector<int> feedList;

ifstream cin ("holstein.in");
ofstream cout ("holstein.out");

bool process_tuple(){
  for(int j=0; j<v; j++){
    int x=0;
    for(int i : feedList){
      x+=feed[i][j];
    }
    if(x<vitamins[j]){
      return false;
    }
  }
  return true;
}

bool construct_tuple(int x=n, int i=0){
  if(x==0){
    if(process_tuple()){
      cout<<n<<" ";
      for(i=0; i<feedList.size()-1; i++){
        cout<<feedList[i]+1<<" ";
      }
      cout<<feedList[i]+1<<endl;
      return true;
    }
    return false;
  }
  for(;i<g+1-x; i++){
    feedList.push_back(i);
    if(construct_tuple(x-1, i+1))
      return true;
    feedList.pop_back();
  }
  return false;
}

int main(){
  cin>>v;
  int temp[25];
  
  for(int i=0; i<v; i++){
    cin>>vitamins[i];
  }

  cin>>g;
  
  for(int i=0; i<g; i++){
    for(int j=0; j<v; j++){
      cin>>feed[i][j];
    }
  }
  
  for(int i=1; i<=g; i++){
    n=i;
    if(construct_tuple()){
      break;
    }
  }
}