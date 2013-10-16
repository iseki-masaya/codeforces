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

#define MAX_N 600010

int seg_n,N,M;
vector<vector<int> > vs;

vector<int> dat;

void
init()
{
    seg_n = 1;
    while (seg_n < N) {
        seg_n *= 2;
    }
}

void
update(int a,int b,int l,int r,int k,int x)
{
    if (r <= a || b <= l || dat[k] != 0) {
        return;
    }
    else if (a <= l && r <= b) {
        dat[k] = x;
    }
    else {
        int mid = (r+l+1)/2;
        update(a, b, l, mid, 2*k+1, x);
        update(a, b, mid, r, 2*k+2, x);
    }
}

int
query(int k)
{
    k += seg_n-1;
    while (k > 0 && dat[k] == 0) {
        k = (k-1)/2;
    }
    return dat[k];
}

int
main()
{
    scanf("%d%d",&N,&M);
    vector<int> ans(N,0);
    init();
    dat.resize(2*seg_n-1,0);
    int x;
    for (int i=0; i<M; ++i) {
        int l,r;
        scanf("%d%d%d",&l,&r,&x);
        --l, --r, --x;
        update(l, x, 0, seg_n, 0, x+1);
        update(x+1, r+1, 0, seg_n, 0, x+1);
    }
    for (int i=0; i<N; ++i) {
        if (x == i) {
            printf("0%c",i==N-1?'\n':' ');
        }
        else {
            printf("%d%c",query(i),i==N-1?'\n':' ');
        }
    }
    return 0;
}
