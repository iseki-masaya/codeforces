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

using namespace std;

void
solve(int n)
{
	vector<bool> isPrime(MAX_V,true);
	vector<int> prime(MAX_N);

	int cnt=0;
	for (int i=2; i<MAX_V; ++i) {
		if (isPrime[i]) {
			prime[cnt] = i;
			++cnt;
			int k=i+i;
			while (k<MAX_V) {
				isPrime[k] = false;
				k+=i;
			}
		}
		if (cnt >= MAX_N) {
			break;
		}
	}

	for (int i=0; i<n; ++i) {
		if (i==n-1) {
			printf("%d\n",prime[i]);
		}
		else {
			printf("%d ",prime[i]);
		}
	}
}

int main(void) {

	int n;
	scanf("%d",&n);

	solve(n);
	return 0;
}