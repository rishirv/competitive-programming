//Knuth-Morris-Pratt
//KMP
//String Matching
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;

string a, b;
int n, back[100010];

void kmpPre(){
  int i=0, j=-1;
  back[0]=-1;
  while(i<n){
    while(j>=0 && b[i]!=b[j]) j = back[j];
    i++;
    j++;
    back[i]=j;
  }
}

int kmpSearch(){
  int i=0, j=0;
  while(i<n){
    while(j>=0 && a[i]!=b[j]){
      j=back[j];
    }
    i++; j++;
  }
  return j;
}

int main(){
  while(cin>>a){
    b = a;
    n = a.size();
    reverse(b.begin(), b.end());
    kmpPre();
    cout<<a<<b.substr(kmpSearch())<<'\n';
  }
}