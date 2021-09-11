/*
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string& trim(string &s)
{
    if(s.empty())
    {
        return s;
    }
    s.erase(0, s.find_first_not_of('0'));
    return s;
}

string add(string a, string b)
{   
    // make sure string a is longer string
    if(b.length() > a.length()){ 
        string tmp = a;
        a = b;
        b = tmp;
    }
    if(b.length()==0){
        return a;
    }

    string::iterator it_a = a.end()-1;
    string ::iterator it_b = b.end()-1;
    string res;
    int ones=0, tens=0, tmp;
    for(; it_a != a.begin()-1; it_a --)
    {   
        int num;
        if(it_b != b.begin()-1)
        {
            num = ((*it_a -'0') + (*it_b - '0'));
            it_b --;
        }
        else
        {
            num = (*it_a -'0');
        }
        tmp = num + tens;
        ones = tmp%10;
        tens = tmp/10;
        res.insert(0, 1, (char)('0'+ones));
    }

    return res;
}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    while(n--)
    {
        string a, b;

        cin>>a>>b;

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        trim(a);
        trim(b);

        string add_res = add(a, b);
        reverse(add_res.begin(), add_res.end());
        cout<<trim(add_res)<<endl;
    }

    return 0;
}
*/

// This example can pass in POJ
// However can not pass in WSL(gcc/g++ 9.3.0)
#include <cstdio>
#include <cstring>
char str[100];
int main() {
    int n, a, b;
    scanf("%d%*c", &n);
    while(n--) {
        gets(str);
        sscanf(strrev(str), "%d%d", &a, &b);
        sprintf(str, "%d", a + b);
        sscanf(strrev(str), "%d", &a);
        printf("%d\n", a);
    }
    return 0;
}


