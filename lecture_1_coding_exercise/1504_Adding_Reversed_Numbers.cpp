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

    string::iterator it_a = a.end();
    string ::iterator it_b = b.end();
    string res;
    int ones=0, tens=0;
    for(; it_b != b.begin(); it_b --)
    {   
        int num = ((int)*it_a + (int)*it_b);
        ones = num%10 + tens;
        tens = num/10;
        cout<<ones<<' ';
        res.push_back((char)ones);
        it_a --;
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

        cout<<a<<' '<<b<<endl;
        cout<<add(a, b)<<endl;
    }

    return 0;
}
