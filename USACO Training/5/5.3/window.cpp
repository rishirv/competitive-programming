/*
ID: verma.r1
PROG: window
LANG: C++11
*/
#include <fstream>
#include <algorithm>
#include <deque>
#include <iomanip>
using namespace std;

struct win{
  char id;
  int x, y, X, Y;
};

deque<win> windows;
ifstream cin ("window.in");
ofstream cout ("window.out");

double a(win w){ 
  return (w.X-w.x)*(w.Y-w.y);
}

int area(win w, deque<win>::iterator it){
  if(w.x >= w.X || w.y >= w.Y) return 0;
  if(it == windows.end()) return (w.X-w.x)*(w.Y-w.y);

  return 
    area(win {' ', w.x, w.y, min(it->x, w.X), w.Y}, it+1) +
    area(win {' ', max(it->x, w.x), w.y, min(it->X, w.X), min(it->y, w.Y)}, it+1) +
    area(win {' ', max(it->X, w.x), w.y, w.X, w.Y}, it+1) + 
    area(win {' ', max(it->x, w.x), max(it->Y, w.y), min(it->X, w.X), w.Y}, it+1);
}

int main(){
  char func, bl, id;
  while(cin>>func){
    switch(func){
      case 'w':
        int x, y, X, Y;
        cin>>bl>>id>>bl>>x>>bl>>y>>bl>>X>>bl>>Y>>bl;

        windows.push_back(win {id, min(x, X), min(y, Y), max(x, X), max(y, Y)});

        break;
      case 't':
        cin>>bl>>id>>bl;

        for(auto it=windows.begin(); it!=windows.end(); ++it){
          if(it->id == id){
            auto x = *it;
            windows.erase(it);
            windows.push_back(x);
            break;
          }
        }
        
        break;
      case 'b':
        cin>>bl>>id>>bl;

        for(auto it=windows.begin(); it!=windows.end(); ++it){
          if(it->id == id){
            auto x = *it;
            windows.erase(it);
            windows.push_front(x);
            break;
          }
        }

        break;
      case 'd':
        cin>>bl>>id>>bl;

        for(auto it=windows.begin(); it!=windows.end(); ++it){
          if(it->id == id){
            windows.erase(it);
            break;
          }
        }

        break;
      case 's':
        cin>>bl>>id>>bl;

        for(auto it=windows.begin(); it!=windows.end(); it++){
          if(it->id == id){
            cout<<fixed<<setprecision(3)<<area(*it, it+1)/a(*it)*100<<endl;
          }
        }
        break;
    }
  }
}