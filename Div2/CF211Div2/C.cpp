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
#include <bitset>

const long long LINF = (1e11);
const int INF = (1<<30);
#define EPS 1e-6

using namespace std;

string s;

void
solve()
{
    vector<int> cnt;
    vector<char> ch;
    int N = (int)s.size();
    char prev = s[0];
    int c = 1;
    for (int i=1; i<N; ++i) {
        if (prev == s[i]) {
            ++c;
        }
        else {
            ch.push_back(prev);
            cnt.push_back(c);
            prev = s[i];
            c = 1;
        }
    }
    if (c) {
        ch.push_back(prev);
        cnt.push_back(c);
    }

    int M = (int)cnt.size();
    for (int i=0; i<M; ++i) {
        cnt[i] = cnt[i] > 2 ? 2 : cnt[i];
    }
    for (int i=0; i<M-1; ++i) {
        if (cnt[i] == 2 && cnt[i+1] == 2) {
            cnt[i+1] = 1;
        }
    }

    for (int i=0; i<M; ++i) {
        for (int j=0; j<cnt[i]; ++j) {
            cout << ch[i];
        }
    }
    cout << endl;
}

int
main()
{
    cin >> s;
    solve();
    return 0;
}