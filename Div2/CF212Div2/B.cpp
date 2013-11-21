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

int
main() {
    int N,M;
    scanf("%d%d",&N,&M);
    if (M == 0) {
        puts("YES");
        return 0;
    }
    vector<int> v(M);
    for (int i=0; i<M; ++i) {
        scanf("%d",&v[i]);
    }
    sort(v.begin(), v.end());
    if (v[0] == 1 || v[M-1] == N) {
        puts("NO");
        return 0;
    }
    for (int i=1; i<M-1; ++i) {
        if (v[i]-v[i-1] == 1 && v[i+1]-v[i] == 1) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}