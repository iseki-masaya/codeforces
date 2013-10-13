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

int k,d;

int
main()
{
    scanf("%d %d",&k,&d);
    if (d != 0) {
        printf("%d",d);
        for (int i=0; i < k-1; ++i) {
            printf("0");
        }
        printf("\n");
    }
    else {
        if (k == 1) {
            printf("0\n");
        }
        else {
            puts("No solution");
        }
    }
}