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

int M;
vector<int> sum;

int
main()
{
    scanf("%d",&M);
    for (int i=0; i<M; ++i) {
        int a;
        scanf("%d",&a);
        int v = i == 0 ? a : sum[i-1] + a;
        sum.push_back(v);
    }
    int x,y;
    scanf("%d%d",&x,&y);

    for (int i = x; i <= y; ++i) {
        int p = (int)distance(sum.begin(), lower_bound(sum.begin(), sum.end(), i));
        int sub = sum[M-1] - sum[p];
        if (x <= sum[p] && sum[p] <= y && x <= sub && sub <= y) {
            printf("%d\n",p+2);
            return 0;
        }
    }
    printf("0\n");
    return 0;
}