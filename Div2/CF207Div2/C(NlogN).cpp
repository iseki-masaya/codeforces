#include <iostream>
#include <stdio.h>
#include <string.h>
#include <set>
using namespace std;
#define maxn 300005
set <int> s;
set <int>::iterator ite;
int res[maxn];
int main()
{
    int n,m,l,r,x;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) s.insert(i);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&l,&r,&x);
        ite = s.lower_bound(l);
        while(ite!=s.end())
        {
            if((*ite)>r) break;
            if((*ite) == x) {res[(*ite)]=0;ite++;continue;}
            res[(*ite)]=x;
            ite=s.erase(ite);
        }
    }
    for(int i=1;i<=n;i++) printf("%d ",res[i]);
    return 0;
}