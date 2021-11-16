#include<iostream>
using namespace std;
typedef long long ll;

ll n,a[100005],sum[100005],pos[100005];

int main(int argc, char const *argv[])
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        if(sum[i]%n==0){
            cout<<i<<endl;
            for(int j=1;j<=i;j++)
                cout<<a[j]<<endl;
            break;
        }
        if(pos[sum[i]%n]){
            cout<<i-pos[sum[i]%n]<<endl;
            for(int j=pos[sum[i]%n]+1;j<=i;j++)
                cout<<a[j]<<endl;
            break;
        }
        pos[sum[i]%n]=i;
    }
    return 0;
}
