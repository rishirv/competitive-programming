/*
ID: verma.r1
PROG: numtri
LANG: C++11
*/
#include <fstream>
#include <algorithm>
using namespace std;

int main(){
  ifstream fin ("numtri.in");
  ofstream fout ("numtri.out");
  int n;
  fin>>n;
  int nums[n*(n+1)/2];
  for(int i=0; i<n*(n+1)/2; i++)
    fin>>nums[i];
  --n;
  for(; n>0; --n)
    for(int i = 0; i<n; i++)
      nums[n*(n-1)/2+i]+=max(nums[n*(n+1)/2+i], nums[n*(n+1)/2+i+1]);
  fout<<nums[0]<<endl;
  return 0;
}