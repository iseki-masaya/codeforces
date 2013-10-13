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

int N;
int C[8];

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

int N;
int C[8];

void
ans_print(int i,int j,int k)
{
    for (int w=0 ; w<i ; ++w) {
        printf("1 2 4\n");
    }
    for (int w=0 ; w<j ; ++w) {
        printf("1 2 6\n");
    }
    for (int w=0 ; w<k ; ++w) {
        printf("1 3 6\n");
    }
}

void
solve()
{
    if (C[5] || C[7]) {
        printf("-1\n");
        return;
    }
    int p[3] = {0};
    // 1 3 6
    p[2]  = C[3];
    C[6] -= C[3];
    C[1] -= C[3];
    C[3] = 0;
    if (C[6] < 0 || C[1] < 0) {
        printf("-1\n");
        return;
    }
    // 1 2 4
    p[0]  = C[4];
    C[1] -= C[4];
    C[2] -= C[4];
    C[4] = 0;
    if (C[1] < 0 || C[2] < 0) {
        printf("-1\n");
        return;
    }
    // 1 2 6
    p[1]  = C[2];
    C[6] -= C[2];
    C[1] -= C[2];
    C[2] = 0;
    if (C[6] < 0 || C[1] < 0) {
        printf("-1\n");
        return;
    }
    for (int i=0; i<8; ++i) {
        if (C[i] != 0) {
            printf("-1\n");
            return;
        }
    }
    ans_print(p[0], p[1], p[2]);
}

int
main()
{
    memset(C, 0, sizeof(C));
    scanf("%d",&N);
    for (int i=0; i<N; ++i) {
        int idx;
        scanf("%d",&idx);
        C[idx]++;
    }
    solve();
    return 0;
}

void
solve()
{
    if (C[5]>0 || C[7]>0) {
        printf("-1\n");
        return;
    }
    for (int i=0; i<=C[1]; ++i) {
        for (int j=0; i+j<=C[1]; ++j) {
            int k = C[1] - (i+j);
            if (C[2] == i+j && C[4] == i && C[3] == k && C[6] == j+k) {
                ans_print(i, j, k);
                return;
            }
        }
    }
    printf("-1\n");
}

int
main()
{
    memset(C, 0, sizeof(C));
    scanf("%d",&N);
    for (int i=0; i<N; ++i) {
        int idx;
        scanf("%d",&idx);
        if (idx < 0 || idx >= 7) {
            printf("-1\n");
            return 0;
        }
        C[idx]++;
    }
    solve();
    return 0;
}