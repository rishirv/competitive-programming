#include <fstream>
using namespace std;

struct point{
  int x, y;
};

int main() {
  ifstream cin("billboard.in");
  ofstream cout("billboard.out");

  point a1, a2, b1, b2;
  cin>>a1.x>>a1.y>>a2.x>>a2.y>>b1.x>>b1.y>>b2.x>>b2.y;
  int area = (a2.x-a1.x)*(a2.y-a1.y);
  
  if(!(b1.x<=a2.x && b1.y<=a2.y && b2.x>=a1.x && b2.y>=a1.y)){ //Don't intersect
    cout<<area<<endl;
    return 0;
  }
  
  //Intersect
  if(b1.y <= a1.y && b2.y >= a2.y){
    if(b1.x <= a1.x && b2.x >= a2.x){
      area = 0;
    }
    else if(b1.x <= a1.x && b2.x < a2.x){
      area = (a2.x - b2.x)*(a2.y - a1.y);
    }
    else if(b1.x < a2.x && b2.x >= a2.x){
      area = (b1.x - a1.x)*(a2.y - a1.y);
    }
  }
  else if(b1.x <= a1.x && b2.x >= a2.x){
    if(b1.y <= a1.y && b2.y < a2.y){
      area = (a2.x - a1.x)*(a2.y - b2.y);
    }
    else if(b1.y < a2.y && b2.y >= a2.y){
      area = (a2.x - a1.x)*(b1.y - a1.y);
    }
  }

  cout<<area<<endl;
  return 0;
}