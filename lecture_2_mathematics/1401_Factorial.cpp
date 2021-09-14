#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int T;
    cin>>T;
    while(T--)
    {
        int n, ans=0;
        cin>>n;
        while(n>1)
        {
            ans += n/5;
            n /= 5;
        }
        cout<<ans<<endl;
    }
    return 0;
}
