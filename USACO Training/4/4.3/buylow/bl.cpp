/*
ID: verma.r1
PROG: buylow
LANG: C++11
*/

#include <fstream>
#include <iomanip>
#include <algorithm>
using namespace std;

ifstream cin ("buylow.in");
ofstream cout ("buylow.out");

int n, longestLength=0, BASE=100000000, prices[5001], len[5001], prev[5001], num[5001][100], digits[5001];

void add(int x,int y){
    digits[x] = max(digits[x], digits[y]);
    
    for(int i=1; i <= digits[x]; i++){
        num[x][i] += num[y][i];
        if(num[x][i] >= BASE){
            num[x][i+1] += num[x][i]/BASE;
            num[x][i] %= BASE;
        }
    }

    if(num[x][digits[x]+1])
        ++digits[x];
}

void print(int x){
    cout<<num[x][digits[x]];
    for(int i = digits[x]-1; i>=1; i--){
        cout << setw(8) << setfill('0') << num[x][i];
    }
}

int main(){
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>prices[i];
        len[i] = 0;
        
        for(int j=1; j<i; j++){
            if(prices[j] == prices[i]) 
                prev[i]=j;
            if(len[j]+1 > len[i] && prices[j] > prices[i]) 
                len[i] = len[j]+1;
        }
        
        if(len[i] == 0)
            len[i] = 1;
        
        if(len[i] > longestLength) 
            longestLength=len[i]; 
    }

    for(int i=1; i<=n; i++){
        if(len[i] == 1 && prev[i] == 0){
            num[i][1] = 1;
            digits[i] = 1;
        } else{
            for(int j=prev[i]+1; j<i; j++)
                if(len[j] + 1 == len[i] && prices[j] > prices[i])
                    add(i, j);
        }
    }

    for(int i=1; i<=n; i++)
        if(len[i] == longestLength)
            add(0,i);

    cout<<longestLength<<' ';
    print(0);
    cout<<'\n';
    return 0;
}