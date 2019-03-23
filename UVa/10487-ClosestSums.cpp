#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000], sums[1000000], n, x, c = 0;

int main(){
	while(cin>>n && n != 0){
		int k = 0;
		for(int i=0; i<n; i++){
			cin>>arr[i];
		}
		for(int i=0; i<n; i++){
			for(int j=i+1; j<n; j++){
				sums[k++] = arr[i] + arr[j];
			}
		}
		sort(sums, sums+k);
		cin>>n;
    cout<<"Case "<<++c<<":\n";
		while(n--){
			cin>>x;
      auto it = lower_bound(sums, sums+k, x);
      if(it == sums+k || (it != sums && x - *(it-1) < *it - x)) --it;
      cout<<"Closest sum to "<<x<<" is "<<*it<<".\n";
		}
	}
}