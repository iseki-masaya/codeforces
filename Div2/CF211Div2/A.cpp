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

string V;

void
init()
{
    cin >> V;
}

void
make(int v)
{
    switch (v) {
        case 0:
            puts("O-|-OOOO");
            break;
        case 1:
            puts("O-|O-OOO");
            break;
        case 2:
            puts("O-|OO-OO");
            break;
        case 3:
            puts("O-|OOO-O");
            break;
        case 4:
            puts("O-|OOOO-");
            break;
        case 5:
            puts("-O|-OOOO");
            break;
        case 6:
            puts("-O|O-OOO");
            break;
        case 7:
            puts("-O|OO-OO");
            break;
        case 8:
            puts("-O|OOO-O");
            break;
        case 9:
            puts("-O|OOOO-");
            break;
    }
}

void
solve()
{
    for (int i=(int)V.size()-1; i>=0; --i) {
        make(V[i]-'0');
    }
}

int
main()
{
    init();
    solve();
    return 0;
}