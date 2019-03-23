#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

struct task{
	int w, l;
};

bool comp(task a, task b){
	return a.w/(double) a.l > b.w/(double) b.l;
}

ifstream fin ("jobschedule.in");

int main(){
	int n;
	fin>>n;
	task arr[n];

	for(int i=0; i<n; i++) fin>>arr[i].w>>arr[i].l;
	sort(arr, arr + n, comp);

	long sum=0, c=0;

	for(int i=0; i<n; i++){
		c += arr[i].l;
		sum += arr[i].w * c;
	}

	cout<<sum;
}