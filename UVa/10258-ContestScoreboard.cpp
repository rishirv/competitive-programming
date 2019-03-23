#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

struct m{
  int cont, time[10], correct[10], t, p;
  bool u;

  bool operator <(m &r){
    if(u && r.u){
      if(p == r.p){
        if(t == r.t){
          return cont < r.cont;
        }
        return t < r.t;
      }
      return p > r.p;
    }
    if(u) return true;
    return false;
  }
} arr[102];
char str[100];

int a, b, c;
char d;

int main() {
  int n;
  scanf("%d", &n);
  fgets(str, 100, stdin);
  fgets(str, 100, stdin);


  for(int i=0; i<n; i++){
    memset(arr, 0, sizeof arr);
    for(int j=1; j<=100; j++) arr[j].cont = j;

    while(fgets(str, 100, stdin) && strlen(str) > 1){
      sscanf(str, "%d %d %d %c", &a, &b, &c, &d);
      arr[a].u = true;
      if(d == 'C' && arr[a].correct[b] == 0){
        arr[a].correct[b] = c;
        arr[a].time[b] += c;
      } else if(d == 'I' && (c < arr[a].correct[b] || arr[a].correct[b] == 0)){
        arr[a].time[b] += 20;
      }
    }

    for(int j=1; j<=100; j++){
      for(int k=1; k<10; k++){
        if(arr[j].correct[k]){
          arr[j].t += arr[j].time[k];
          arr[j].p++;
        }
      }
    }

    sort(arr+1, arr+101);
    for(int j=1; j<=100; j++){
      if(arr[j].u){
        cout<<arr[j].cont<<' '<<arr[j].p<<' '<<arr[j].t<<endl;
      }
    }
    if(i < n-1) cout<<endl;
  }
}