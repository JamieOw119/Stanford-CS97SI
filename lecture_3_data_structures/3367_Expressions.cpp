#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
#include <queue>

using namespace std;

const int maxn = 10000;

struct node{
    int l, r;
    char c;
} e[maxn];

int cnt;
char str[maxn];

void initial(){
    int len = strlen(str);
    for(int i=0; i<=len; i++)
    {
        e[i].l = e[i].r = -1;
    }
    cnt = 0;
}

void solve()
{
    int len = strlen(str);
    stack<int> v;
    for(int i=0; i<len; i++)
    {
        if(str[i]>='a' && str[i]<='z')
        {
            e[cnt].c=str[i];
            v.push(cnt);
            cnt++;
        }
        else
        {
            int r = v.top();
            v.pop();
            int l = v.top();
            v.pop();
            e[cnt].l = l;
            e[cnt].r = r;
            e[cnt].c=str[i];
            v.push(cnt);
            cnt++;
        }
    }
}

void output()
{
    string ans;
    queue<int> q;
    q.push(cnt-1);
    while(!q.empty())
    {
        int s=q.front();
        q.pop();
        ans.push_back(e[s].c);
        if(e[s].l!=-1) q.push(e[s].l);
        if(e[s].r!=-1) q.push(e[s].r);
    }
    reverse(ans.begin(),ans.end());
    printf("%s\n",ans.c_str());
}


int main(){
    int t;
    scanf("%d",&t);
    while(t-- >0){
        scanf("%s",str);
        initial();
        solve();
        output();
    }
    return 0;
}