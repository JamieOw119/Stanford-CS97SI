#include <cstdio>
#include <iostream> 
using namespace std;
struct tw{
    int fat;
    int dx;
    int dy;
};
tw w[99999];
char get[99999][50];  
int abs(int k)
{
    if(k<0) return -k;
    return k;
}
int find(int nd)  
{  
    if(nd==w[nd].fat)  
        return nd;  
    int tmp=w[nd].fat;  
    w[nd].fat=find(w[nd].fat);  
    w[nd].dx+=w[tmp].dx;  
    w[nd].dy+=w[tmp].dy;  
    return w[nd].fat;  
}  
void Union(int a, int b, int dx, int dy)  
{  
    int r1=find(a);  
    int r2=find(b);
    if(r1!=r2)  
    {  
        w[r2].fat=r1;  
        w[r2].dx=w[a].dx+dx-w[b].dx;  
        w[r2].dy=w[a].dy+dy-w[b].dy;   
    }  
}  
int main()
{
    int n,m;

    scanf("%d%d",&n,&m);
    getchar();  
    for(int i=1;i<=n;i++)
     w[i].fat=i,w[i].dx=w[i].dy=0;

    for(int i=0;i<m;i++)  
     gets(get[i]);  

    int t;
    scanf("%d",&t);
    int last_time=0;
    for(int i=1;i<=t;i++)
     {
        int d1,d2,time;
        scanf("%d%d%d",&d1,&d2,&time);

        for(int i=last_time;i<time;i++)  
        {  
            int dx=0,dy=0;  
            int a,b,d;
            char dir[2];  
            sscanf(get[i], "%d %d %d %s", &a, &b, &d, dir);  
            switch(dir[0])  
            {  
                case'E':dx += d; break;  
                case 'W': dx -= d; break;  
                case 'N': dy += d; break;  
                case 'S': dy -= d; break;  
            }  
            Union(a, b, dx, dy);  
        }  
        last_time = time;

        int q1=find(d1);
        int q2=find(d2);
        if(q1!=q2)
         printf("-1\n");
        else
         printf("%d\n",abs(w[d1].dx-w[d2].dx)+abs(w[d1].dy-w[d2].dy));
     }
     return 0;
}