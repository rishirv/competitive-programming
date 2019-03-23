#include <fstream>
using namespace std;

struct point{
  int x, y;
};

int min(int x, int y){
  if(x<y){
    return x;
  }
  return y;
}

int area(point b1, point b2, point t1, point t2){
  int length=0, width=0;
  if(t1.x<b1.x){
    length = min(t2.x-b1.x, b2.x-b1.x);
  } else{
    length = min(t2.x-t1.x, b2.x-t1.x);
  }
  
  if(t1.y<b1.y){
    width = min(t2.y-b1.y, b2.y-b1.y);
  } else{
    width = min(t2.y-t1.y, b2.y-t1.y);
  }
  return length*width;
}

int main(){
  ifstream cin("billboard.in");
  ofstream cout("billboard.out");

  point a1, a2, b1, b2, t1, t2;
  cin>>a1.x>>a1.y>>a2.x>>a2.y>>b1.x>>b1.y>>b2.x>>b2.y>>t1.x>>t1.y>>t2.x>>t2.y;
  
  int a = (a2.x-a1.x)*(a2.y-a1.y) + (b2.x-b1.x)*(b2.y-b1.y);
  
  if(t1.x<=a2.x && t1.y<=a2.y && t2.x>=a1.x && t2.y>=a1.y){
    a-=area(a1, a2, t1, t2);
  }
  
  if(t1.x<=b2.x && t1.y<=b2.y && t2.x>=b1.x && t2.y>=b1.y){
    a-=area(b1, b2, t1, t2);
  }
  
  cout<<a<<endl;
  return 0;
}