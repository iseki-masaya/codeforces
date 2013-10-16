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

int
main()
{
    int N,M;
    scanf("%d%d",&N,&M);

    int color[100050];
    memset(color, 0, sizeof(color));
    for (int i=0; i<M; ++i) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        int *col[3] = {&color[a],&color[b],&color[c]};
        int f[4] = {};
        for (int j=0; j<3; ++j) {
            f[*col[j]]++;
        }
        for (int j=0; j<3; ++j) {
            for (int k=1; k<4; ++k) {
                if (f[k] == 0 && *col[j] == 0) {
                    *col[j] = k;
                    f[k]++;
                    break;
                }
            }
        }
    }
    for (int i=1; i<=N; ++i) {
        printf("%d%c",color[i],i==N?'\n':' ');
    }
    return 0;
}
