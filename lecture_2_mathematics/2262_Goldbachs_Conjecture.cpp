#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

/*bool isprime(int k)
{
    int t = sqrt(k+0.5);
    for(int i=2; i<=t; i++)
    {
        if(k%i==0)
        {
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    int n;
    while(cin>>n && n!=0)
    {
        bool flag = false;
        int i;
        for(i=3; i<n/2; i+=2)
        {
            if(isprime(i)&&isprime(n-i))
            {
                flag = true;
                break;
            }
        }
        if(flag)
        {
            cout<<n<<" = "<<i<<" + "<<n-i<<endl;
        }
        else
        {
            cout<<"Goldbach's conjecture is wrong."<<endl;
        }
    }
    return 0;
}*/


int isprime(int k)
{
    int t=sqrt(k+0.5) ;
    for(int i=2; i<=t; i++)
        if(k%i==0)
            return 0;
    return 1;
}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(!n) return 0;
        int i;
        int t=n/2;
        for(i=3; i<=t; i+=2)
            if(isprime(i)&&isprime(n-i))
                break;
        printf("%d = %d + %d\n",n,i,n-i) ;
    }
    return 0;
}