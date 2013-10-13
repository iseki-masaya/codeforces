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
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <numeric>

#define INF (1<<30)

using namespace std;

#define MAX_N 100005
#define MAX_M 100005

int n,m,s,f;
int T[MAX_M],L[MAX_M],R[MAX_M];

void
solve()
{
    if (s==f)
        return;
    char d = (s-f)>0 ? 'L' : 'R';
    int p = s;
    int i = 0,k = -1;
    string ans = "";
    for (int t=1; t<=1000000000; ++t) {
        if (t == T[i]) {
            k = i;
            ++i;
        }
        if (k == -1 || p + (d=='R'?1:0) < L[k] || R[k] < p - (d=='L'?1:0)) {
            p += d=='R'?1:-1;
            ans += d;
        }
        else {
            ans += 'X';
        }

        if (p==f) {
            printf("%s\n",ans.c_str());
            return;
        }
    }
}

int
main()
{
    scanf("%d %d %d %d",&n,&m,&s,&f);
    for (int i=0; i<m; ++i) {
        scanf("%d %d %d",&T[i],&L[i],&R[i]);
    }
    solve();
    return 0;
}