#include <iostream>
#include <cstdio>
#define N 100010
using namespace std;
// 以下四个函数均为并查集模板
int a[2*N],r[2*N];
void init(int n)
{
    for(int i = 0; i <= n; i++)
    {
        a[i] = i;
        r[i] = 1;
    }
}
int findset(int x)
{
    return a[x] == x?x:(a[x] = findset(a[x]));
}
void mergeset(int x, int y)
{
    x = findset(x);
    y = findset(y);
    if(x != y)
    {
        if(r[x] <= r[y]) 
            a[x] = y;
        else 
            a[y] = x;
        if(r[x] == r[y]) 
            r[y]++;
    }
}
bool issame(int x, int y)
{
    return findset(x) == findset(y);
}
int main()
{
    int t,m,n,x,y;
    char c; // 各种所需变量
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        init(2*n); // 两个帮派，所以开大两倍
        while(m--)
        {
            scanf("\n%c%d%d",&c,&x,&y); // Attention！ 输入字符前加一个换行符
            if(c == 'D')
            {
                mergeset(x,y+n); // 可以理解为x和y的敌人是一个帮派的，即敌人的敌人是朋友
                mergeset(x+n,y);
            } else if(c == 'A') {
                if(issame(x,y+n) || issame(x+n,y)) printf("In different gangs.\n");
                else if(issame(x,y) || issame(x+n,y+n)) printf("In the same gang.\n");
                else printf("Not sure yet.\n");
            }
        }
    }
    return 0;
}