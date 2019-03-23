/*
ID: verma.r1
PROG: race3
LANG: C++11
*/

#include <fstream>
#include <deque>
#include <vector>
using namespace std;

ifstream cin ("race3.in");
ofstream cout ("race3.out");

vector<int> to[50];
vector<int> from[50];
vector<int> unavoidable;
vector<int> splitting;
int n=0;

void isSplitting(int x, bool visit0[]){
  deque<int> d;
  bool visited[n] {false};
  d.push_back(x);
  
  while(!d.empty()){
    int last = d.back();
    d.pop_back();
    
    for(int i: to[last]){
      if(visit0[i]){
        return;
      }
      if(!visited[i] && !(i == n-1)){
        visited[i]=true;
        d.push_back(i);
      }
    }
  }
  splitting.push_back(x);
}

void isUnavoidable(int x){
  deque<int> d;
  bool visited[n] {false};
  visited[0]=true;
  d.push_back(0);
  while(!d.empty()){
    int last = d.back();
    d.pop_back();
    
    for(int i: to[last]){
      if(i == n-1){
        return;
      }
      
      if(!visited[i] && !(i == x)){
        visited[i]=true;
        d.push_back(i);
      }
    }
  }

  unavoidable.push_back(x);
  isSplitting(x, visited);
}

int main(){
  int x;
  while(true){
    cin>>x;
    if(x==-2)
      ++n;
    else if(x==-1)
      break;
    else{
      to[n].push_back(x);
      from[x].push_back(n);
    }
  }
  
  for(int i=1; i<n; i++){
    isUnavoidable(i);
  }
  
  cout<<unavoidable.size();
  for(int i : unavoidable){
    cout<<' '<<i;
  }
  cout<<endl;

  cout<<splitting.size();
  for(int i : splitting){
    cout<<' '<<i;
  }
  cout<<endl;
}