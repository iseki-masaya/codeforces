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

#define MAX_N 105

int N;
int x[MAX_N] , y[MAX_N];

bool
x_odd()
{
    for (int i=0; i<N; ++i) {
        if (x[i]&1 && !(y[i]&1)) {
            return true;
        }
    }
    return false;
}

bool
y_odd()
{
    for (int i=0; i<N; ++i) {
        if (!(x[i]&1) && y[i]&1) {
            return true;
        }
    }
    return false;
}

int
solve()
{
    int X = 0 , Y = 0;
    for (int i=0; i<N; ++i) {
        X += x[i];
        Y += y[i];
    }
    if (X&1 && Y&1) {
        if (x_odd() || y_odd())
            return 1;
    }
    else if (!(X&1) && !(Y&1)) {
        return 0;
    }
    return -1;
}

int
main()
{
    scanf("%d",&N);
    for (int i=0; i<N; ++i) {
        scanf("%d %d",&x[i],&y[i]);
    }
    printf("%d\n",solve());
    return 0;
}