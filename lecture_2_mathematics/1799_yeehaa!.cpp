#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

#define PI acos(-1.)
int T,k,c=1;
double r;
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%lf %d",&r,&k);
        printf("Scenario #%d:\n",c++);
        printf("%.3lf\n\n",r*sin(PI/k)/(1+sin(PI/k)));
    }
    return 0;
}
