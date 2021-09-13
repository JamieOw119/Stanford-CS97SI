#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    while(cin>>n && n != 0)
    {
        double mintime = 999999999999.9999999999;
        for (int i = 0; i < n; i++)
        {
            int v, t;
            cin>>v>>t;
            if(t < 0)
            {
                continue;
            }
            double time = 4.5/v*3600+t;
            if(time < mintime)
            {
                mintime = time;
            }
        }
        cout<<ceil(mintime)<<endl;
    }
    return 0;
}


