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

#define INF (1<<30)
#define LINF (5e18)

using namespace std;

const int X = 8;
const int Y = 8;

const int dx[] = {2,2,-2,-2};
const int dy[] = {2,-2,2,-2};

typedef pair<int, int> P;

vector<string> m(Y);

void
calc_dist(vector<vector<int> > &dist,int x,int y) {
    queue<P> que;
    que.push(P(x,y));
    dist[y][x] = 0;

    while (!que.empty()) {
        P p = que.front(); que.pop();
        int cx = p.first , cy = p.second;
        for (int i=0; i<4; ++i) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (0 <= nx && nx < X && 0 <= ny && ny < Y && dist[ny][nx] == -1) {
                dist[ny][nx] = (dist[cy][cx] + 1)&1;
                que.push(P(nx,ny));
            }
        }
    }
}

P
search_k() {
    for (int y=0; y<Y; ++y) {
        for (int x=0; x<X; ++x) {
            if (m[y][x] == 'K') {
                return P(x,y);
            }
        }
    }
    return P(-1,-1);
}

string
solve() {
    vector<vector<int> > dist_f(Y,vector<int>(X,-1)),dist_s(Y,vector<int>(X,-1));
    P f = search_k();
    m[f.second][f.first] = '.';
    calc_dist(dist_f, f.first, f.second);
    P s = search_k();
    calc_dist(dist_s, s.first, s.second);
    for (int x=0; x<X; ++x) {
        for (int y=0; y<Y; ++y) {
            if (dist_f[y][x]==dist_s[y][x] && dist_f[y][x] != -1 && m[y][x] != '#') {
                return "YES";
            }
        }
    }
    return "NO";
}

int
main() {
    int num;
    scanf("%d",&num);
    for (int i=0; i<num; ++i) {
        for (int y=0; y<Y; ++y) {
            string str;
            cin >> str;
            m[y] = str;
        }
        cout << solve() << endl;
    }
}