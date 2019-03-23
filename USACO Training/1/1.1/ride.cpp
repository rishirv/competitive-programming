/*
ID: verma.r1
PROG: ride
LANG: C++
*/

#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main()
{
	string comet, group;
	int a=1, b=1;

	freopen("ride.in", "r", stdin);
	freopen("ride.out", "w", stdout);
	cin >> comet;
	cin >> group;

	for (int i=0; i<comet.length(); i++)
		a *= comet[i]-64;

	for (int i=0; i<group.length(); i++)
		b *= group[i]-64;

	if (a%47 == b%47)
		cout << "GO\n";
	else
		cout << "STAY\n";

	return 0;
}