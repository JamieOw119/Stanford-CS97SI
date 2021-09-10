#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    int cnt[26] = {0};
    int max = 0;
    for(int l=0; l<4; l++)
    {
        string str;
        getline(cin, str);
        for(string::iterator it=str.begin(); it != str.end(); it++)
        {
            int idx = (int)*it-65;
            if(idx>=0 && idx<=26){
                cnt[idx] ++;
                max = (cnt[idx] > max ? cnt[idx] : max);
            }     
        }
    }
    
    // char **res;
    // res = (char**)malloc(max*sizeof(char*));

    for(int j=0, height = max; j<max; j++, height --)
    {
        // res[j] = (char *)malloc(26*sizeof(char));
        for(int i=0; i<26; i++)
        {
            if(cnt[i] == height)
            {
                cout<<"* ";
                cnt[i] --;
            }
            else
            {
                cout<<"  ";
            }
        }
        cout<<endl;
    }
    cout<<"A B C D E F G H I J K L M N O P Q R S T U V W X Y Z"<<endl;
    
    return 0;
}
