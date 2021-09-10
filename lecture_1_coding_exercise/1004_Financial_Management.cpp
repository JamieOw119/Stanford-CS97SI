#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    double sum = 0.0;
    for(int i=0; i<12; i++)
    {
        double account;
        cin>>account;
        sum += (account / 12.0);
    }
    cout<<'$'<<sum<<endl;
    return 0;
}
