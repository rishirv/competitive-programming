#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int n, m, c, arr[100001];
ifstream fin ("convention.in");
ofstream fout ("convention.out");

int trywait(int t){
  int maxwait = 0, buses = 0, cows = 0, earliest = arr[0];
  for(int i=0; i<n; i++){
    if(arr[i]-earliest > t){
      buses++;
      cows = 1;
      maxwait = max(maxwait, arr[i-1] - earliest);
      earliest = arr[i];
      if(buses == m) return -1;
    } else{
      cows++;
      if(cows == c || i == n-1){
        buses++;
        cows = 0;
        maxwait = max(maxwait, arr[i] - earliest);
        if(i != n-1) earliest = arr[i+1];
      }
    }
    if(buses == m && i != n-1) return -1;
  }
  return maxwait;
}

int main(){
  fin>>n>>m>>c;
  for(int i=0; i<n; i++) fin>>arr[i];
  sort(arr, arr+n);
  int lo = 0, hi = 1000000001, mid;
  while(hi - lo > 1){
    mid = (lo + hi)/2;
    int x = trywait(mid);
    if(x >= 0){
      hi = x;
    } else{
      lo = mid;
    }
  }
  if(trywait(lo) >= 0) fout<<lo<<'\n';
  else fout<<hi<<'\n';
}