/*
ID: verma.r1
PROG: friday
LANG: C++11
*/
#include <fstream>
using namespace std;

bool isLeapYear(int year){
  if(year%400==0 || (year%100!=0 && year%4==0))
    return true;
  return false;
}

int main(){
  ifstream fin ("friday.in");
  ofstream fout ("friday.out");
  
  int months[12]={3,0,3,2,3,2,3,3,2,3,2,3};
  int days[7]={0,0,0,0,0,0,0};
  int date=0, year=1900, n;
  fin>>n;
  int endyear=1900+n;
  do{
    for(int month=0; month<12; month++){
      days[date]+=1;
      date+=months[month];
      if(month==1 && isLeapYear(year))
        date+=1;
      date%=7;
    }
  } while(++year!=endyear);
  
  for(int i=0; i<7; i++){
	  fout<<days[i];
	  if(i!=6)
		  fout<<" ";
	  else
		  fout<<"\n";
  }
  return 0;
}