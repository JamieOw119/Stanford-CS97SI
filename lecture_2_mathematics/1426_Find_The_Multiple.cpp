#include <cstdio>
#include <cstring>
#include <queue>
#include <iostream>
using namespace std;

int n;
void solve()
{
    queue<long long> q;
    q.push(1);
    while(!q.empty())
    {
        long long u = q.front();
        q.pop();

        if(u % n == 0)
        {
            cout<<u<<endl;
            return;
        }

        q.push(u * 10);
        q.push(u * 10 + 1);
    }
}

int main(int argc, char const *argv[])
{
    while(cin>>n, n)
    {
        solve();
    }
    return 0;
}
