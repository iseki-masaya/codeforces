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

int N,M;
vector<vector<int> > vs;

int
main()
{
    scanf("%d%d",&N,&M);
    vs.resize(N);
    for (int i=0; i<M; ++i) {
        int s,t,u;
        scanf("%d%d%d",&s,&t,&u);
        --s , --t , --u;
        vs[s].push_back(t);
        vs[s].push_back(u);
        vs[t].push_back(s);
        vs[t].push_back(u);
        vs[u].push_back(s);
        vs[u].push_back(t);
    }

    int color_num[3];
    vector<int> color(N,-1);

    for (int i=0; i<N; ++i) {
        if (color[i] != -1) {
            continue;
        }
        queue<int> que;
        que.push(i);
        while (!que.empty()) {
            int idx = que.front();
            que.pop();
            memset(color_num, 0, sizeof(color_num));
            for (int j=0; j<vs[idx].size(); ++j) {
                int v = vs[idx][j];
                if (color[v] != -1) {
                    color_num[color[v]]++;
                }
                else {
                    que.push(v);
                }
            }
            for (int j=0; j<3; ++j) {
                if (color_num[j] == 0) {
                    color[idx] = j;
                    break;
                }
            }
        }
    }

    for (int i=0; i<N; ++i) {
        printf("%d%c",color[i]+1,i==N-1 ? '\n' : ' ');
    }
    return 0;
}
