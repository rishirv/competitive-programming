#include <iostream>
#include <fstream>
#include <deque>
#include <algorithm>
using namespace std;

#define pii pair<int, int>

int n;
deque<pii> q, r;
ifstream fin ("in.txt");

pii findMin(){
  pii x;
  if(r.size()==0 || (q.size()>0 && q.front().first < r.front().first)){
    x = q.front();
    q.pop_front();
  } else{
    x = r.front();
    r.pop_front();
  }
  return x;
}

bool comp(pii a, pii b){ 
  return a.first < b.first;
}

int main() {
  int a;
  fin>>n;
  for(int i=0; i<n; i++){
    fin>>a;
    q.push_back(make_pair(a, 0));
  }

  sort(q.begin(), q.end(), comp);
  pii i, j;

  while(q.size() + r.size() >= 2){
    i = findMin(), j = findMin();
    r.push_back(make_pair(i.first+j.first, max(i.second, j.second)+1));
  }

  cout<<r.front().second<<endl;
}