/*
ID: verma.r1
PROG: rockers
LANG: C++11
*/
#include <fstream>
#include <algorithm>
using namespace std;

int n, m, d, s[20], maxSongs;
ifstream cin ("rockers.in");
ofstream cout ("rockers.out");

void recurse(int pos, int songs, int minutes, int disks){
  if(pos==n || disks==d){
    maxSongs=max(maxSongs, songs);
    return;
  }
  recurse(pos+1, songs, minutes, disks);
  if(minutes+s[pos]<=m){
    recurse(pos+1, songs+1, minutes+s[pos], disks);
  } else if(s[pos]<=m){
    recurse(pos, songs, 0, disks+1);
  }
}

int main(){
  cin>>n>>m>>d;
  for(int i=0; i<n; i++)
    cin>>s[i];
  recurse(0, 0, 0, 0);
  cout<<maxSongs<<endl;
}