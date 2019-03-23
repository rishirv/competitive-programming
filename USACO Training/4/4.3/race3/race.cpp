/*
ID: verma.r1
PROG: race3
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <queue>
#include <deque>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int main(){
  ifstream cin ("race3.in");
  ofstream cout ("race3.out");

  int n=0, x=0, i;
  queue<int> points;
  bool visited[50] {0};
  
  bool arr[50][50] {{0}};
  
  while(true){
    cin>>x;
    if(x==-2)
      ++n;
    else if(x==-1)
      break;
    else
      arr[n][x]=1;
  }
  
  i=0;
  bool thisGroup[50] {0}, prevPoints[50] {0}, flag=true, alreadyPopped=false;;
  vector<int> unvoidPoints;
  deque<int> isSplitPoint;

  do{
    if(points.empty() && i!=0){
      points.push(i);
      unvoidPoints.push_back(i);
      if(flag){
        isSplitPoint.push_back(i);
      }
      for(int i=0; i<=n; i++){
        prevPoints[i] |= thisGroup[i];
      }
      memset(thisGroup, 0, sizeof(thisGroup));
      flag=true;
      alreadyPopped=false;
    }

    for(int j=0; j<n; j++){
      if(arr[i][j] && !visited[j]){
        visited[j]=1;
        points.push(j);
        thisGroup[j]=1;
      } else if(arr[i][j] && thisGroup[j]==0){
        if(prevPoints[j]){
          if(!alreadyPopped){
            isSplitPoint.pop_back();
            alreadyPopped=true;
          }
        } else{
          flag=false;
        }
      }
    }

    i=points.front();
    points.pop();
  } while(i!=n-1);
  
  if(!unvoidPoints.empty())
    cout<<unvoidPoints.size()<<" ";
  else
    cout<<unvoidPoints.size()<<endl;

  for(int i=0; !unvoidPoints.empty() && i<unvoidPoints.size()-1; i++){
    cout<<unvoidPoints[i]<<" ";
  }
  
  if(!unvoidPoints.empty()){
    cout<<unvoidPoints[unvoidPoints.size()-1]<<endl;
  }
  
  if(!isSplitPoint.empty())
    cout<<isSplitPoint.size()<<" ";
  else
    cout<<isSplitPoint.size()<<endl;

  while(!isSplitPoint.empty()){
    cout<<isSplitPoint.front();
    isSplitPoint.pop_front();
    if(isSplitPoint.empty()){
      cout<<endl;
      break;
    } else{
      cout<<" ";
    }
  }
}