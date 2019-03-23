//Suffix Tree
//Suffix Trie
//Suffix Array
//LCS Longest Common Substring
//Counting Sort
//String
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;

string s, a, b;
bool f;
int n;
int RA[1000], tempRA[1000];
int SA[1000], tempSA[1000];
int Phi[1000], LCP[1000], PLCP[1000];
int owner[1000];
int c[1000];
vector<string> vs;

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
    while(s[i+L] == s[Phi[i]+L]) L++;
    PLCP[i] = L;
    L = max(L-1, 0);
  }
  for(int i=0; i<n; i++) LCP[i] = PLCP[SA[i]];
}

void computeLCS(){
  int i, m=0;
  for(int i=0; i<n; i++)
    owner[i] = (SA[i] < a.size()+1 ? 1 : 2);
  for(int i=1; i<n; i++)
    if(owner[i]!=owner[i-1]) m=max(m, LCP[i]);
  if(m == 0) cout<<"No common sequence.\n";
  else{
    for(int i=0; i<n; i++){
      if(owner[i]!=owner[i-1] && LCP[i] == m)
        vs.push_back(s.substr(SA[i], m));
    }
    auto last = unique(vs.begin(), vs.end());
    for(auto it = vs.begin(); it!=last; it++)
      cout<<*it<<'\n';
  }
}

int main(){
  while(getline(cin, a) && getline(cin, b)){
    cin.ignore();
    vs.clear();
    if(f) cout<<'\n';
    f = true;
    s = a + "$" + b +"#";
    n = s.length();
    constructSA();
    computeLCP();
    computeLCS();
  }
}