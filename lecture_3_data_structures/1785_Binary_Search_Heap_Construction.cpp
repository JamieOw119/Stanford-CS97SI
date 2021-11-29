#include <algorithm>
#include <iostream>
#include <cstring> 

using namespace std;

const int maxn = 55000;
const int maxc = 100;

struct node{
    char s[maxc];
    int val,l,r,fa;
}dt[maxn];

bool Cmp(node a, node b){ return strcmp(a.s,b.s) < 0; }
 
void Insert(int i){
    int j = i - 1;
    while(dt[j].val < dt[i].val)
        j = dt[j].fa;
    dt[i].l  = dt[j].r;
    dt[i].fa = j;
    dt[j].r  = i;
}

void Visit(int i){
    if(i == 0 ) return ;
    printf("(");
    Visit(dt[i].l);
    printf("%s/%d",dt[i].s,dt[i].val);
    Visit(dt[i].r);
    printf(")");
}

int main(int argc, char const *argv[])
{
    int n;
    while(scanf("%d",&n) == 1 && n)
    {
        for(int i=1; i <= n; i++)
        {
            scanf(" %[a-z]/%d", dt[i].s,&dt[i].val);
            dt[i].fa = dt[i].l = dt[i].r = 0;
        }
        dt[0].fa = dt[0].r = dt[0].l = 0;
        dt[0].val = 999999999;
        sort(dt+1,dt+n+1,Cmp);
        for(int i = 1; i <= n; ++i)
            Insert(i);
        Visit(dt[0].r);
        printf("\n");
    }
    return 0;
}
