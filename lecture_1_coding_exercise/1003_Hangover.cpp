#include <iostream>

using namespace std;


int main(int argc, char const *argv[])
{
    float length;
    while(cin>>length)
    {
        if(length==0)
        {
            break;
        }

        float mylength = 0.0;
        int i;
        for(i=1; mylength < length; i++)
        {
            mylength += 1.0/(i+1);
        }
        cout<<i-1<<" card(s)"<<endl;
    }
    return 0;
}
