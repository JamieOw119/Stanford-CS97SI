#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, sum, cnt=0;
    cin>>n;
    for (int i = 1; i <= n/2+1; i++){
        sum = 0;
        for (int j = i; j <= n/2+1; j++){
            sum += j;
            if (sum == n){
                cnt++;
                break;
            }
            if (sum > n)  break;
        }
    }
    cout << cnt + 1 << endl;
    return 0;
}
