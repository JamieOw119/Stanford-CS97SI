#include <iostream>

using namespace std;

int lowbit(int n)
{
    return n&(-n);
}

int main(int argc, char const *argv[])
{
    int ncase;
    cin>>ncase;
    while(ncase--)
    {
        int k;
        cin>>k;
        cout<<k-lowbit(k)+1<<' '<<k+lowbit(k)-1<<endl;
    }
    return 0;
}
