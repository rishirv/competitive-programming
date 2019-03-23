/*
ID: verma.r1
PROG: ariprog
LANG: C++11
*/
#include <fstream>
using namespace std;

int i,j,n,d, bisquares[125002] {0};

bool is_in(){
  for(d=0; d<n; d++)
    if(!bisquares[j+d*i])
      return false;
  return true;
}

int main(){
  ifstream fin ("ariprog.in");
  ofstream fout ("ariprog.out");
  int x, flag=0, p, q;
  fin>>n>>x;
  for(p=0; p<=x; p++)
    for(q=p; q<=x; q++)
      bisquares[p*p+q*q]=1;
  p=2*x*x;
  if(n>4){
    for(i = 4; i<=p/(n-1); i+=4){
      for(j=0; j<=p-(n-1)*i; j++){
        if(j%4!=3 && is_in()){
          fout<<j<<" "<<i<<endl;
          flag=1;
        }
      }
    }
  } else{
    for(i=1; i<=p/(n-1); i++){
      for(j=0; j<=p-(n-1)*i; j++){
        if(is_in()){
          fout<<j<<" "<<i<<endl;
          flag=1;
        }
      }
    }
  }
  if(!flag)
    fout<<"NONE"<<endl;
}
// /*
// ID: verma.r1
// PROG: ariprog
// LANG: C++11
// */
// #include <fstream>
// #include <unordered_set>
// using namespace std;

// int i,j,n,d;
// unordered_set<int> bisquares;

// bool is_in(){
//   for(d=0; d<n; d++)
//     if(bisquares.find(j+d*i)==bisquares.end())
//       return false;
//   return true;
// }

// int main(){
//   ifstream fin ("ariprog.in");
//   ofstream fout ("ariprog.out");
//   int x, flag=0, p, q;
//   fin>>n>>x;
//   for(p=0; p<=x; p++)
//     for(q=p; q<=x; q++)
//       bisquares.insert(p*p+q*q);
//   p=2*x*x;
//   if(n>4){
//     for(i = 4; i<=p/(n-1); i+=4){
//       for(j=0; j<=p-(n-1)*i; j++){
//         if(j%4!=3 && is_in()){
//           fout<<j<<" "<<i<<endl;
//           flag=1;
//         }
//       }
//     }
//   } else{
//     for(i=1; i<=p/(n-1); i++){
//       for(j=0; j<=p-(n-1)*i; j++){
//         if(is_in()){
//           fout<<j<<" "<<i<<endl;
//           flag=1;
//         }
//       }
//     }
//   }
//   if(!flag)
//     fout<<"NONE"<<endl;
// }