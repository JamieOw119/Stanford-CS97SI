#include<iostream>
#include<vector>
#include<cstdio>
#define maxn 50005
using namespace std;
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        if(n==-1&&m==-1)break;//找到i到n 满足逆序数大于m 剩下的升序输出
        int i;int k=0;
        for( i=n;i>=1;i--)
        {
            k=((n-i)*(n-i+1))/2;
            if(k>m)break;
        }  
        int ans=0;
        for(int j=n;j>=i;j--)  // 如 找到了 5-9满足完全逆序的时候逆序数大于给定值
        {
            if(m==((j-i)+((n-i-1)*(n-i))/2))//这5个数一定是数列s=（x，剩下的个数你序排列）。
            {
                   ans=j;                   //数列s的逆序数计算公式为 (j-i)+((n-i-1)*(n-i))/2)；
                   break;                     //通过枚举找到k值。
            }
        }
        for(int s=1;s<i;s++)
        {
            printf("%d ",s);
        }
        printf("%d",ans);
        for(int ss=n;ss>=i;ss--)
        {
            if(ss==ans)continue;
            else printf(" %d",ss);
        }
        printf("\n");
    }
}f