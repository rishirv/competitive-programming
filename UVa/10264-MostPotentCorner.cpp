#include <iostream>
#include <cstring>
#include <math.h>
#include <algorithm>
using namespace std;

int arr[40000], pot[40000], n, m;

int main() {
  while(cin>>n){
    memset(pot, 0, sizeof pot);
    m = 0;
    for(int i=0; i<pow(2, n); i++) cin>>arr[i];
    for(int i=0; i<pow(2, n); i++)
      for(int k=0; k<n; k++)
        pot[i] += arr[i ^ 1<<k];
    for(int i=0; i<pow(2, n); i++)
      for(int k=0; k<n; k++)
        m = max(m, pot[i] + pot[i ^ 1<<k]);
    cout<<m<<endl;
  }
}