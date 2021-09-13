/*#include <iostream>
#include <cstring>
#include <queue>
#include <deque>
#include <cmath>
using namespace std;

#define SIZE 10

typedef struct map_container{
    char map[SIZE][SIZE];
}map_container;

int main(int argc, char const *argv[])
{
    int m;
    deque<map_container> maps;
    cin>>m;

    for(int j=1; j<=m; j++)
    {   
        cout<<"Scenario #"<<j<<endl;
        
        int n;
        cin>>n;

        if(n == 0)
        {
            cout<<'0'<<endl;
            continue;
        }

        int x_center = n+1, y_center = n+1;
        for(int k=1; k<=n+1; k++)
        {
            int v_center = n+1-k;
            char map[SIZE][SIZE] = {'\0'};
            for(int x=1; x<=2*n+1; x++)
            {
                for(int y=1; y<=2*n+1; y++)
                {
                    int value = v_center + abs(x-x_center) + abs(y-y_center);
                    if(value<k)
                    {
                        map[x][y] = (char)('0' + value);
                    }
                    else 
                    {
                        map[x][y] = '.';
                    }
                }   
            }
            map_container mc;
            memcpy(mc.map, map, sizeof(char)*SIZE*SIZE);
            maps.push_front(mc);
            if(k != n+1)
                maps.push_back(mc);
        }

        for(int k=1; k<=2*n+1; k++)
        {
            cout<<"scene #"<<k<<endl;
            
            map_container mc = maps.front();
            maps.pop_front();
            char map[SIZE][SIZE];
            memcpy(map, mc.map, sizeof(char)*SIZE*SIZE);
            
            for(int i=1; i<=2*n+1; i++)
            {
                for(int j=1; j<=2*n+1; j++)
                {
                    cout<<map[i][j];
                }
                cout<<endl;
            }
        }
        cout<<endl;
    }
      
    return 0;
}*/

#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

void gprint(int u)
{
    for(int k = 1; k <= 2 * u + 1; k++) {
        printf("slice #%d:\n", k);
        for(int i = 1; i <= 2 * u + 1; i++) {
            for(int j = 1; j <= 2 * u + 1; j++) {
                int u2 = abs(u +1 - i) + abs(u + 1 - j) + abs(u +1 - k);     // 计算走到相应位置需要的油量
                if(u2 > u) printf(".");
                else printf("%d", u2);
            }
            printf("\n");
        }
    }
}

int main()
{
    int t, u;
    scanf("%d", &t);
    for(int k = 1; k <= t; k++) {
        scanf("%d", &u);
        if(u >= 0 && u <= 9) {
            printf("Scenario #%d:\n", k);
            gprint(u);
        }
        printf("\n");
    }

    return 0;
}

