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
#include <bitset>

const long long LINF = (1e11);
const int INF = (1<<30);
#define EPS 1e-6

using namespace std;

int N,K;
vector<int> h;

void
solve()
{
    vector<int> sum(N,0);
    for (int i=1; i<=N; ++i) {
        sum[i] = h[i-1] + sum[i-1];
    }

    int mn = INF;
    int ans = 0;
    for (int i=0; i<=N-K; ++i) {
        if (mn > sum[i+K] - sum[i]) {
            mn = sum[i+K] - sum[i];
            ans = i + 1;
        }
    }
    printf("%d\n",ans);
}

int
main()
{
    scanf("%d%d",&N,&K);
    h.resize(N);
    for (int i=0; i<N; ++i) {
        scanf("%d",&h[i]);
    }
    solve();
}