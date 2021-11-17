#include <iostream>
#include <cstring> 
#include <vector>
using namespace std;

const int MAX=10005;
vector<int> vec[MAX];
int     pre[MAX];
bool    visited[MAX];
bool    root[MAX];
int     u, v;
int     node;

int findset(int x)
{
    if(pre[x] != x)
    {
        pre[x] = findset(pre[x]);
    }
    return pre[x];
}

void unionset(int x, int y)
{
    x = findset(x);
    y = findset(y);
    if(x == y)
        return;
    pre[y] = x;
}

void LCA(int par)
{
    for(int i=0; i < vec[par].size(); i++)
    {
        LCA(vec[par][i]);
        unionset(par,vec[par][i]);
    }
    visited[par] = true;
    if(par == u && visited[v] == true)
    {
        node = findset(v);
        return;
    }
    if(par == v && visited[u] == true)
    {
        node = findset(u);
        return;
    }
}

int main(int argc, char const *argv[])
{
    int T, n;
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=0; i<MAX; i++)
        {
            vec[i].clear();
            pre[i] = i;
            root[i]=true;
        }
        memset(visited,0,sizeof(visited));
        for(int i=1; i<=n-1; i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            vec[a].push_back(b);
            root[b] = false;
        }
        scanf("%d%d",&u,&v);
        int pos;
        for(int i=1;i<=n-1;i++)
        {
            if(root[i]==true)
            {
                pos=i;
                break;
            }
        }
        LCA(pos);
        cout<<node<<endl;
    }

    return 0;
}
