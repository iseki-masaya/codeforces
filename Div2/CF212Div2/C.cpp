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
#include <numeric>
#include <stdio.h>
#include <string.h>

#define INF (1<<28)
#define LINF (1e17)

using namespace std;

const int MAX = 5005;
int dp[MAX][MAX];

int
main() {
    int N;
    scanf("%d",&N);
    vector<int> v(N);
    for (int i=0; i<N; ++i) {
        scanf("%d",&v[i]);
    }

    memset(dp, 0, sizeof(dp));
    for (int i=0; i<N; ++i) {
        for (int j=i+1; j<N; ++j) {
            if (v[i] < v[j]) {
                dp[i][j] = dp[i][j-1] + 1;
            }
            else if (v[i] > v[j]) {
                dp[i][j] = dp[i][j-1] - 1;
            }
        }
    }
    for (int i=N-1; i>=0; --i) {
        for (int j=i-1; j>=0; --j) {
            if (v[i] < v[j]) {
                dp[i][j] = dp[i][j+1] - 1;
            }
            else if (v[i] > v[j]) {
                dp[i][j] = dp[i][j+1] + 1;
            }
        }
    }

    int mn = INF;
    int mnc = 0;
    int l=-1,r=-1;
    for (int i=0; i<N; ++i) {
        for (int j=i+1; j<N; ++j) {
            int val = dp[i][j] + dp[j][i];
            if (val < mn) {
                mn = val;
                mnc = 1;
                l = i , r = j;
            }
            else if (val == mn) {
                ++mnc;
            }
        }
    }

    swap(v[l], v[r]);
    int cnt = 0;
    for (int i=0; i<N; ++i) {
        for (int j=i+1; j<N; ++j) {
            if (v[i] > v[j]) {
                ++cnt;
            }
        }
    }
    printf("%d %d\n",cnt,mnc);
    return 0;
}