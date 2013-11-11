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

int n,m,a;
vector<int> b,p;

void
init()
{
    scanf("%d%d%d",&n,&m,&a);
    b.resize(n);
    p.resize(m);
    for (int i=0; i<n; ++i) {
        scanf("%d",&b[i]);
    }
    for (int i=0; i<m; ++i) {
        scanf("%d",&p[i]);
    }
}

int
calc(int &r,int &s)
{
    for (int i=0; i<n; ++i) if (b[i] != -1) {
        for (int j=0; j<m; ++j) if (p[j] != -1) {
            int v = p[j] - b[i];
            if (a < v) {
                return s;
            }
            s += b[i];
            b[i] = -1;
            p[j] = -1;
            a -= v;
            ++r;
            break;
        }
    }
    return s;
}

int
check(int x)
{
    vector<int> tb(b);
    sort(tb.begin(), tb.begin()+x);
    long long sub = 0;
    for (int i=0; i<x; ++i) {
        if (p[i] > tb[i]) {
            sub += p[i] - tb[i];
        }
    }
    if (sub > a) {
        return -1;
    }
    int accum = (int)accumulate(p.begin(), p.begin()+x, 0);
    return a >= accum ? 0 : accum - a;
}

void
solve()
{
    sort(b.begin(), b.end(), greater<int>());
    sort(p.begin(), p.end());
    int N = (int)b.size() , M = (int)p.size();
    int lb = 0 , ub = min(N,M)+1;
    int cost = 0;
    while (ub - lb > 1) {
        int md = (lb+ub)/2;
        int d = check(md);
        if (d >= 0) {
            lb = md;
            cost = d;
        }
        else {
            ub = md;
        }
    }
    printf("%d %d\n",lb,cost);
}

int
main()
{
    init();
    solve();
    return 0;
}