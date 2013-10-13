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

#define INF (a<<20)

using namespace std;

int
calc(int left,int right,vector<int>&flip)
{
	int ret=0;
	for (int i=left; i<right; ++i) {
		if (flip[i]==0) {
			++ret;
		}
		else {
			--ret;
		}
	}
	return ret;
}

int
solve(int n,vector<int> flip)
{
	int numOne=0;
	for (int i=0; i<flip.size(); ++i) {
		if (flip[i]==1) {
			++numOne;
		}
	}

	int ans=-2;
	for (int pos=0; pos<flip.size(); ++pos) {
		for (int num=1; pos+num<=flip.size(); ++num) {
			ans = max(ans,calc(pos, pos+num, flip));
		}
	}

	return ans+numOne;
}

int main(void) {

	int n;
	scanf("%d",&n);

	vector <int> flip(n);
	for (int i=0; i<n; ++i) {
		scanf("%d",&flip[i]);
	}

	int ans = solve(n,flip);
	printf("%d\n",ans);
	return 0;
}