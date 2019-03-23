/*
ID: verma.r1
PROG: charrec
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ifstream font("font.in");
ifstream fin("charrec.in");
ofstream fout("charrec.out");

int n;
int chars[27][20];
int rec[1201];
int corruptions[1201];
int previous[1201];
int s[1201];

int intify(char[]);
void solve(int);
void dist19(int);
void dist20(int);
void dist21(int);
int dist(int, int);
void construct(int);

int main() {
  char line[32];
  font>>n;

  for(int i=0; i<27; i++){
    for(int j=0; j<20; j++){
      font>>line;
      chars[i][j] = intify(line);
    }
  }
  
  fin>>n;
  corruptions[n] = 1;
  previous[n] = -1;

  for(int i=0; i<n; i++){
    fin>>line;
    rec[i] = intify(line);
  }

  for(int i=n-19; i>=0; i--){
    solve(i);
  }

  construct(0);
  fout<<endl;
}

void construct(int i){
  if(previous[i] != -1){
    fout<<(char)(s[i] == 0 ? ' ' : 'a'+s[i]-1);
    construct(previous[i]);
  }
}

int intify(char line[]){
  int j=0;
  for(int i=0; i<20; i++){
    j = j<<1;
    if(line[i]=='1') j |= 1;
  }
  return j;
}

void solve(int l){
  corruptions[l] = 40000;
  if(l+19<=n && corruptions[l+19]){
    dist19(l);
  }
  if(l+20<=n && corruptions[l+20]){
    dist20(l);
  }
  if(l+21<=n && corruptions[l+21]){
    dist21(l);
  }
}

void dist20(int l){
  int m;
  for(int c=0; c<27; c++){
    m = 0;
    for(int i=0; i<20; i++){
      m += dist(rec[l+i], chars[c][i]);
    }
    if(m + corruptions[l+20] < corruptions[l]){
      corruptions[l] = m + corruptions[l+20];
      previous[l] = l+20;
      s[l] = c;
    }
  }
}

void dist19(int l){
  int m;
  for(int line=0; line<20; line++){
    for(int c=0; c<27; c++){
      m = 0;
      for(int i=0; i<line; i++){
        m += dist(rec[l+i], chars[c][i]);
      }
      for(int i=line+1; i<20; i++){
        m += dist(rec[l+i-1], chars[c][i]);
      }
      if(m + corruptions[l+19] < corruptions[l]){
        corruptions[l] = m + corruptions[l+19];
        previous[l] = l+19;
        s[l] = c;
      }
    }
  }
}

void dist21(int l){
  int m;
  for(int line=0; line<20; line++){
    for(int c=0; c<27; c++){
      m = 0;
      for(int i=0; i<line; i++){
        m += dist(rec[l+i], chars[c][i]);
      }
      for(int i=line+1; i<20; i++){
        m += dist(rec[l+i+1], chars[c][i]);
      }

      m += min(dist(rec[l+line], chars[c][line]), dist(rec[l+line+1], chars[c][line]));
      m += dist(rec[l+line], rec[l+line+1]);

      if(m + corruptions[l+21] < corruptions[l]){
        corruptions[l] = m + corruptions[l+21];
        previous[l] = l+21;
        s[l] = c;
      }
    }
  }
}

int dist(int x, int y){
  int d = 0, val = x^y;
  while(val){
    ++d; 
    val &= val - 1;
  }
  return d;
}