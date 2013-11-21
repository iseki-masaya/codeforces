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

vector<string> m;

const int dx[] = {2,2,-2,-2};
const int dy[] = {2,-2,2,-2};

const int N = 8;

typedef pair<int, int> P;

string
solve() {
    int kx1=-1,ky1=0;
    int kx2=0,ky2=0;
    for (int x=0; x<N; ++x) {
        for (int y=0; y<N; ++y) {
            if (m[x][y] == 'K') {
                if (kx1 == -1) {
                    kx1 = x , ky1 = y;
                }
                else {
                    kx2 = x , ky2 = y;
                }
            }
        }
    }


    queue<P> que;
    int kx = kx1 , ky = ky1;
    que.push(P(kx,ky));
    vector<vector<int> > dist(N,vector<int>(N,-1));
    dist[kx][ky] = 0;
    while (!que.empty()) {
        P p = que.front();
        que.pop();
        int x = p.first , y = p.second;
        for (int i=0; i<4; ++i) {
            int cx = x + dx[i];
            int cy = y + dy[i];
            if (0 <= cx && cx < N && 0 <= cy && cy < N && dist[cx][cy] == -1) {
                dist[cx][cy] = dist[x][y] + 1;
                que.push(P(cx,cy));
            }
        }
    }

    kx = kx2 , ky = ky2;
    que.push(P(kx,ky));
    vector<vector<int> > dist2(N,vector<int>(N,-1));
    dist2[kx][ky] = 0;
    while (!que.empty()) {
        P p = que.front();
        que.pop();
        int x = p.first , y = p.second;
        for (int i=0; i<4; ++i) {
            int cx = x + dx[i];
            int cy = y + dy[i];
            if (0 <= cx && cx < N && 0 <= cy && cy < N && dist2[cx][cy] == -1) {
                dist2[cx][cy] = dist2[x][y] + 1;
                if (dist2[cx][cy] != -1 && dist[cx][cy] != -1 && !(abs(dist2[cx][cy]-dist[cx][cy])&1) && m[cx][cy] != '#') {
                    return "YES";
                }
                que.push(P(cx,cy));
            }
        }
    }
    return "NO";
}

int
main() {
    int M;
    scanf("%d",&M);
    for (int i=0; i<M; ++i) {
        m.clear();
        for (int j=0; j<N; ++j) {
            string s;
            cin >> s;
            m.push_back(s);
        }
        cout << solve() << endl;
    }
}