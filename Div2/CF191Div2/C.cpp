#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <algorithm>
#include <sstream>
#include <set>
#include <cmath>
#include <map>
#include <stack>
#include <queue>

#define MAX_V (10000001)
#define MAX_N (100001)
#define MOD 1000000007

using namespace std;

long long
modPow(long long x,long long n,long long m)
{
	if (n==0) return 1;
	long long res = modPow((x*x)%m, n/2, m);
	if (n&1) res = (res*x)%m;
	return res;
}

long long
extgcd(long long a,long long b,long long &x,long long &y)
{
	long long d = a;
	if (b!=0) {
		d = extgcd(b,a%b,y,x);
		y -= (a/b)*x;
	}
	else {
		x = 1;
		y = 0;
	}
	return d;
}

long long
inv(long long x)
{
	return modPow(x, MOD-2, MOD);
}

long long
solve(string str,int k)
{
	long long single_ans=0;
	for (int i=0; i<str.size(); ++i) {
		if (str[i]=='0'||str[i]=='5') {
			single_ans = (single_ans + modPow(2, i, MOD))%MOD;
		}
	}
	long long q = modPow(2, str.size(), MOD);
	long long sum = ((modPow(q, k, MOD)-1)*inv(q-1))%MOD;
	return single_ans*sum%MOD;
}

int main(void) {
	string str;
	int n;

	cin >> str;
	cin >> n;

	long long ans = solve(str,n);
	cout << ans;
	return 0;
}