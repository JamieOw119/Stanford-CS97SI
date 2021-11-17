#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iomanip>
using namespace std;

int nodenum, sum;
struct Trie_node
{
    bool isstr;
    int cnt;
    char name[40];
    Trie_node *branch[95];
}node[3000001];

class Trie
{
public:
    Trie_node root;
    Trie() { root=node[0];}
    void insert(char word[])
    {
        int i = 0;
        Trie_node *location = &root;
        while(word[i])
        {
            int t = word[i] - ' ';
            if(location->branch[t] == NULL)
            {
                location->branch[t] = &node[nodenum];
                node[nodenum].isstr = false;
                memset(node[nodenum].branch,NULL,sizeof(node[nodenum].branch));
                nodenum++;
            }
            i++;
            location=location->branch[t];
        }
        if(location->isstr==false)
        {
            location->isstr=true;
            location->cnt=1;
            strcpy(location->name,word);
        }
        else
            location->cnt++;
    }
};

void dfs(Trie_node *root)
{
    Trie_node *p=root;
    if(p->isstr)
    {
        cout<<p->name<<" "<<fixed<<setprecision(4)<<100.0*p->cnt/sum<<endl;
    }
    for(int i=0;i<95;i++)
    {
        if(p->branch[i])
            dfs(p->branch[i]);
    }
}

int main()
{
    char name[40];
    nodenum=1;
    sum=0;
    Trie t;
    while(gets(name))
    {
       t.insert(name);
        sum++;
    }
    dfs(&t.root);
}