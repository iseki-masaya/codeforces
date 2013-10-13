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

long long
solve(string str,int n)
{
	vector<int> pos;
	bool isAll=true;
	for (int i=0; i<str.size(); ++i) {
		if (str[i]=='0'||str[i]=='5') {
			pos.push_back(i);
		}
		else {
			isAll = false;
		}
	}

	long long ans=0;

	if (isAll) {
		int p=pos.back()+1;
		ans = 1;
		p += (n-1)*str.size();
		for (int i=0; i<p; ++i) {
			ans *= 2;
			ans = ans%1000000007;
		}
	}
	else {
		for (int i=0; i<n; ++i) {
			for (int j=0; j<pos.size(); ++j) {
				int work=1;
				for (int k=0; k<pos[j]; ++k) {
					work *= 2;
					work = work%1000000007;
				}
				ans += work;
				ans = ans%1000000007;
				pos[j] += str.size();
			}
		}
	}

	return ans-isAll;
}

int main(void) {
	string str;
	int n;

	cin >> str;
	cin >> n;

	long long ans = solve(str,n);
	cout << ans;
}