//Suffix Tree
//Suffix Trie
//Suffix Array
//LCS Longest Common Substring
//Counting Sort
//String
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

ifstream cin ("standingout.in");
ofstream cout ("standingout.out");

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;

string s="", a;
int n, m;
int RA[210000], tempRA[210000];
int SA[210000], tempSA[210000];
int Phi[210000], LCP[210000], PLCP[210000];
int owner[210000], len[210000], val[210000];
int c[210000];

void countingSort(int k){
  int i, sum, maxi = max(300, n);
  memset(c, 0, sizeof c);
  for(i=0; i<n; i++) c[i+k<n ? RA[i+k] : 0]++;
  for(i = sum = 0; i<maxi; i++){
    int t = c[i];
    c[i] = sum;
    sum += t;
  }
  for(i=0; i<n; i++)
    tempSA[c[SA[i]+k<n ? RA[SA[i]+k] : 0]++] = SA[i];
  for(i=0; i<n; i++) SA[i] = tempSA[i];
}

void constructSA(){
  int i, k, r;
  for(i=0; i<n; i++) RA[i] = s[i];
  for(i=0; i<n; i++) SA[i] = i;
  for(k=1; k<n; k<<=1){
    countingSort(k);
    countingSort(0);
    tempRA[SA[0]] = r = 0;
    for(i=1; i<n; i++)
      tempRA[SA[i]] = (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;
    for(int i=0; i<n; i++) RA[i] = tempRA[i];
    if(RA[SA[n-1]] == n-1) break;
  }
}

void computeLCP(){
  int i, L;
  Phi[SA[0]] = -1;
  for(i=1; i<n; i++) Phi[SA[i]] = SA[i-1];
  for(i=L=0; i<n; i++){
    if(Phi[i] == -1){
      PLCP[i] = 0;
      continue;
    }
    while(s[i+L] == s[Phi[i]+L] and s[i+L] != '?') L++;
    PLCP[i] = L;
    L = max(L-1, 0);
  }
  for(i=0; i<n; i++) LCP[i] = PLCP[SA[i]];
}

void computeUnique(){
  int i, l, r, k;
  for(i=0; i<n; i++)
    owner[i] = upper_bound(len, len+m, SA[i])-len;
  for(i=0; i<n; i++){
    l = LCP[i];
    for(int j=i-1; j>=0; j--){
      if(owner[j] != owner[i]) break;
      l = min(l, LCP[j]);
    }
    r = LCP[i+1];
    for(int j=i+1; j<n; j++){
      r = min(r, LCP[j]);
      if(owner[j] != owner[i]) break;
    }
    k = max(LCP[i], l);
    k = max(k, r);
    val[owner[i]] -= k;
  }
}

int main(){
  cin>>m;
  for(int i=0; i<m; i++){
    cin>>a;
    n = a.length();
    s += a+'?';
    len[i] = (i>0 ? len[i-1] : 0) + n+1;
    if(n & 1) val[i] = n*((n+1)/2);
    else val[i] = (n/2)*(n+1);
  }
  n = s.length();
  constructSA();
  computeLCP();
  computeUnique();
  for(int i=0; i<m; i++) cout<<val[i]<<'\n';
}