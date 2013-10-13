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
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <numeric>

#define INF (1<<28)
#define EPS 1e-8

using namespace std;

#define MAX_N 100005

int N;
int x[MAX_N];
string bit;

int
solve()
{
    int sum_one[MAX_N];
    int sum_all[MAX_N];
    memset(sum_all, 0, sizeof(sum_all));
    memset(sum_one, 0, sizeof(sum_one));

    for (int i=0; i<N; ++i) {
        if (bit[i] == '1') {
            sum_one[i+1] = x[i] + sum_one[i];
        }
        else {
            sum_one[i+1] = sum_one[i];
        }
        sum_all[i+1] = x[i] + sum_all[i];
    }

    int one = sum_one[N];
    int ans = one;
    for (int i=1; i<N; ++i) {
        if (bit[i] == '1') {
            ans = max(ans, one + sum_all[i] - sum_one[i+1]);
        }
    }
    return ans;
}

int
main()
{
    scanf("%d",&N);
    for (int i=0; i<N ; ++i) {
        scanf("%d",&x[i]);
    }
    cin >> bit;
    cout << solve() << endl;
}