#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
    cout.setf(ios::fixed);
    cout.precision(2);

    double x1, y1, x2, y2, x3 ,y3, a, b, c, p, s, r, len;
    while(cin>>x1>>y1>>x2>>y2>>x3>>y3)
    {
        a = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        b = sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
        c = sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));

        p = (a+b+c)/2;
        s = sqrt(p*(p-a)*(p-b)*(p-c));
        r = (a*b*c)/(4*s);
        len = 2*M_PI*r;
        
        cout<<len<<endl;
    }
    return 0;
}
