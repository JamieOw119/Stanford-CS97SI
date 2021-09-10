#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

struct DNA
{
    string str;
    int cnt;
} w[100];

bool cmp(DNA table, DNA b)
{
    return table.cnt < b.cnt;
}

int count_inv(string str, int len)
{
    int cnt = 0;
    int table[4] = {0};
    for(int i=len-1; i>=0; i--)
    {
        switch (str[i])
        {
        case 'A':
            table[1]++;
            table[2]++;
            table[3]++;
            break;
        case 'C':
            table[2]++;
            table[3]++;
            cnt += table[1];
            break;
        case 'G':
            table[3]++;
            cnt += table[2];
            break;
        case 'T':
            cnt += table[3];
            break;
        default:
            break;
        }
    }
    return cnt;
}

int main(int argc, char const *argv[])
{
    int length, cases;
    cin>>length>>cases;
    for(int i=0; i<cases; i ++)
    {
        cin>>w[i].str;
        w[i].cnt = count_inv(w[i].str, length);
    }
    stable_sort(w, w+cases, cmp);
    for(int i=0; i<cases; i ++)
    {
        cout<<w[i].str<<endl;
    }
    
    return 0;
}
